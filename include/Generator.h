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
    virtual ~Generator();

    void createPlayer(std::string_view ch_name, std::string_view author_name, int level, Attribute p_die1, Attribute p_die2,
        WeaponType pref_weapon, bool canMartialWeapon, bool canMartialArmor,
        bool canRange, bool canShield);
    void deletePlayer(Player* p);
    void deleteAllPlayer();

    virtual Item* generateItem(Player* p) = 0;
};


#endif //FULTIMA_GEN_GENERATOR_H
