#ifndef FULTIMA_TEMP_WEAPON_H
#define FULTIMA_TEMP_WEAPON_H

#include "Item.h"
#include "AttributeEnum.h"
#include <string_view>


enum class DMGType {
    PHYSICAL = 0, AIR = 1, BOLT = 2, DARK = 3, EARTH = 4, FIRE = 5, ICE = 6, LIGHT = 7, POISON = 8, NONE = 99
};

enum class WeaponType {
    ARCANE = 0, BOW = 1, BRAWL = 2, DAGGER = 3, FIREARM = 4, FLAIL = 5, HEAVY = 6, SPEAR = 7, SWORD = 8, THROWN = 9, NONE = 99
};

class Weapon : public Item
{
    WeaponType _weapon_type;
    int _dmg_desc;
    DMGType _dmg_type;
    Attribute _accuracy1;
    Attribute _accuracy2;
    int _accuracy_bonus;
    bool _isSingleHanded;
    bool _isRange;
    bool _isMartial;

public:
    Weapon();
    Weapon(std::string_view name, std::string_view desc, int default_price, int price, WeaponType weapon_type, int dmg_desc,
        DMGType dmg_type, Attribute accuracy1, Attribute accuracy2, int accuracy_bonus,
        bool isSingleHanded, bool isRange, bool isMartial);

    ItemType getItemType() const override;
    QJsonObject toJson() const override;

    WeaponType getWeaponType() const;
    int getDmgDesc() const;
    Attribute getAccuracy1() const;
    Attribute getAccuracy2() const;
    int getAccuracyBonus() const;
    DMGType getDmgType() const;
    bool getIsSingleHanded() const;
    bool getIsRange() const;
    bool getIsMartial() const;

    void setType(WeaponType t);
    void setDmgDesc(int dd);
    void setAccuracy1(Attribute a1);
    void setAccuracy2(Attribute a2);
    void setAccuracyBonus(int ab);
    void setDmgType(DMGType dt);
    void setIsSingleHanded(bool ish);
    void setIsRange(bool ir);
    void setIsMartial(bool im);

};



#endif //FULTIMA_TEMP_WEAPON_H