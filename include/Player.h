//
// Created by Micha on 10/12/2025.
//

#ifndef FULTIMA_GEN_PLAYER_H
#define FULTIMA_GEN_PLAYER_H

#include "Weapon.h"
#include "AttributeEnum.h"
#include <string>
#include <string_view>


class Player
{
    std::string _name;
    int _level;
    Attribute _primary_die1;
    Attribute _primary_die2;
    WeaponType _preferred_weapon_type;
    bool _canMartialWeapon;
    bool _canMartialArmor;
    bool _canRange;
    bool _canShield;

public:
    Player();
    Player(std::string_view name, int level, Attribute p_die1, Attribute p_die2,
        WeaponType pref_weapon, bool canMartialWeapon, bool canMartialArmor,
        bool canRange, bool canShield);

    std::string_view getName() const;
    int getLevel() const;
    Attribute getPrimaryDie1() const;
    Attribute getPrimaryDie2() const;
    WeaponType getPreferredWeaponType() const;
    bool getCanMartialWeapon() const;
    bool getCanMartialArmor() const;
    bool getCanRange() const;
    bool getCanShield() const;

    void setLevel(int level);
    void setName(std::string_view name);
    void setPrimaryDie1(Attribute p_die1);
    void setPrimaryDie2(Attribute p_die2);
    void setPreferredWeaponType(WeaponType pref_weapon);
    void setCanMartialWeapon(bool canMartialWeapon);
    void setCanMartialArmor(bool canMartialArmor);
    void setCanRange(bool canRange);
    void setCanShield(bool canShield);
};


#endif //FULTIMA_GEN_PLAYER_H