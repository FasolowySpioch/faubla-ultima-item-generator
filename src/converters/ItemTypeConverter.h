#ifndef FULTIMA_GEN_ENUMCONVERTER_H
#define FULTIMA_GEN_ENUMCONVERTER_H

#include "../models/Item.h"
#include <string>


struct ItemTypeConverter
{
    static std::string toString(const ItemType it)
    {
        switch (it)
        {
            case ItemType::WEAPON: return "Weapon";
            case ItemType::ARMOR: return "Armor";
            case ItemType::ACCESSORY: return "Accessory";
            case ItemType::RANDOM: return "Random";
            default: return "[undefined]";
        }
    }

    static QString toQString(const ItemType it)
    {
        return QString::fromStdString(toString(it));
    }
};


#endif //FULTIMA_GEN_ENUMCONVERTER_H