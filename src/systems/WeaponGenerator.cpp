#include "WeaponGenerator.h"
#include "../models/Weapon.h"

#include <QFIle>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QString>
#include <algorithm>
#include <iterator>
#include <random>
#include <iostream>

std::unique_ptr<Item> WeaponGenerator::generate(const Player &player)
{

    // ================== WCZYTYWANIE Z JSON ==================

    QFile file("../../data/basic/Basic_Weapons.json");
    if (!file.open(QIODevice::ReadOnly))
        throw std::runtime_error("WeaponGenerator::generate: Couldn't open JSON file");

    QJsonParseError jsonError;
    QJsonDocument JsonWeaponsDoc = QJsonDocument::fromJson(file.readAll(), &jsonError);
    file.close();

    if (jsonError.error != QJsonParseError::NoError)
        throw std::runtime_error("WeaponGenerator::generate: JSON parsing error -- " + jsonError.errorString().toStdString());

    if (!JsonWeaponsDoc.isObject())
        throw std::runtime_error("WeaponGenerator::generate: JSON's content isn't object.");
    QJsonObject RootObj = JsonWeaponsDoc.object();

    if (!RootObj.value("Weapon").isArray())
        throw std::runtime_error("WeaponGenerator::generate: 'Weapon' value isn't array.");
    QJsonArray WeaponsArr = RootObj.value("Weapon").toArray();

    // =========================================================

    QJsonArray JsonMatchedObjs;
    QJsonArray JsonWeaklyMatchedObjs;

    if (player.getPreferredWeaponType() != WeaponType::NONE)
    {
        std::copy_if(WeaponsArr.begin(), WeaponsArr.end(), std::back_inserter(JsonMatchedObjs), [&](QJsonValueRef JsonVal) {
            return JsonVal.toObject().value("Type").toInt() == static_cast<int>(player.getPreferredWeaponType());
        });
    }
    else if (JsonMatchedObjs.isEmpty())
    {
        for (QJsonValueRef JsonVal : WeaponsArr)
        {
            if (JsonVal.toObject().value("Accuracy_1").toInt() == static_cast<int>(player.getPrimaryDie1()))
            {
                if (JsonVal.toObject().value("Accuracy_2").toInt() == static_cast<int>(player.getPrimaryDie2()))
                    JsonMatchedObjs.push_back(JsonVal);
                else
                    JsonWeaklyMatchedObjs.push_back(JsonVal);
            }
            // jesli 1-szy atrybut nie zgadza sie z 1-sza koscia gracza, sprawdz druga kosc
            else if (JsonVal.toObject().value("Accuracy_1").toInt() == static_cast<int>(player.getPrimaryDie2()))
            {
                if (JsonVal.toObject().value("Accuracy_2").toInt() == static_cast<int>(player.getPrimaryDie1()))
                    JsonMatchedObjs.push_back(JsonVal);
                else
                    JsonWeaklyMatchedObjs.push_back(JsonVal);
            }
        }
    }

    // === Testing purposes ===
    // for (auto el : JsonWeaklyMatchedObjs){
    //     std::cerr << "\t\t" << el.toObject().value("Name").toString().toStdString() << '\n';
    // }


    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // !!!!!!!!!!!!!!!!!   DOROBIĆ SPRAWDZENIE FLAG   !!!!!!!!!!!!!!!!!!!!!!!
    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


    static std::random_device seed;
    static std::mt19937 mt(seed());
    QJsonValue SelectedJsonObj;

    if (!JsonMatchedObjs.isEmpty())
    {
        if (JsonMatchedObjs.size() > 1)
        {
            std::uniform_int_distribution<> dist(0, JsonMatchedObjs.size() - 1);
            SelectedJsonObj = JsonMatchedObjs[dist(mt)];
        }
        else
            SelectedJsonObj = JsonMatchedObjs.last();
    }
    else if (!JsonWeaklyMatchedObjs.isEmpty())
    {
        if (JsonWeaklyMatchedObjs.size() > 1)
        {
            std::uniform_int_distribution<> dist(0, JsonWeaklyMatchedObjs.size() - 1);
            SelectedJsonObj = JsonWeaklyMatchedObjs[dist(mt)];
        }
        else
            SelectedJsonObj = JsonWeaklyMatchedObjs.last();
    }

    std::unique_ptr<Item> ParsedObj = std::make_unique<Weapon>(
        SelectedJsonObj.toObject().value("Name").toString().toStdString(),
        SelectedJsonObj.toObject().value("Quality").toString().toStdString(),
        SelectedJsonObj.toObject().value("Cost").toInt(),
        static_cast<WeaponType>(SelectedJsonObj.toObject().value("Type").toInt()),
        SelectedJsonObj.toObject().value("Damage_desc").toInt(),
        static_cast<DMGType>(SelectedJsonObj.toObject().value("Damage_type").toInt()),
        static_cast<Attribute>(SelectedJsonObj.toObject().value("Accuracy_1").toInt()),
        static_cast<Attribute>(SelectedJsonObj.toObject().value("Accuracy_2").toInt()),
        SelectedJsonObj.toObject().value("Accuracy_bonus").toInt(),
        SelectedJsonObj.toObject().value("IsSingleHanded").toBool(),
        SelectedJsonObj.toObject().value("IsRange").toBool(),
        SelectedJsonObj.toObject().value("IsMartial").toBool()
        );

    return std::move(ParsedObj);
}
