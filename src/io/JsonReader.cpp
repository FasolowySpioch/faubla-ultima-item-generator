#include "JsonReader.h"
#include <QFIle>
#include <QJsonArray>
#include <QJsonObject>


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



std::vector<std::unique_ptr<Item>> JsonReader::loadItems(const QString& file_path)
{
    if (file_path.isEmpty())
        throw std::invalid_argument("File path is empty");
    if (!file_path.endsWith(".json"))
        throw std::invalid_argument("File path not pointing to .json file");
    if (!QFile::exists(file_path))
        throw std::invalid_argument("File does not exist");

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

    if (!RootObj.value("Weapon").isArray())
        throw std::runtime_error("JsonReader::loadItems: 'Weapon' value isn't array.");
    QJsonArray WeaponsArr = RootObj.value("Weapon").toArray();


    std::vector<std::unique_ptr<Item>> ParsedItems;

    for (QJsonArray::const_iterator it = WeaponsArr.cbegin(); it != WeaponsArr.cend(); ++it)
    {
        if (!it->isObject()) throw std::runtime_error("JsonReader::loadItems: the value inside of array isn't object.");
        ParsedItems.push_back(parseWeapon(it->toObject()));
    }

    return ParsedItems;
}