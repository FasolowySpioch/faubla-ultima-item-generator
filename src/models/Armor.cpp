#include "Armor.h"

#include <stdexcept>


Armor::Armor()
    : _initiative(0)
    , _isMartial(false)
    , _magic_defense(0)
    , _defense(0)
{
}

Armor::Armor(const std::string_view name, const std::string_view desc, const int price,
             const int initiative, const bool isMartial, const int magic_defense, const int defense)
    : Item(name, desc, price)
    , _initiative((initiative <= 0) ? initiative : 0)   //throw std::invalid_argument("Armor::Armor: Invalid value for _initiative");
    , _isMartial(isMartial)
    , _magic_defense(magic_defense)
    , _defense(defense)
{
}


int Armor::getInitiative() const { return _initiative; }
bool Armor::getIsMartial() const { return _isMartial; }
int Armor::getMagDef() const { return _magic_defense; }
int Armor::getDef() const { return _defense; }
Attribute Armor::getMagDefAtr() { return Attribute::INS; }
Attribute Armor::getDefAtr() const
{
    if (_defense <= 3)
        return Attribute::DEX;

    return Attribute::NONE;
}

void Armor::setInitiative(const int in)
{
    if (0 < in)
        _initiative = 0;
        //throw std::invalid_argument("Armor::setInitiative: Invalid value for _initiative");
    else
    _initiative = in;
}
void Armor::setIsMartial(const bool m) { _isMartial = m; }
void Armor::setMagDef(const int md) { _magic_defense = md; }    // input check?
void Armor::setDef(const int d) { _defense = d; }               // input check?
