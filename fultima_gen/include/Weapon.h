//
// Created by Micha on 9.12.2025.
//

#ifndef FULTIMA_TEMP_WEAPON_H
#define FULTIMA_TEMP_WEAPON_H

#include "Item.h"
#include <string_view>

enum class Attributes {
    WLP = 0, INS = 1, DEX = 2, MIG = 3 //Jak w JSONIe jest cokolwiek powyżej 3 to zmusić generator do przypisania wartości która jest tam wpisana
};

enum class DMGType {
    PHYSICAL = 0, AIR = 1, BOLT = 2, DARK = 3, EARTH = 4, FIRE = 5, ICE = 6, LIGHT = 7, POISON = 8
};

enum class WeaponType {
    ARCANE = 0, BOW = 1, BRAWL = 2, DAGGER = 3, FIREARM = 4, FLAIL = 5, HEAVY = 6, SPEAR = 7, SWORD = 8, THROWN = 9
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
    Weapon() = default;
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