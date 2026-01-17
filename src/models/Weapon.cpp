#include "Weapon.h"


Weapon::Weapon()
    : _weapon_type(WeaponType::NONE)
    , _dmg_desc(0)
    , _dmg_type(DMGType::NONE)
    , _accuracy1(Attribute::NONE)
    , _accuracy2(Attribute::NONE)
    , _accuracy_bonus(0)
    , _isSingleHanded(false)
    , _isRange(false)
    , _isMartial(false)
{
}

Weapon::Weapon(const std::string_view name, const std::string_view desc, const int price, const WeaponType weapon_type,
               const int dmg_desc, const DMGType dmg_type, const Attribute accuracy1, const Attribute accuracy2,
               const int accuracy_bonus, const bool isSingleHanded, const bool isRange, const bool isMartial)
    : Item(name, desc, price, 0)
    , _weapon_type(weapon_type)
    , _dmg_desc(dmg_desc)   // check if input >=0 ??
    , _dmg_type(dmg_type)
    , _accuracy1(accuracy1)
    , _accuracy2(accuracy2)
    , _accuracy_bonus(accuracy_bonus)   // check if input >=0 ??
    , _isSingleHanded(isSingleHanded)
    , _isRange(isRange)
    , _isMartial(isMartial)
{
}

ItemType Weapon::getItemType() const { return ItemType::WEAPON; }

WeaponType Weapon::getWeaponType() const { return _weapon_type; }
int Weapon::getDmgDesc() const { return _dmg_desc; }
DMGType Weapon::getDmgType() const { return _dmg_type; }
Attribute Weapon::getAccuracy1() const { return _accuracy1; }
Attribute Weapon::getAccuracy2() const { return _accuracy2; }
int Weapon::getAccuracyBonus() const { return _accuracy_bonus; }
bool Weapon::getIsSingleHanded() const { return _isSingleHanded; }
bool Weapon::getIsRange() const { return _isRange; }
bool Weapon::getIsMartial() const { return _isMartial; }

void Weapon::setType(const WeaponType t) { _weapon_type = t; }
void Weapon::setDmgDesc(const int dd) { _dmg_desc = dd; }       // check if input >=0 ??
void Weapon::setDmgType(const DMGType dt) { _dmg_type = dt; }
void Weapon::setAccuracy1(const Attribute a1) { _accuracy1 = a1; }
void Weapon::setAccuracy2(const Attribute a2) { _accuracy2 = a2; }
void Weapon::setAccuracyBonus(const int ab) { _accuracy_bonus = ab; }   // check if input >=0 ??
void Weapon::setIsSingleHanded(const bool ish) { _isSingleHanded = ish; }
void Weapon::setIsRange(const bool ir) { _isRange = ir; }
void Weapon::setIsMartial(const bool im) { _isMartial = im; }
