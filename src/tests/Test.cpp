//
// Created by ola on 5.01.2026.
//
#include "Test.h"
//=== WEAPON GENERATOR TESTS ===
void Test::allWeaponTests(){
    std::cerr<<"\t\t\t=== WEAPON TESTS START ===\n";
    testWeaponFullPreferences();
    testWeaponAttributePreference();
    testWeaponTypePreference();
    testWeaponRandom();
    std::cerr<<"\t\t\t=== WEAPON TEST STOP ===\n";
}

//THESE TESTS DO NOT CHECK COST!
//Items generated in here do not have any quality, so costs are the default ones.
void Test::testWeaponFullPreferences(){
    std::cerr<<"\n=== WEAPON FULL PREFERENCES TEST ===\n";
    try{
        std::unique_ptr<Player> p = std::make_unique<Player>(
            "X'Azih",
            "FasolowySpioch",
            9,
            Attribute::MIG,
            Attribute::MIG,
            WeaponType::HEAVY,
            true,
            true,
            false,
            false
            );

        std::cerr<<"Generating weapon for a player...";
        std::unique_ptr<Item> GenItem= _wg->generate(*p);
        std::cerr<<"OK\n";

        auto* GenWeapon = dynamic_cast<Weapon*>(GenItem.get());

        std::cerr<<"Reading weapon...\n";
        try{
            readWeapon(*GenWeapon);
            std::cerr <<"Reading complete!\n";

        }
        catch(const std::exception& e){
            std::cerr<<"FAIL! --- " << e.what();
        }
        std::cerr<<"\n=MAIN CHECK=\n";
        //player with all the attributes and weapon preferences
        std::cerr << "Weapon valid: \n";
        std::cerr << "\tMartial: "; //If player has martial as true, player can still use nonmartial weapons.
        checkMartial(*GenWeapon, *p);
        std::cerr << "\tRanged: ";
        checkRange(*GenWeapon, *p);
        std::cerr<<"Player attributes considered: ";
        checkAttributes(*GenWeapon, *p);
        std::cerr<<"Player weapon preference: ";
        checkPreference(*GenWeapon, *p);

    }
    catch(const std::exception& e){
        std::cerr<<"FAIL! --- " << e.what();
    }
}

void Test::testWeaponAttributePreference(){
        std::cerr<<"\n=== WEAPON ATTRIBUTES PREFERENCE TEST ===\n";
        try{
        std::unique_ptr<Player> p = std::make_unique<Player>(
            "Kael",
            "Reddi",
            5,
            Attribute::DEX,
            Attribute::INS,
            WeaponType::NONE,
            true,
            false,
            true,
            false
                );
            std::cerr<<"Generating weapon for a player...";
            std::unique_ptr<Item> GenItem= _wg->generate(*p);
            std::cerr<<"OK\n";

            auto* GenWeapon = dynamic_cast<Weapon*>(GenItem.get());

            std::cerr<<"Reading weapon...\n";
            try{
                readWeapon(*GenWeapon);
                std::cerr <<"Reading complete!\n";

            }
            catch(const std::exception& e){
                std::cerr<<"FAIL! --- " << e.what();
            }
            std::cerr<<"\n=MAIN CHECK=\n";
            std::cerr << "Weapon valid: \n";
            std::cerr << "\tMartial: "; //If player has martial as true, player can still use nonmartial weapons.
            checkMartial(*GenWeapon, *p);
            std::cerr << "\tRanged: ";
            checkRange(*GenWeapon, *p);
            std::cerr<<"Player attributes considered: ";
            checkAttributes(*GenWeapon, *p);

        }
        catch(const std::exception& e){
            std::cerr<<"FAIL! --- " << e.what();
        }
    }

void Test::testWeaponTypePreference(){
std::cerr<<"\n=== WEAPON TYPE PREFERENCE TEST ===\n";
    try{
    std::unique_ptr<Player> p = std::make_unique<Player>(
        "X'Azih",
        "FasolowySpioch",
        9,
        Attribute::NONE,
        Attribute::NONE,
        WeaponType::HEAVY,
        true,
        true,
        false,
        false
        );
    std::cerr<<"Generating weapon for a player...";
    std::unique_ptr<Item> GenItem= _wg->generate(*p);
    std::cerr<<"OK\n";

    auto* GenWeapon = dynamic_cast<Weapon*>(GenItem.get());

    std::cerr<<"Reading weapon...\n";
        try{
            readWeapon(*GenWeapon);
            std::cerr <<"Reading complete!\n";
        }
        catch(const std::exception& e){
            std::cerr<<"FAIL! --- " << e.what();
        }
        std::cerr<<"\n=MAIN CHECK=\n";
        std::cerr << "Weapon valid: \n";
        std::cerr << "\tMartial: "; //If player has martial as true, player can still use nonmartial weapons.
        checkMartial(*GenWeapon, *p);
        std::cerr << "\tRanged: ";
        checkRange(*GenWeapon, *p);
        std::cerr<<"Player weapon preference: ";
        checkPreference(*GenWeapon, *p);
    }
    catch(const std::exception& e){
        std::cerr<<"FAIL! --- " << e.what();
    }
}

void Test::testWeaponRandom() {
    std::cerr<<"\n=== WEAPON TYPE PREFERENCE TEST ===\n";
    try{
        std::unique_ptr<Player> p = std::make_unique<Player>(
            "Kael",
            "Reddi",
            5,
            Attribute::NONE,
            Attribute::NONE,
            WeaponType::NONE,
            true,
            false,
            true,
            false
            );
        std::cerr<<"Generating weapon for a player...";
        std::unique_ptr<Item> GenItem= _wg->generate(*p);
        std::cerr<<"OK\n";

        auto* GenWeapon = dynamic_cast<Weapon*>(GenItem.get());

        std::cerr<<"Reading weapon...\n";
        try{
            readWeapon(*GenWeapon);
            std::cerr <<"Reading complete!\n";
        }
        catch(const std::exception& e){
            std::cerr<<"FAIL! --- " << e.what();
        }
        std::cerr<<"\n=MAIN CHECK=\n";
        std::cerr << "Weapon valid: \n";
        std::cerr << "\tMartial: "; //If player has martial as true, player can still use nonmartial weapons.
        checkMartial(*GenWeapon, *p);
        std::cerr << "\tRanged: ";
        checkRange(*GenWeapon, *p);
    }
    catch(const std::exception& e){
        std::cerr<<"FAIL! --- " << e.what();
    }
}

void Test::checkMartial(const Weapon &w, const Player &p){
    if(p.getCanMartialWeapon() == true) std::cerr<<"OK\n";
    else {
        if(p.getCanMartialWeapon() == w.getIsMartial()) std::cerr<<"OK\n";
        else std::cerr<<"FAIL\n";
    }
}

void Test::checkRange(const Weapon &w, const Player &p){
    if(p.getCanRange() == true) std::cerr<<"OK\n";
    else{
        if(p.getCanRange() == w.getIsRange()) std::cerr << "OK\n";
        else std::cerr<<"FAIL";
    }
}

void Test::checkAttributes(const Weapon &w, const Player &p){
    if(p.getPrimaryDie1() == p.getPrimaryDie2()){
        if(p.getPrimaryDie1() == w.getAccuracy1() || p.getPrimaryDie1() == w.getAccuracy2()) std::cerr<<"OK\n";
        else std::cerr<<"FAIL\n";
    }
    else if(p.getPrimaryDie1() == w.getAccuracy1() || p.getPrimaryDie1() == w.getAccuracy2()) std::cerr<<"OK\n";
    else if(p.getPrimaryDie2() == w.getAccuracy1() || p.getPrimaryDie2() == w.getAccuracy2()) std::cerr<<"OK\n";
    else std::cerr<<"FAIL\n";
}

void Test::checkPreference(const Weapon &w, const Player &p){
    if(p.getPreferredWeaponType() == w.getType()) std::cerr << "OK\n";
    else std::cerr<<"FAIL\n";
}

void Test::readWeapon(const Weapon &GenWeapon){
    std::cerr << "\tname: " << GenWeapon.getName() << '\n';
    std::cerr << "\tquality: "<< GenWeapon.getDesc() << '\n';
    std::cerr << "\tprice: " << GenWeapon.getPrice() << '\n';
    std::cerr << "\tweapon_type: " << weapon_type[static_cast<size_t>(GenWeapon.getType())] << '\n';
    std::cerr << "\tdmg_desc: " << GenWeapon.getDmgDesc() << '\n';
    std::cerr << "\tdmg_type: " << dmg_type[static_cast<size_t>(GenWeapon.getDmgType())] << '\n';
    std::cerr << "\taccuracy_1: " << attributes[static_cast<size_t>(GenWeapon.getAccuracy1())] << '\n';
    std::cerr << "\taccuracy_2: " << attributes[static_cast<size_t>(GenWeapon.getAccuracy2())] << '\n';
    std::cerr << "\taccuracy_bonus: " << GenWeapon.getAccuracyBonus() << '\n';
    std::cerr << "\tisMartial: " << GenWeapon.getIsMartial() << '\n';
    std::cerr << "\tisRange: " << GenWeapon.getIsRange() << '\n';
    std::cerr << "\tisSingleHanded: " << GenWeapon.getIsSingleHanded() << '\n';
}


//=== ARMOR GENERATOR TESTS ===
void Test::allArmorTests(){
   // testArmorPreferances();
   // testArmorRandom();
   // testLegalArmorQuality();
}
//=== SCENARIOS TESTS

//=== OTHER
void Test::checkCost(const Item &i){

}

void Test::checkCostToLevel(const Item &i, const Player &p){

}
