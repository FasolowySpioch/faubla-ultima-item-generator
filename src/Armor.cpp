#include "Armor.h"


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
    , _initiative(initiative)
    , _isMartial(isMartial)
    , _magic_defense(magic_defense)
    , _defense(defense)
{
}


int Armor::getInitiative() const { return _initiative; }
bool Armor::getIsMartial() const { return _isMartial; }
int Armor::getMagDef() const { return _magic_defense; }
int Armor::getDef() const { return _defense; }

void Armor::setInitiative(const int i) { _initiative = i; }
void Armor::setIsMartial(const bool m) { _isMartial = m; }
void Armor::setMagDef(const int md) { _magic_defense = md; }
void Armor::setDef(const int d) { _defense = d; }
