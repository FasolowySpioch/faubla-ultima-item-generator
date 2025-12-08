#include "Weapon.h"

WeaponType Weapon::getType() { return _weapon_type; }
std::string Weapon::getDmgDesc() { return _dmg_desc; }
Atributes Weapon::getAccuracy1() { return _accuracy1; }
Atributes Weapon::getAccuracy2() { return _accuracy2; }
int Weapon::getAccuracyBonus() { return _accuracy_bonus; }
DMGType Weapon::getDmgType() { return _dmg_type; }
bool Weapon::getIsSingleHanded() { return _isSingleHanded; }
bool Weapon::getIsRange() { return _isRange; }
bool Weapon::getIsMartial() { return _isMartial; }
void Weapon::setType(WeaponType t) { _weapon_type = t; }
void Weapon::setDmgDesc(std::string dd) { _dmg_desc = dd; }
void Weapon::setAccuracy1(Atributes a1) { _accuracy1 = a1; }
void Weapon::setAccuracy2(Atributes a2) { _accuracy2 = a2; }
void Weapon::setAccuracyBonus(int ab) { _accuracy_bonus = ab; }
void Weapon::setDmgType(DMGType dt) { _dmg_type = dt; }
void Weapon::setIsSingleHanded(bool ish) { _isSingleHanded = ish; }
void Weapon::setIsRange(bool ir) { _isRange = ir; }
void Weapon::setIsMartial(bool im) { _isMartial = im; }
