#include "Player.h"
int Player::getLevel() { return _level; }
Atributes Player::getPrimaryDie1() { return _primary_die1; }
Atributes Player::getPrimaryDie2() { return _primary_die2; }
WeaponType Player::getPrefferedWeaponType() { return _preffered_weapon_type; }
bool Player::getCanMartialWeapon() { return _canMartialWeapon; }
bool Player::getCanMartialArmor() { return _canMartialArmor; }
bool Player::getCanRange() { return _canRange; }
bool Player::getCanShield() { return _canShield; }
std::string Player::getName() { return _name; }
void Player::setLevel(int level) { _level = level; }
void Player::setPrimaryDie1(Atributes pd1) { _primary_die1 = pd1; }
void Player::setPrimaryDie2(Atributes pd2) { _primary_die2 = pd2; }
void Player::setPrefferedWeaponType(WeaponType pwt) { _preffered_weapon_type = pwt; }
void Player::setCanMartialWeapon(bool cmw) { _canMartialWeapon = cmw; }
void Player::setCanMartialArmor(bool cma) { _canMartialArmor = cma; }
void Player::setCanRange(bool cr) { _canRange = cr; }
void Player::setCanShield(bool cs) { _canShield = cs; }
void Player::setName(std::string name) { _name = name; }
