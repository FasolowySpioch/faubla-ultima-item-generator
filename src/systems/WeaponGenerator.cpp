#include "WeaponGenerator.h"
#include "../io/JsonReader.h"


WeaponGenerator::WeaponGenerator(const std::string &file_path)
{
    // rng init
    std::random_device seed;
    _mt = std::mt19937(seed());

    // loading the file
    JsonReader reader;
    const std::vector<std::unique_ptr<Item>> loadedItems = reader.loadItems(QString::fromStdString(file_path), ItemType::WEAPON);

    // caching the file and casting to derived class
    _cache_weapons.reserve(loadedItems.size());
    for (auto& item : loadedItems)
    {
        if (auto* weapon_ptr = dynamic_cast<Weapon*>(item.get()))
            _cache_weapons.push_back(std::make_unique<Weapon>(*weapon_ptr));
    }
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

        if (w->getType() == player.getPreferredWeaponType())
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
    std::vector<const Weapon *> weapons_final = filterByPlayerPreference(player);

    // 'chain of responsibility' design pattern?
    if (weapons_final.empty())
        weapons_final = filterByPlayerAttributesHard(player);

    if (weapons_final.empty())
        weapons_final = filterByPlayerAttributesSoft(player);

    // if still empty, take everything that player can use
    if (weapons_final.empty())
    {
        for (auto &w : _cache_weapons)
        {
            if (!isWeaponUsable(player, *w))
                continue;

            weapons_final.push_back(w.get());
        }
    }

    // if STILL empty, then either:
    // - there's no weapons matching the requirements (like, in the file)
    // - OR player is meant to have absolutely nothing
    if (weapons_final.empty())
        return nullptr;
        // throw exception ??

    // choosing random weapon to return
    std::uniform_int_distribution<> dist(0, weapons_final.size() - 1);

    return std::make_unique<Weapon>(*weapons_final[dist(_mt)]);
}
