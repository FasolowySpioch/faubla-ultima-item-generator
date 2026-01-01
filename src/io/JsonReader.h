#ifndef FULTIMA_GEN_JSONREADER_H
#define FULTIMA_GEN_JSONREADER_H

#include "../models/Item.h"
#include "../models/Weapon.h"
#include <QJsonObject>
// #include <QString>
#include <memory>
#include <vector>


class JsonReader
{
    std::unique_ptr<Weapon> parseWeapon(const QJsonObject& JsonWeaponObj);
public:
    std::vector<std::unique_ptr<Item>> loadItems(const QString& file_path);
};


#endif //FULTIMA_GEN_JSONREADER_H