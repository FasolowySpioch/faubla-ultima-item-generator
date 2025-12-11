#include "Generator.h"
#include <algorithm>


void Generator::createPlayerProfile(const std::string_view ch_name, const std::string_view author_name, const int level,
                                    const Attribute p_die1, const Attribute p_die2, const WeaponType pref_weapon, const bool canMartialWeapon,
                                    const bool canMartialArmor, const bool canRange, const bool canShield)
{
    _players.push_back(
        new Player(
            ch_name, author_name, level, p_die1, p_die2, pref_weapon, canMartialWeapon, canMartialArmor,
            canRange, canShield
        ));
}

void Generator::deletePlayerProfile(Player* p)
{
    auto it = std::find(_players.begin(), _players.end(), p);
    if (it != _players.end())
    {
        delete _players.at(it - _players.begin());
        _players.erase(it);
    }
}

void Generator::deleteAllPlayerProfiles()
{
    for (auto p : _players)
        delete p;

    _players.clear();
}

// Player* Generator::getPlayer(std::string_view name)
// {
//
// }