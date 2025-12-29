#include "WeaponGenerator.h"
#include "../models/Weapon.h"

#include <QFIle>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QString>
#include <algorithm>
#include <vector>
#include <iterator>
#include <random>

std::unique_ptr<Item> WeaponGenerator::generate(const Player &player)
{

    // ================== WCZYTYWANIE Z JSON ==================

    QFile file("../data/basic/Basic_Weapons.json");
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
    else if (player.getPreferredWeaponType() == WeaponType::NONE || JsonMatchedObjs.isEmpty())
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
            else if (JsonVal.toObject().value("Accuracy_1").toInt() == static_cast<int>(player.getPrimaryDie2()))
            {
                if (JsonVal.toObject().value("Accuracy_2").toInt() == static_cast<int>(player.getPrimaryDie1()))
                    JsonMatchedObjs.push_back(JsonVal);
                else
                    JsonWeaklyMatchedObjs.push_back(JsonVal);
            }
        }
    }

    std::mt19937 mt;
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

    // Utworzyć obiekt Weapon z SelectedJsonObject
    // Zwrócić wynik
    // + testy
}
