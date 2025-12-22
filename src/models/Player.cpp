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

Player::Player(const std::string_view character_name, const std::string_view author_name, const int level, const Attribute p_die1,
    const Attribute p_die2, const WeaponType pref_weapon, const bool canMartialWeapon,
    const bool canMartialArmor, const bool canRange, bool canShield)
        : _character_name((!character_name.empty()) ? character_name : "[The Nameless]")
        , _author_name((!author_name.empty()) ? author_name : "[The Creator]")
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


const std::string& Player::getCharacterName() const { return _character_name; }
const std::string& Player::getAuthorName() const { return _author_name; }
int Player::getLevel() const { return _level; }
Attribute Player::getPrimaryDie1() const { return _primary_die1; }
Attribute Player::getPrimaryDie2() const { return _primary_die2; }
WeaponType Player::getPreferredWeaponType() const { return _preferred_weapon_type; }
bool Player::getCanMartialWeapon() const { return _canMartialWeapon; }
bool Player::getCanMartialArmor() const { return _canMartialArmor; }
bool Player::getCanRange() const { return _canRange; }
bool Player::getCanShield() const { return _canShield; }

void Player::setCharacterName(const std::string_view ch_name)
{
    if (ch_name.empty())
        _character_name = "[The Nameless]";   // :p
    else
        _character_name = ch_name;
}
void Player::setAuthorName(const std::string_view author_name)
{
    if (author_name.empty())
        _author_name = "[The Creator]";   // :p
    else
        _author_name = author_name;
}
void Player::setLevel(const int level)
{
    if (5 > level || level > 50)
        throw std::invalid_argument("Player::setLevel: level out of range");
    _level = level;
}
void Player::setPrimaryDie1(const Attribute p_die1) { _primary_die1 = p_die1; }
void Player::setPrimaryDie2(const Attribute p_die2) { _primary_die2 = p_die2; }
void Player::setPreferredWeaponType(const WeaponType pref_weapon) { _preferred_weapon_type = pref_weapon; }
void Player::setCanMartialWeapon(const bool canMartialWeapon) { _canMartialWeapon = canMartialWeapon; }
void Player::setCanMartialArmor(const bool canMartialArmor) { _canMartialArmor = canMartialArmor; }
void Player::setCanRange(const bool canRange) { _canRange = canRange; }
void Player::setCanShield(const bool canShield) { _canShield = canShield; }
