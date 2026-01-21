#include "ItemGeneratorSystem.h"
#include "AccessoryGenerator.h"
#include "ArmorGenerator.h"
#include "QualityGenerator.h"
#include "WeaponGenerator.h"
#include <cassert>
#include <QRandomGenerator>


QString getPath(const QString &relative_path)
{
    return QStringLiteral(":/data/") + relative_path;
}


ItemGeneratorSystem::ItemGeneratorSystem()
{
    // generators init
    strategies[ItemType::WEAPON] = std::make_unique<WeaponGenerator>(getPath("basic/Basic_Weapons.json"));
    strategies[ItemType::ARMOR] = std::make_unique<ArmorGenerator>(getPath("basic/Basic_Armor_Shield.json"));
    strategies[ItemType::ACCESSORY] = std::make_unique<AccessoryGenerator>();

    quality_gen[ItemType::WEAPON] = std::make_unique<QualityGenerator>(getPath("basic/Basic_Weapon_Qualities.json"));
    quality_gen[ItemType::ARMOR] = std::make_unique<QualityGenerator>(getPath("basic/Basic_Armor_Qualities.json"));
    quality_gen[ItemType::ACCESSORY] = std::make_unique<QualityGenerator>(getPath("basic/Basic_Accessory_Qualities.json"));
}

ItemType ItemGeneratorSystem::getRandomItemType()
{
    int val = QRandomGenerator::global()->bounded(3);    // 0, 1, 2

    return static_cast<ItemType>(val);
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


std::unique_ptr<Item> ItemGeneratorSystem::generateItem(ItemType type, const Player &player)
{
    constexpr int MAX_TRIES = 100;
    constexpr int MAX_Q_REROLLS = 20;
    int i = 0;
    const bool isRandomRequest = type == ItemType::RANDOM;

    while (i < MAX_TRIES)
    {
        ItemType currentType = isRandomRequest ? getRandomItemType() : type;

        // if there was no strategy for type, throw exception
        if (strategies.find(currentType) == strategies.end())
        {
            qWarning() << "No strategy for type: " << static_cast<int>(currentType);
            break;
        }

        std::unique_ptr<Item> item = strategies[currentType]->generate(player);

        if (!item)
        {
            i++;
            continue;
        }

        if (i < MAX_Q_REROLLS)
        {
            // generate quality and apply to item
            assignQuality(type, item.get());
        }

        if (isItemPriceValid(*item, player))
            return item;

        i++;
    }

    qWarning() << "Failed to generate valid item for player lvl" << player.getLevel() << "after" << i << "attempts.";
    return nullptr;
}

void ItemGeneratorSystem::assignQuality(const ItemType type, Item *item)
{
    if (type == ItemType::RANDOM) return;
    if (!item) return;

    auto it = quality_gen.find(type);
    if (it != quality_gen.end()) {
        it->second->applyRandomQualityTo(item);
    }
}
