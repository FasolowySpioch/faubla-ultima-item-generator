#ifndef FULTIMA_TEMP_ARMOR_H
#define FULTIMA_TEMP_ARMOR_H

#include "Item.h"
#include "AttributeEnum.h"
#include <string_view>

class Armor : public Item
{
    int _initiative;
    int _magic_defense;
    int _defense;
    bool _isMartial;
    bool _isShield;

public:
    Armor();
    Armor(std::string_view name, std::string_view desc, int price, int initiative,
        bool isMartial, int magic_defense, int defense, bool isShield);

    int getInitiative() const;
    bool getIsMartial() const;
    bool getIsShield() const;
    int getMagDefBonus() const;
    int getDefBonus() const;
    static Attribute getMagDefAtr();
    Attribute getDefAtr() const;

    void setInitiative(int in);
    void setIsMartial(bool m);
    void setIsShield(bool s);
    void setMagDef(int md);
    void setDef(int d);
};



#endif //FULTIMA_TEMP_ARMOR_H
