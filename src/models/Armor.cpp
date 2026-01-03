#include "Armor.h"
#include <stdexcept>


Armor::Armor()
    : _initiative(0)
    , _isMartial(false)
    , _magic_defense(0)
    , _defense(0)
    , _isShield(false)
{
}

Armor::Armor(const std::string_view name, const std::string_view desc, const int price,
             const int initiative, const bool isMartial, const int magic_defense, const int defense, const bool isShield)
    : Item(name, desc, price, 0)
    , _initiative((initiative <= 0) ? initiative : 0)   //throw std::invalid_argument("Armor::Armor: Invalid value for _initiative");
    , _isMartial(isMartial)
    , _magic_defense(magic_defense)
    , _defense(defense)
    , _isShield(isShield)
{
}


int Armor::getInitiative() const { return _initiative; }
bool Armor::getIsMartial() const { return _isMartial; }
bool Armor::getIsShield() const { return _isShield; }
int Armor::getMagDefBonus() const { return _magic_defense; }
int Armor::getDefBonus() const { return _defense <= 3 ? _defense - 2 : _defense; }
Attribute Armor::getMagDefAtr() { return Attribute::INS; }
Attribute Armor::getDefAtr() const { return _defense <= 3 ? Attribute::DEX : Attribute::NONE; }       // def + bonus is always DEX(2)+0/1 or integer >9 -- so if it's <=3, then Attr always DEX

void Armor::setInitiative(const int in)
{
    if (0 < in)
        _initiative = 0;
        //throw std::invalid_argument("Armor::setInitiative: Invalid value for _initiative");
    else
        _initiative = in;
}
void Armor::setIsMartial(const bool m) { _isMartial = m; }
void Armor::setIsShield(const bool s) { _isShield = s; }
void Armor::setMagDef(const int md) { _magic_defense = md; }    // input check?
void Armor::setDef(const int d) { _defense = d; }               // input check?
