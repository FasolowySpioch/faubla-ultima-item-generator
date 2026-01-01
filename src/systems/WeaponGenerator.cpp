#include "WeaponGenerator.h"
#include "../models/Weapon.h"
#include "../io/JsonReader.h"


WeaponGenerator::WeaponGenerator(const std::string &file_path)
{
    // rng init
    std::random_device seed;
    _mt = std::mt19937(seed());

    // loading the file
    JsonReader reader;
    const std::vector<std::unique_ptr<Item>> loadedItems = reader.loadItems(QString::fromStdString(file_path));

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

void WeaponGenerator::filterByPlayerPreference(const Player &player, std::vector<const Weapon*> &candidates) const
{
    if (player.getPreferredWeaponType() == WeaponType::NONE)
        return;

    std::vector<const Weapon*> filtered;
    for (auto &w : _cache_weapons)
    {
        if (!isWeaponUsable(player, *w))
            continue;

        if (w->getType() == player.getPreferredWeaponType())
            filtered.push_back(w.get());
    }

    if (!filtered.empty())
        candidates = std::move(filtered);
}

void WeaponGenerator::filterByPlayerAttributesHard(const Player &player, std::vector<const Weapon*> &candidates) const
{
    // if (candidates.size() >= 2)
    if (!candidates.empty())
        return;

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

    if (!filtered.empty())
        candidates = std::move(filtered);
}

void WeaponGenerator::filterByPlayerAttributesSoft(const Player &player, std::vector<const Weapon*> &candidates) const
{
    if (!candidates.empty())
        return;

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

    if (!filtered.empty())
        candidates = std::move(filtered);
}

std::unique_ptr<Item> WeaponGenerator::generate(const Player &player)
{
    std::vector<const Weapon*> weapons_final;

    filterByPlayerPreference(player, weapons_final);
    filterByPlayerAttributesHard(player, weapons_final);
    filterByPlayerAttributesSoft(player, weapons_final);

    // if still empty, take everything that player can use
    if (weapons_final.empty())
    {
        for (auto &w : _cache_weapons)
        {
            if ((!player.getCanRange() && w->getIsRange()) || (!player.getCanMartialWeapon() && w->getIsMartial()))
                continue;

            weapons_final.push_back(w.get());
        }
    }

    // if STILL empty, then either:
    // - there's no weapons matching the requirements (like, in the file)
    // - OR player is meant to have absolutely nothing
    if (weapons_final.empty())
        return nullptr;

    // choosing random weapon to return
    std::uniform_int_distribution<> dist(0, weapons_final.size() - 1);

    // deep copy
    return std::make_unique<Weapon>(*weapons_final[dist(_mt)]);
}
