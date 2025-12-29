#include "mainwindow.h"
#include "src/systems/WeaponGenerator.h"

#include <QApplication>
#include <iostream>

void testWeaponGenerator();

int main(int argc, char *argv[])
{
    // QApplication a(argc, argv);
    // MainWindow w;
    // w.show();
    // return a.exec();
    testWeaponGenerator();
    return 0;
}

void testWeaponGenerator()
{
    // ====== PRE-REQS ======

    std::unique_ptr<Player> pl = std::make_unique<Player>(
        "Kael",
        "Reddi",
        5,
        Attribute::DEX,
        Attribute::INS,
        // WeaponType::SWORD,
        WeaponType::NONE,
        false,
        false,
        true,
        false
    );

    std::string attributes[] = {"WLP", "INS", "DEX", "MIG"};
    std::string dmg_type[] = {"PHYSICAL", "AIR", "BOLT", "DARK", "EARTH",
        "FIRE", "ICE", "LIGHT", "POISON"};
    std::string weapon_type[] = {"ARCANE", "BOW", "BRAWL", "DAGGER", "FIREARM",
        "FLAIL", "HEAVY", "SPEAR", "SWORD", "THROWN"};

    WeaponGenerator WeaponGen;

    // ====== TEST START ======

    try
    {
        std::unique_ptr<Item> GeneratedItem = WeaponGen.generate(*pl);
        std::cerr << "weapon generation test: OK\n";

        auto* GeneratedWeapon = static_cast<Weapon*>(GeneratedItem.get());
        std::cerr << "weapon attributes read test:\n";
        try
        {
            std::cerr << "\tname: " << GeneratedWeapon->getName() << '\n';
            std::cerr << "\tdesc: " << GeneratedWeapon->getDesc() << '\n';
            std::cerr << "\tprice: " << GeneratedWeapon->getPrice() << '\n';
            std::cerr << "\tweapon_type: " << weapon_type[static_cast<size_t>(GeneratedWeapon->getType())] << '\n';
            std::cerr << "\tdmg_desc: " << GeneratedWeapon->getDmgDesc() << '\n';
            std::cerr << "\tdmg_type: " << dmg_type[static_cast<size_t>(GeneratedWeapon->getDmgType())] << '\n';
            std::cerr << "\taccuracy1: " << attributes[static_cast<size_t>(GeneratedWeapon->getAccuracy1())] << '\n';
            std::cerr << "\taccuracy2: " << attributes[static_cast<size_t>(GeneratedWeapon->getAccuracy2())] << '\n';
            std::cerr << "\taccuracy_bonus: " << GeneratedWeapon->getAccuracyBonus() << '\n';
            std::cerr << "\tisSingleHanded: " << GeneratedWeapon->getIsSingleHanded() << '\n';
            std::cerr << "\tisRange: " << GeneratedWeapon->getIsRange() << '\n';
            std::cerr << "\tisMartial: " << GeneratedWeapon->getIsMartial() << '\n';

            std::cerr << "OK\n";
        }
        catch (const std::exception& e)
        {
            std::cerr << "weapon attributes read test: FAIL! -- " << e.what() << '\n';
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "weapon generation test: FAIL! -- " << e.what() << '\n';
    }

    // ====== TEST END ======
}
