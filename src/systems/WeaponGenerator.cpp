#include "WeaponGenerator.h"
#include "../io/JsonReader.h"
#include <QRandomGenerator>


WeaponGenerator::WeaponGenerator(const QString &file_path)
{
    // loading the file
    const std::vector<std::unique_ptr<Item>> loadedItems = JsonReader::loadItems(file_path, ItemType::WEAPON);

    // caching the file and casting to derived class
    _cache_weapons.reserve(loadedItems.size());
    for (auto& item : loadedItems)
    {
        if (auto* weapon_ptr = dynamic_cast<Weapon*>(item.get()))
            _cache_weapons.push_back(std::make_unique<Weapon>(*weapon_ptr));
    }

    if (_cache_weapons.empty())
        qWarning() << "WeaponGenerator: No weapons loaded from" << file_path;
}


bool WeaponGenerator::isWeaponUsable(const Player &player, const Weapon &weapon)
{
    if (!player.getCanRange() && weapon.getIsRange())
        return false;
    if (!player.getCanMartialWeapon() && weapon.getIsMartial())
        return false;

    return true;
}

std::vector<const Weapon*> WeaponGenerator::filterByPlayerPreference(const Player &player) const
{
    std::vector<const Weapon*> filtered;

    if (player.getPreferredWeaponType() == WeaponType::NONE)
        return filtered;

    for (auto &w : _cache_weapons)
    {
        if (!isWeaponUsable(player, *w))
            continue;

        if (w->getWeaponType() == player.getPreferredWeaponType())
            filtered.push_back(w.get());
    }

    return filtered;
}

std::vector<const Weapon*> WeaponGenerator::filterByPlayerAttributesHard(const Player &player) const
{
    std::vector<const Weapon*> filtered;

    for (auto &w : _cache_weapons)
    {
        if (!isWeaponUsable(player, *w))
            continue;

        // precisely two attributes matching
        bool match1 = w->getAccuracy1() == player.getPrimaryDie1() && w->getAccuracy2() == player.getPrimaryDie2();
        bool match2 = w->getAccuracy1() == player.getPrimaryDie2() && w->getAccuracy2() == player.getPrimaryDie1();

        if (match1 || match2)
            filtered.push_back(w.get());
    }

    return filtered;
}

std::vector<const Weapon*> WeaponGenerator::filterByPlayerAttributesSoft(const Player &player) const
{
    std::vector<const Weapon*> filtered;

    for (auto &w : _cache_weapons)
    {
        if (!isWeaponUsable(player, *w))
            continue;

        // at least one matching attribute
        if (w->getAccuracy1() == player.getPrimaryDie1() || w->getAccuracy1() == player.getPrimaryDie2() ||
            w->getAccuracy2() == player.getPrimaryDie1() || w->getAccuracy2() == player.getPrimaryDie2())
            filtered.push_back(w.get());
    }

    return filtered;
}

std::unique_ptr<Item> WeaponGenerator::generate(const Player &player)
{
    std::vector<const Weapon *> candidates = filterByPlayerPreference(player);

    if (candidates.empty())
        candidates = filterByPlayerAttributesHard(player);

    if (candidates.empty())
        candidates = filterByPlayerAttributesSoft(player);

    // if still empty, load in everything that player can use
    if (candidates.empty())
    {
        for (auto &w : _cache_weapons)
        {
            if (isWeaponUsable(player, *w))
                candidates.push_back(w.get());
        }
    }

    // if STILL empty, then either:
    // - there's no weapons matching the requirements (like, in the file)
    // - OR player is meant to have absolutely nothing
    if (candidates.empty())
    {
        qWarning() << "WeaponGenerator: Could not generate any weapon for player" << player.getCharacterName();
        return nullptr;
    }

    // choosing random weapon to return
    const int idx = QRandomGenerator::global()->bounded(static_cast<int>(candidates.size()));

    return std::make_unique<Weapon>(*candidates[idx]);
}
