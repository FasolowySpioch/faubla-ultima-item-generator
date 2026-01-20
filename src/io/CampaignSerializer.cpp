#include "CampaignSerializer.h"
#include "../models/Armor.h"
#include "../models/Accessory.h"

#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonParseError>

std::unique_ptr<Player> CampaignSerializer::playerFromJson(QJsonObject json_player)
{
    if (json_player["Type"] != "Player")
        return std::make_unique<Player>();
        // idk im too fucking tired to think what to do here

    std::string character_name = json_player["Character_Name"].toString().toStdString();
    std::string author_name = json_player["Author_Name"].toString().toStdString();
    int level = json_player["Level"].toInt();
    auto primary_die1 = static_cast<Attribute>(json_player["Primary_Die_1"].toInt());
    auto primary_die2 = static_cast<Attribute>(json_player["Primary_Die_2"].toInt());
    auto preferred_weapon = static_cast<WeaponType>(json_player["Preferred_Weapon_Type"].toInt());
    bool canMartialWeapon = json_player["CanMartialWeapon"].toBool();
    bool canMartialArmor = json_player["CanMartialArmor"].toBool();
    bool canRange = json_player["CanRange"].toBool();
    bool canShield = json_player["CanShield"].toBool();

    return std::make_unique<Player>(character_name, author_name, level, primary_die1, primary_die2,
        preferred_weapon, canMartialWeapon, canMartialArmor, canRange, canShield);
}

std::unique_ptr<Item> CampaignSerializer::itemFromJson(QJsonObject json_item)
{
    if (json_item["Type"] != "Weapon"
        && json_item["Level"] != "Armor"
        && json_item["Type"] != "Accessory")
        return nullptr;
        // same here

    std::string name = json_item["Name"].toString().toStdString();
    std::string desc = json_item["Desc"].toString().toStdString();
    int default_price = json_item["Default_Price"].toInt();
    int price = json_item["Price"].toInt();

    std::unique_ptr<Item> item = nullptr;

    if (json_item["Type"] == "Weapon")
    {
        auto weapon_type = static_cast<WeaponType>(json_item["Weapon_Type"].toInt());
        int dmg_desc = json_item["Dmg_Desc"].toInt();
        auto dmg_type = static_cast<DMGType>(json_item["Dmg_Type"].toInt());
        auto accuracy1 = static_cast<Attribute>(json_item["Accuracy1"].toInt());
        auto accuracy2 = static_cast<Attribute>(json_item["Accuracy2"].toInt());
        int accuracy_bonus = json_item["Accuracy_Bonus"].toInt();
        bool isSingleHanded = json_item["IsSingleHanded"].toBool();
        bool isRange = json_item["IsRange"].toBool();
        bool isMartial = json_item["IsMartial"].toBool();

        item = std::make_unique<Weapon>(name, desc, default_price, price, weapon_type, dmg_desc, dmg_type, accuracy1, accuracy2,
            accuracy_bonus, isSingleHanded, isRange, isMartial);
    }
    else if (json_item["Type"] == "Armor")
    {
        auto magic_def = static_cast<Attribute>(json_item["Magic_Defense"].toInt());
        int magic_def_bonus = json_item["Magic_Defense_Bonus"].toInt();
        auto def = static_cast<Attribute>(json_item["Defense"].toInt());
        int def_bonus = json_item["Defense_Bonus"].toInt();
        int init = json_item["Initiative"].toInt();
        bool isShield = json_item["IsShield"].toBool();
        bool isMartial = json_item["IsMartial"].toBool();

        item = std::make_unique<Armor>(name, desc, default_price, price, init, isMartial, magic_def, magic_def_bonus,
            def, def_bonus, isShield);
    }
    else if (json_item["Type"] == "Accessory")
    {
        item = std::make_unique<Accessory>(name, desc, default_price, price);
    }

    return item;
}


bool CampaignSerializer::save(const CampaignManager &mng, const QString &file_path)
// Saves the campaign inside &mng into json. Returns true if successful.
{
    if (file_path.isEmpty())
        return false;
    if (!file_path.endsWith(".json"))
        return false;

    QJsonArray PlayersArr;
    for (auto &player : mng.getPlayers())
        PlayersArr.append(player->toJson());

    QJsonArray ItemsArr;
    for (auto &item : mng.getItems())
        ItemsArr.append(item->toJson());

    QJsonObject RootObj;
    RootObj["Players"] = PlayersArr;
    RootObj["Items"] = ItemsArr;

    QJsonDocument JsonDocument(RootObj);
    QFile file(file_path);
    if (!file.open(QIODevice::WriteOnly))
        return false;

    file.write(JsonDocument.toJson());
    return true;
}

bool CampaignSerializer::load(CampaignManager &mng, const QString &file_path)
// Loads the saved campaign into &mng. Returns true if successful.
{
    if (file_path.isEmpty())
        return false;
    if (!file_path.endsWith(".json"))
        return false;
    if (!QFile::exists(file_path))
        return false;

    QFile file(file_path);
    if (!file.open(QIODevice::ReadOnly))
        return false;

    QJsonParseError jsonError;
    QJsonDocument JsonWeaponsDoc = QJsonDocument::fromJson(file.readAll(), &jsonError);
    file.close();
    if (jsonError.error != QJsonParseError::NoError)
        return false;

    if (!JsonWeaponsDoc.isObject())
        return false;
    QJsonObject RootObj = JsonWeaponsDoc.object();

    if (!RootObj.value("Players").isArray() || !RootObj.value("Items").isArray())
        return false;

    QJsonArray PlayersArr = RootObj.value("Players").toArray();
    QJsonArray ItemsArr = RootObj.value("Items").toArray();

    for (auto json_player : PlayersArr)
        mng.addPlayer(playerFromJson(json_player.toObject()));

    for (auto json_item : ItemsArr)
        mng.addItem(itemFromJson(json_item.toObject()));

    return true;
}
