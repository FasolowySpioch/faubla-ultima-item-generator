#ifndef FULTIMA_TEMP_WEAPON_H
#define FULTIMA_TEMP_WEAPON_H

#include "Item.h"
#include <string_view>

enum class Attributes {
    NONE = 0, WLP = 1, INS = 2, DEX = 3, MIG = 4 //Jak w JSONIe jest cokolwiek powyżej 3 to zmusić generator do przypisania wartości która jest tam wpisana
};

enum class DMGType {
    NONE = 0, PHYSICAL = 1, AIR = 2, BOLT = 3, DARK = 4, EARTH = 5, FIRE = 6, ICE = 7, LIGHT = 8, POISON = 9
};

enum class WeaponType {
    NONE = 0, ARCANE = 1, BOW = 2, BRAWL = 3, DAGGER = 4, FIREARM = 5, FLAIL = 6, HEAVY = 7, SPEAR = 8, SWORD = 9, THROWN = 10
};

class Weapon : public Item
{
    WeaponType _weapon_type;
    int _dmg_desc;
    DMGType _dmg_type;
    Attributes _accuracy1;
    Attributes _accuracy2;
    int _accuracy_bonus;
    bool _isSingleHanded;
    bool _isRange;
    bool _isMartial;
    //Quality podpada pod desc og�lnie, bo z perspektywy kodu b�dzie to osobno

public:
    Weapon();
    Weapon(std::string_view name, std::string_view desc, int price, WeaponType weapon_type, int dmg_desc,
        DMGType dmg_type, Attributes accuracy1, Attributes accuracy2, int accuracy_bonus,
        bool isSingleHanded, bool isRange, bool isMartial);

    WeaponType getType() const;
    int getDmgDesc() const;
    Attributes getAccuracy1() const;
    Attributes getAccuracy2() const;
    int getAccuracyBonus() const;
    DMGType getDmgType() const;
    bool getIsSingleHanded() const;
    bool getIsRange() const;
    bool getIsMartial() const;

    void setType(WeaponType t);
    void setDmgDesc(int dd);
    void setAccuracy1(Attributes a1);
    void setAccuracy2(Attributes a2);
    void setAccuracyBonus(int ab);
    void setDmgType(DMGType dt);
    void setIsSingleHanded(bool ish);
    void setIsRange(bool ir);
    void setIsMartial(bool im);

};



#endif //FULTIMA_TEMP_WEAPON_H