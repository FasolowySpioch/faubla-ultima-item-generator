//
// Created by Micha on 9.12.2025.
//

#ifndef FULTIMA_TEMP_ARMOR_H
#define FULTIMA_TEMP_ARMOR_H

#include "Item.h"
#include <string_view>

class Armor : public Item
{
    int _initiative;
    bool _isMartial;
    int _magic_defense;
    int _defense;

public:
    Armor() = default;
    Armor(std::string_view name, std::string_view desc, int price, int initiative,
        bool isMartial, int magic_defense, int defense);

    int getInitiative() const;
    bool getIsMartial() const;
    int getMagDef() const;
    int getDef() const;

    void setInitiative(int i);
    void setIsMartial(bool m);
    void setMagDef(int md);
    void setDef(int d);
};



#endif //FULTIMA_TEMP_ARMOR_H