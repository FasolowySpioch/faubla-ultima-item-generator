#include "ArmorGenerator.h"
#include "../io/JsonReader.h"
#include <QRandomGenerator>

ArmorGenerator::ArmorGenerator(const QString &file_path)
{
    // loading the file
    const std::vector<std::unique_ptr<Item>> loadedItems = JsonReader::loadItems(file_path, ItemType::ARMOR);

    // caching the file and casting to derived class
    _cache_armors.reserve(loadedItems.size());
    for (auto& item : loadedItems)
    {
        if (auto* armor_ptr = dynamic_cast<Armor*>(item.get()))
            _cache_armors.push_back(std::make_unique<Armor>(*armor_ptr));
    }

    if (_cache_armors.empty())
        qWarning() << "ArmorGenerator: No armors loaded from" << file_path;
}


bool ArmorGenerator::isArmorUsable(const Player &player, const Armor &armor)
{
    if (!player.getCanMartialWeapon() && armor.getIsMartial())
        return false;
    if (!player.getCanShield() && armor.getIsShield())
        return false;

    return true;
}

std::unique_ptr<Item> ArmorGenerator::generate(const Player &player)
{
    std::vector<Armor*> candidates;

    // pick up armors that player can use
    for (auto &a : _cache_armors)
    {
        if (isArmorUsable(player, *a))
            candidates.push_back(a.get());
    }

    // if still empty, then either:
    // - there's no armors matching the requirements (like, in the file)
    // - OR player is meant to have absolutely nothing
    if (candidates.empty())
    {
        qWarning() << "ArmorGenerator: Could not generate any armor for player" << player.getCharacterName();
        return nullptr;
    }

    // choosing random armor to return
    const int idx = QRandomGenerator::global()->bounded(static_cast<int>(candidates.size()));

    return std::make_unique<Armor>(*candidates[idx]);
}