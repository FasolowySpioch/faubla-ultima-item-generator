#ifndef FULTIMA_GEN_GENERATOR_H
#define FULTIMA_GEN_GENERATOR_H

#include "Item.h"
#include "Player.h"
#include <vector>

class Generator
{
    std::vector<Item*> _items;
    std::vector<Player*> _players;

public:
    Generator() = default;
    ~Generator();

    void createPlayerProfile(std::string_view ch_name, std::string_view author_name, int level, Attribute p_die1, Attribute p_die2,
        WeaponType pref_weapon, bool canMartialWeapon, bool canMartialArmor,
        bool canRange, bool canShield);
    void deletePlayerProfile(Player* p);
    void deleteAllPlayerProfiles();
    Player* getPlayer(std::string_view name);   // either author's or character's name
};


#endif //FULTIMA_GEN_GENERATOR_H
