#include "Armor.h"


Armor::Armor()
    : _initiative(0)
    , _isMartial(false)
    , _magic_defense(Attribute::NONE)
    , _magic_defense_bonus(0)
    , _defense(Attribute::NONE)
    , _defense_bonus(0)
    , _isShield(false)
{
}

Armor::Armor(const std::string_view name, const std::string_view desc, const int default_price, const int price,
             const int initiative, const bool isMartial, const Attribute magic_defense, const int magic_defense_bonus, const Attribute defense, const int defense_bonus, const bool isShield)
    : Item(name, desc, default_price, price)
    , _initiative((initiative <= 0) ? initiative : 0)   //throw std::invalid_argument("Armor::Armor: Invalid value for _initiative");
    , _isMartial(isMartial)
    , _magic_defense(magic_defense)
    , _magic_defense_bonus(magic_defense_bonus)
    , _defense(defense)
    , _defense_bonus(defense_bonus)
    , _isShield(isShield)
{
}


ItemType Armor::getItemType() const { return ItemType::ARMOR; }

QJsonObject Armor::toJson() const
{
    QJsonObject json;

    json["Type"] = "Armor";
    json["Name"] = QString::fromStdString(_name);
    json["Desc"] = QString::fromStdString(_desc);
    json["Default_Price"] = _default_price;
    json["Price"] = _price;

    json["Magic_Defense"] = static_cast<int>(_magic_defense);
    json["Magic_Defense_Bonus"] = _magic_defense_bonus;
    json["Defense"] = static_cast<int>(_defense);
    json["Defense_Bonus"] = _defense_bonus;
    json["Initiative"] = _initiative;
    json["IsShield"] = _isShield ? 1 : 0;
    json["IsMartial"] = _isMartial ? 1 : 0;

    return json;
}


int Armor::getInitiative() const { return _initiative; }
bool Armor::getIsMartial() const { return _isMartial; }
bool Armor::getIsShield() const { return _isShield; }
int Armor::getMagDefBonus() const { return _magic_defense_bonus; }
int Armor::getDefBonus() const { return _defense_bonus; }
Attribute Armor::getMagDefAtr() const { return _magic_defense; }
Attribute Armor::getDefAtr() const { return _defense; }

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
void Armor::setMagDef(const int md) { _magic_defense_bonus = md; }    // input check?
void Armor::setDef(const int d) { _defense_bonus = d; }               // input check?
