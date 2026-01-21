#ifndef FULTIMA_GEN_WEAPONTYPECONVERTER_H
#define FULTIMA_GEN_WEAPONTYPECONVERTER_H

#include "../models/Weapon.h"
#include <QString>
#include <string>


struct WeaponTypeConverter
{
    static std::string toString(const WeaponType wt)
    {
        switch (wt)
        {
            case WeaponType::ARCANE: return "ARCANE";
            case WeaponType::BOW: return "BOW";
            case WeaponType::BRAWL: return "BRAWL";
            case WeaponType::DAGGER: return "DAGGER";
            case WeaponType::FIREARM: return "FIREARM";
            case WeaponType::FLAIL: return "FLAIL";
            case WeaponType::HEAVY: return "HEAVY";
            case WeaponType::SPEAR: return "SPEAR";
            case WeaponType::SWORD: return "SWORD";
            case WeaponType::THROWN: return "THROWN";
            case WeaponType::NONE: return "NONE";
            default: return "[undefined]";
        }
    }

    static QString toQString(const WeaponType wt)
    {
        return QString::fromStdString(toString(wt));
    }

};


#endif //FULTIMA_GEN_WEAPONTYPECONVERTER_H