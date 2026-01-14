#ifndef FULTIMA_TEMP_ARMOR_H
#define FULTIMA_TEMP_ARMOR_H

#include "Item.h"
#include "AttributeEnum.h"
#include <string_view>

class Armor : public Item
{
    Attribute _magic_defense;
    Attribute _defense;
    int _magic_defense_bonus;
    int _defense_bonus;
    int _initiative;
    bool _isMartial;
    bool _isShield;

public:
    Armor();
    Armor(std::string_view name, std::string_view desc, int price, int initiative,
        bool isMartial, Attribute magic_defense, int magic_defense_bonus, Attribute defense, int defense_bonus, bool isShield);

    int getInitiative() const;
    bool getIsMartial() const;
    bool getIsShield() const;
    int getMagDefBonus() const;
    int getDefBonus() const;
    Attribute getMagDefAtr() const;
    Attribute getDefAtr() const;

    void setInitiative(int in);
    void setIsMartial(bool m);
    void setIsShield(bool s);
    void setMagDef(int md);
    void setDef(int d);
};



#endif //FULTIMA_TEMP_ARMOR_H
