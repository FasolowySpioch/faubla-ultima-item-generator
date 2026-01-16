#include "JsonReader.h"
#include <QFile>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>


std::unique_ptr<Weapon> JsonReader::parseWeapon(const QJsonObject &JsonWeaponObj)
{
    QString name = JsonWeaponObj.value("Name").toString();
    QString desc = JsonWeaponObj.value("Quality").toString();
    int price = JsonWeaponObj.value("Cost").toInt();

    WeaponType weapon_type = static_cast<WeaponType>(JsonWeaponObj.value("Type").toInt());
    int dmg_desc = JsonWeaponObj.value("Damage_desc").toInt();
    DMGType dmg_type = static_cast<DMGType>(JsonWeaponObj.value("Damage_type").toInt());
    Attribute accur_1 = static_cast<Attribute>(JsonWeaponObj.value("Accuracy_1").toInt());
    Attribute accur_2 = static_cast<Attribute>(JsonWeaponObj.value("Accuracy_2").toInt());
    int accur_bonus = JsonWeaponObj.value("Accuracy_bonus").toInt();
    bool isSingleHanded = JsonWeaponObj.value("IsSingleHanded").toBool();
    bool isRange = JsonWeaponObj.value("IsRange").toBool();
    bool isMartial = JsonWeaponObj.value("IsMartial").toBool();

    return std::make_unique<Weapon>(name.toStdString(), desc.toStdString(), price, weapon_type, dmg_desc, dmg_type, accur_1, accur_2, accur_bonus,
        isSingleHanded, isRange, isMartial);
}

std::unique_ptr<Armor> JsonReader::parseArmor(const QJsonObject &JsonArmorObj, bool makeShield)
{
    QString name = JsonArmorObj.value("Name").toString();
    QString desc = JsonArmorObj.value("Quality").toString();
    int price = JsonArmorObj.value("Cost").toInt();

    int initiative = JsonArmorObj.value("Initiative").toInt();
    Attribute magic_def = static_cast<Attribute>(JsonArmorObj.value("MagicDefense").toInt());
    int magic_def_bonus = JsonArmorObj.value("MagicDefenseBonus").toInt();
    Attribute def = static_cast<Attribute>(JsonArmorObj.value("Defense").toInt());
    int def_bonus = JsonArmorObj.value("DefenseBonus").toInt();
    bool isMartial = JsonArmorObj.value("IsMartial").toBool();

    return std::make_unique<Armor>(name.toStdString(), desc.toStdString(), price, initiative,
        isMartial, magic_def, magic_def_bonus, def, def_bonus, makeShield);
}

Quality JsonReader::parseQuality(const QJsonObject &JsonQualityObj, bool makeOffensive)
{
    QString desc = JsonQualityObj.value("Desc").toString();
    int cost_add = JsonQualityObj.value("Cost_add").toInt();

    return {desc.toStdString(), cost_add, makeOffensive};
}

std::vector<std::unique_ptr<Item>> JsonReader::loadItems(const QString& file_path, ItemType type)
{
    if (file_path.isEmpty())
        throw std::invalid_argument("JsonReader::loadItems: File path is empty");
    if (!file_path.endsWith(".json"))
        throw std::invalid_argument("JsonReader::loadItems: File path not pointing to .json file");
    if (!QFile::exists(file_path))
        throw std::invalid_argument("JsonReader::loadItems: File does not exist");
    if (type != ItemType::WEAPON && type != ItemType::ARMOR)
        throw std::invalid_argument("JsonReader::loadItems: Wrong type");

    QFile file(file_path);
    if (!file.open(QIODevice::ReadOnly))
        throw std::runtime_error("JsonReader::loadItems: Couldn't open JSON file.");

    QJsonParseError jsonError;
    QJsonDocument JsonWeaponsDoc = QJsonDocument::fromJson(file.readAll(), &jsonError);
    file.close();
    if (jsonError.error != QJsonParseError::NoError)
        throw std::runtime_error("JsonReader::loadItems: JSON parsing error -- " + jsonError.errorString().toStdString());

    if (!JsonWeaponsDoc.isObject())
        throw std::runtime_error("JsonReader::loadItems: JSON's root isn't object.");
    QJsonObject RootObj = JsonWeaponsDoc.object();

    QJsonArray ItemsArr;
    QJsonArray alt_ShieldsArr;

    if (type == ItemType::WEAPON)
    {
        if (!RootObj.value("Weapon").isArray())
            throw std::runtime_error("JsonReader::loadItems: 'Weapon' value isn't array.");
        ItemsArr = RootObj.value("Weapon").toArray();
    }
    else
    {
        if (!RootObj.value("Armor").isArray())
            throw std::runtime_error("JsonReader::loadItems: 'Armor' value isn't array.");
        if (!RootObj.value("Shield").isArray())
            throw std::runtime_error("JsonReader::loadItems: 'Shield' value isn't array.");

        ItemsArr = RootObj.value("Armor").toArray();
        alt_ShieldsArr = RootObj.value("Shield").toArray();
    }


    std::vector<std::unique_ptr<Item>> ParsedItems;

    for (const auto item : ItemsArr)
    {
        if (!item.isObject()) throw std::runtime_error("JsonReader::loadItems: the value inside of array isn't object.");
        if (type == ItemType::WEAPON)
            ParsedItems.push_back(parseWeapon(item.toObject()));
        else
            ParsedItems.push_back(parseArmor(item.toObject(), false));
    }

    if (!alt_ShieldsArr.isEmpty())
    {
        for (const auto item : alt_ShieldsArr)
        {
            if (!item.isObject()) throw std::runtime_error("JsonReader::loadItems: the value inside of array isn't object.");
            ParsedItems.push_back(parseArmor(item.toObject(), true));
        }
    }

    return ParsedItems;
}

std::vector<Quality> JsonReader::loadQualities(const QString& file_path)
{
    if (file_path.isEmpty())
        throw std::invalid_argument("JsonReader::loadQualities: File path is empty");
    if (!file_path.endsWith(".json"))
        throw std::invalid_argument("JsonReader::loadQualities: File path not pointing to .json file");
    if (!QFile::exists(file_path))
        throw std::invalid_argument("JsonReader::loadQualities: File does not exist");

    QFile file(file_path);
    if (!file.open(QIODevice::ReadOnly))
        throw std::runtime_error("JsonReader::loadQualities: Couldn't open JSON file.");

    QJsonParseError jsonError;
    QJsonDocument JsonWeaponsDoc = QJsonDocument::fromJson(file.readAll(), &jsonError);
    file.close();
    if (jsonError.error != QJsonParseError::NoError)
        throw std::runtime_error("JsonReader::loadQualities: JSON parsing error -- " + jsonError.errorString().toStdString());

    if (!JsonWeaponsDoc.isObject())
        throw std::runtime_error("JsonReader::loadQualities: JSON's root isn't object.");
    QJsonObject RootObj = JsonWeaponsDoc.object();

    if (!RootObj.value("Offensive_Quality").isArray())
        throw std::runtime_error("JsonReader::loadQualities: 'Offensive_Quality' value isn't array.");
    QJsonArray OffensiveQArr = RootObj.value("Offensive_Quality").toArray();

    if (!RootObj.value("Defensive_Quality").isArray())
        throw std::runtime_error("JsonReader::loadQualities: 'Defensive_Quality' value isn't array.");
    QJsonArray DefensiveQArr = RootObj.value("Defensive_Quality").toArray();


    std::vector<Quality> ParsedQualities;

    for (const auto quality : OffensiveQArr)
    {
        if (!quality.isObject()) throw std::runtime_error("JsonReader::loadQualities: the value inside of the 'Offensive_Quality' array isn't object.");
        ParsedQualities.push_back(parseQuality(quality.toObject(), true));
    }

    for (const auto quality : DefensiveQArr)
    {
        if (!quality.isObject()) throw std::runtime_error("JsonReader::loadQualities: the value inside of the 'Defensive_Quality' array isn't object.");
        ParsedQualities.push_back(parseQuality(quality.toObject(), false));
    }

    return ParsedQualities;
}
