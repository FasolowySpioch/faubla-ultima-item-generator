#include "Player.h"
int Player::getLevel() { return _level; }
Atributes Player::getPrimaryDie1() { return _primary_die1; }
Atributes Player::getPrimaryDie2() { return _primary_die2; }
std::string Player::getPrefferedWeaponType() { return _preffered_weapon_type; }
void Player::setLevel(int l) { _level = l; }
void Player::setPrimaryDie1(Atributes pd1) { _primary_die1 = pd1; }
void Player::setPrimaryDie2(Atributes pd2) { _primary_die2 = pd2; }
void Player::setPrefferedWeaponType(std::string pwt) { _preffered_weapon_type = pwt; }
