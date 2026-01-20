//
// Created by ola on 5.01.2026.
//

#ifndef FULTIMA_GEN_TEST_H
#define FULTIMA_GEN_TEST_H
#include <iostream>

#include "../systems/ItemGeneratorSystem.h"

#include "../systems/AccessoryGenerator.h"
#include "../systems/ArmorGenerator.h"
#include "../systems/QualityGenerator.h"
#include "../systems/WeaponGenerator.h"


class Test {
    private:
        ItemGeneratorSystem _igs;
        std::unique_ptr<WeaponGenerator> _wg = std::make_unique<WeaponGenerator>("../../data/basic/Basic_Weapons.json");
        std::unique_ptr<ArmorGenerator> _ag = std::make_unique<ArmorGenerator>("../../data/basic/Basic_Armor_Shield.json");
        std::unique_ptr<QualityGenerator> _qg = std::make_unique<QualityGenerator>("../../data/basic/Basic_Weapon_Qualities.json");

        //STRING ARRAYS
        std::string attributes[4] = {"WLP", "INS", "DEX", "MIG"};
        std::string dmg_type[9] = {"PHYSICAL", "AIR", "BOLT", "DARK", "EARTH",
                                  "FIRE", "ICE", "LIGHT", "POISON"};
        std::string weapon_type[10] = {"ARCANE", "BOW", "BRAWL", "DAGGER", "FIREARM",
                                     "FLAIL", "HEAVY", "SPEAR", "SWORD", "THROWN"};


        void checkMartial(const Weapon &w, const Player &p);
        void checkRange(const Weapon &w, const Player &p);
        void checkAttributes(const Weapon &w, const Player &p);
        void checkPreference(const Weapon &w, const Player &p);
        void readWeapon(const Weapon &GenWeapon);


        void checkCost(const Item &i);
        void checkCostToLevel(const Item &i, const Player &p);


        void checkMartial(const Armor &a);
        void readArmor(const Armor &a);
        void checkMartial(const Armor &a, const Player &p);
        void checkShield(const Armor &a, const Player &p);

    public:
        //=== WEAPON GENERATOR TESTS ===
        void allWeaponTests();
        // ======
        void testWeaponFullPreferences();
        void testWeaponAttributePreference();
        void testWeaponTypePreference();
        void testWeaponRandom();
        //=== ARMOR GENERATOR TESTS ===
        void allArmorTests();
        //===
        void testArmorPreferences();
        void testArmorRandom();
        void testLegalArmorQuality();

        //=== SCENARIOS TESTS
        void allIGSTests();

        void testIGSRandom();
        void testIGSSpecific();

        void allCostTests();
        //TODO: write those later when it works.
        //=== ACCESSORIES GENERATOR TEST ===
};


#endif //FULTIMA_GEN_TEST_H
