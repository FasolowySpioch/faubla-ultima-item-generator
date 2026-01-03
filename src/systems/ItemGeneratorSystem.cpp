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
    // strategies[ItemType::ACCESSORY] = std::make_unique<AccessoryGenerator>("");

    quality_strategy = std::make_unique<QualityGenerator>("../../data/basic/Basic_Qualities.json");
}

std::unique_ptr<Item> ItemGeneratorSystem::generateItem(const Player &player, ItemType type)
{
    if (type == ItemType::RANDOM)
    {
        // dev note: when accessory generation technique clears up, change the range to [0, 2]
        int random_idx = std::uniform_int_distribution<>(0, 1)(mt);
        type = static_cast<ItemType>(random_idx);
    }

    // if there was no strategy for type, return nullptr
    if (strategies.find(type) == strategies.end())
        return nullptr;

    std::unique_ptr<Item> item = strategies[type]->generate(player);

    // generate quality and apply to item
    rerollQuality(type, item.get());

    return item;
}

void ItemGeneratorSystem::rerollQuality(const ItemType type, Item *item) const
{
    if (!item) throw std::invalid_argument("Invalid item type");

    quality_strategy->applyRandomQualityTo(type, item);
}
