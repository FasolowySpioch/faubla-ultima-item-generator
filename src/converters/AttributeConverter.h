#ifndef FULTIMA_GEN_ATTRIBUTECONVERTER_H
#define FULTIMA_GEN_ATTRIBUTECONVERTER_H

#include "../models/AttributeEnum.h"
#include <QString>
#include <string>


struct AttributeConverter
{
    static std::string toString(const Attribute attr)
    {
        switch (attr)
        {
            case Attribute::WLP: return "WLP";
            case Attribute::INS: return "INS";
            case Attribute::DEX: return "DEX";
            case Attribute::MIG: return "MIG";
            case Attribute::NONE: return "NONE";
            default: return "[undefined]";
        }
    }

    static QString toQString(const Attribute attr)
    {
        return QString::fromStdString(toString(attr));
    }

};


#endif //FULTIMA_GEN_ATTRIBUTECONVERTER_H