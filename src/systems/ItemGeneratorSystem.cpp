#include "ItemGeneratorSystem.h"

#include <stdexcept>

#include "AccessoryGenerator.h"
#include "ArmorGenerator.h"
#include "QualityGenerator.h"
#include "WeaponGenerator.h"


ItemGeneratorSystem::ItemGeneratorSystem()
{
    // rng init
    std::random_device seed;
    mt = std::mt19937(seed());

    // generators init
    strategies[ItemType::WEAPON] = std::make_unique<WeaponGenerator>("../../data/basic/Basic_Weapons.json");
    strategies[ItemType::ARMOR] = std::make_unique<ArmorGenerator>("../../data/basic/Basic_Armor_Shield.json");
    strategies[ItemType::ACCESSORY] = std::make_unique<AccessoryGenerator>();

    quality_strategy = std::make_unique<QualityGenerator>("../../data/basic/Basic_Weapon_Qualities.json");
}

ItemType ItemGeneratorSystem::getRandomItemType()
{
    int random_idx = std::uniform_int_distribution<>(0, 2)(mt);

    return static_cast<ItemType>(random_idx);
}

bool ItemGeneratorSystem::isItemPriceValid(const Item &item, const Player &player)
{
    if (player.getLevel() >= 40)
        return true;

    if (player.getLevel() >= 30 && item.getPrice() <= 2000)
        return true;

    if (player.getLevel() >= 20 && item.getPrice() <= 1500)
        return true;

    if (player.getLevel() >= 10 && item.getPrice() <= 1000)
        return true;

    if (player.getLevel() >= 5 && item.getPrice() <= 500)
        return true;

    return false;
}


std::unique_ptr<Item> ItemGeneratorSystem::generateItem(const Player &player, ItemType type)
{
    constexpr int no_of_tries = 20;
    int i = 0;
    const bool wasRandom = type == ItemType::RANDOM;

    while (true)
    {
        if (wasRandom)
        {
            type = getRandomItemType();
        }

        // if there was no strategy for type, throw exception
        if (strategies.find(type) == strategies.end())
            throw std::invalid_argument("ItemGeneratorSystem::generateItem(): Item type not valid or there's no generator strategy for it.");

        std::unique_ptr<Item> item = strategies[type]->generate(player);

        if (i < no_of_tries)
        {
            // generate quality and apply to item
            rerollQuality(type, item.get());
        }

        if (isItemPriceValid(*item, player))
            return item;

        i++;
    }
}

void ItemGeneratorSystem::rerollQuality(const ItemType type, Item *item) const
{
    if (!item) throw std::invalid_argument("ItemGeneratorSystem::rerollQuality(): Invalid pointer to item");

    quality_strategy->applyRandomQualityTo(type, item);
}
