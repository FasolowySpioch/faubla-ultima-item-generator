#include "Armor.h"


Armor::Armor()
    : _magic_defense(Attribute::NONE)
    , _defense(Attribute::NONE)
    , _magic_defense_bonus(0)
    , _defense_bonus(0)
    , _initiative(0)
    , _isMartial(false)
    , _isShield(false)
{
}

Armor::Armor(const std::string_view name, const std::string_view desc, const int default_price, const int price,
             const int initiative, const bool isMartial, const Attribute magic_defense, const int magic_defense_bonus, const Attribute defense, const int defense_bonus, const bool isShield)
    : Item(name, desc, default_price, price - default_price)
    , _magic_defense(magic_defense)
    , _defense(defense)
    , _magic_defense_bonus(magic_defense_bonus)
    , _defense_bonus(defense_bonus)
    , _initiative(std::min(0, initiative))
    , _isMartial(isMartial)
    , _isShield(isShield)
{
}


ItemType Armor::getItemType() const { return ItemType::ARMOR; }

QJsonObject Armor::toJson() const
{
    QJsonObject json = Item::toJson();

    json["Type"] = "Armor";
    json["Magic_Defense"] = static_cast<int>(_magic_defense);
    json["Magic_Defense_Bonus"] = _magic_defense_bonus;
    json["Defense"] = static_cast<int>(_defense);
    json["Defense_Bonus"] = _defense_bonus;
    json["Initiative"] = _initiative;
    json["IsShield"] = _isShield;
    json["IsMartial"] = _isMartial;

    return json;
}

int Armor::getInitiative() const { return _initiative; }
bool Armor::getIsMartial() const { return _isMartial; }
bool Armor::getIsShield() const { return _isShield; }
int Armor::getMagDefBonus() const { return _magic_defense_bonus; }
int Armor::getDefBonus() const { return _defense_bonus; }
Attribute Armor::getMagDefAtr() const { return _magic_defense; }
Attribute Armor::getDefAtr() const { return _defense; }

void Armor::setInitiative(const int in) { _initiative = std::min(0, in); }
void Armor::setIsMartial(const bool m) { _isMartial = m; }
void Armor::setIsShield(const bool s) { _isShield = s; }
void Armor::setMagDef(const int md) { _magic_defense_bonus = md; }
void Armor::setDef(const int d) { _defense_bonus = d; }
