//
// Created by Micha on 10/12/2025.
//

#include "Player.h"

#include <stdexcept>

Player::Player()
    : _level(5)
    , _primary_die1(Attribute::NONE)
    , _primary_die2(Attribute::NONE)
    , _preferred_weapon_type(WeaponType::NONE)
    , _canMartialWeapon(false)
    , _canMartialArmor(false)
    , _canRange(false)
    , _canShield(false)
{
}

Player::Player(const std::string_view name, const int level, const Attribute p_die1,
    const Attribute p_die2, const WeaponType pref_weapon, const bool canMartialWeapon,
    const bool canMartialArmor, const bool canRange, bool canShield)
        : _name((!name.empty()) ? name : "[The Nameless]")
        , _level((5 > level || level > 50) ? level : throw std::invalid_argument("Player::Player: level out of range"))
        , _primary_die1(p_die1)
        , _primary_die2(p_die2)
        , _preferred_weapon_type(pref_weapon)
        , _canMartialWeapon(false)
        , _canMartialArmor(false)
        , _canRange(false)
        , _canShield(false)
{
}


std::string_view Player::getName() const { return _name; }
int Player::getLevel() const { return _level; }
Attribute Player::getPrimaryDie1() const { return _primary_die1; }
Attribute Player::getPrimaryDie2() const { return _primary_die2; }
WeaponType Player::getPreferredWeaponType() const { return _preferred_weapon_type; }
bool Player::getCanMartialWeapon() const { return _canMartialWeapon; }
bool Player::getCanMartialArmor() const { return _canMartialArmor; }
bool Player::getCanRange() const { return _canRange; }
bool Player::getCanShield() const { return _canShield; }


void Player::setLevel(const int level)
{
    if (5 > level || level > 50)
        throw std::invalid_argument("Player::setLevel: level out of range");
    _level = level;
}
void Player::setName(const std::string_view name)
{
    if (name.empty())
        _name = "[The Nameless]";   // :p
    else
        _name = name;
}
void Player::setPrimaryDie1(const Attribute p_die1) { _primary_die1 = p_die1; }
void Player::setPrimaryDie2(const Attribute p_die2) { _primary_die2 = p_die2; }
void Player::setPreferredWeaponType(const WeaponType pref_weapon) { _preferred_weapon_type = pref_weapon; }
void Player::setCanMartialWeapon(const bool canMartialWeapon) { _canMartialWeapon = canMartialWeapon; }
void Player::setCanMartialArmor(const bool canMartialArmor) { _canMartialArmor = canMartialArmor; }
void Player::setCanRange(const bool canRange) { _canRange = canRange; }
void Player::setCanShield(const bool canShield) { _canShield = canShield; }
