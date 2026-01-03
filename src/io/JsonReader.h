#ifndef FULTIMA_GEN_JSONREADER_H
#define FULTIMA_GEN_JSONREADER_H

#include "../models/Item.h"
#include "../models/Weapon.h"
#include "../models/Armor.h"
#include "../models/Quality.h"
#include <QJsonObject>
#include <memory>
#include <vector>


class JsonReader
{
    std::unique_ptr<Weapon> parseWeapon(const QJsonObject& JsonWeaponObj);
    std::unique_ptr<Armor> parseArmor(const QJsonObject& JsonArmorObj, bool makeShield);
    Quality parseQuality(const QJsonObject &JsonQualityObj, bool makeOffensive);   // makeOffensive == false --> return defensive

public:
    std::vector<std::unique_ptr<Item>> loadItems(const QString& file_path, ItemType type);
    std::vector<Quality> loadQualities(const QString& file_path);
};


#endif //FULTIMA_GEN_JSONREADER_H