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
    if(p.getPreferredWeaponType() == w.getWeaponType()) std::cerr << "OK\n";
    else std::cerr<<"FAIL\n";
}

void Test::readWeapon(const Weapon &GenWeapon){
    std::cerr << "\tname: " << GenWeapon.getName() << '\n';
    std::cerr << "\tquality: "<< GenWeapon.getDesc() << '\n';
    std::cerr << "\tprice: " << GenWeapon.getPrice() << '\n';
    std::cerr << "\tweapon_type: " << weapon_type[static_cast<size_t>(GenWeapon.getWeaponType())] << '\n';
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
    std::cerr<<"\t\t\t=== ARMOR TYPE TESTS START ===\n";
    testArmorPreferences();
    testArmorRandom();
    //testLegalArmorQuality();
}

void Test::testArmorPreferences(){
    std::cerr<<"\n=== ARMOR TEST ===\n";
    try{
        std::unique_ptr<Player> p = std::make_unique<Player>(
            "X'Azih",
            "FasolowySpioch",
            9,
            Attribute::NONE,
            Attribute::NONE,
            WeaponType::HEAVY,
            false,
            false,
            false,
            false
            );
        std::cerr<<"Generating armor for a player...";
        std::unique_ptr<Item> GenItem= _wg->generate(*p);
        std::cerr<<"OK\n";

        auto* GenArmor = dynamic_cast<Armor*>(GenItem.get());

        std::cerr<<"Reading armor...\n";
        try{
            readArmor(*GenArmor);
            std::cerr <<"Reading complete!\n";
        }
        catch(const std::exception& e){
            std::cerr<<"FAIL! --- " << e.what();
        }
        std::cerr<<"\n=MAIN CHECK=\n";
        std::cerr << "Armor valid: \n";
        std::cerr << "\tMartial: ";
        checkMartial(*GenArmor, *p);
        std::cerr << "\tShield: ";
        checkShield(*GenArmor, *p);
    }
    catch(const std::exception& e){
        std::cerr<<"FAIL! --- " << e.what();
    }
}

void Test::testArmorRandom(){
    std::cerr<<"\n=== ARMOR TEST ===\n";
    try{
        std::unique_ptr<Player> p = std::make_unique<Player>(
            "Kael",
            "Reddi",
            5,
            Attribute::NONE,
            Attribute::NONE,
            WeaponType::NONE,
            true,
            true,
            true,
            true
            );
        std::cerr<<"Generating armor for a player...";
        std::unique_ptr<Item> GenItem= _wg->generate(*p);
        std::cerr<<"OK\n";

        auto* GenArmor = dynamic_cast<Armor*>(GenItem.get());

        std::cerr<<"Reading armor...\n";
        try{
            readArmor(*GenArmor);
            std::cerr <<"Reading complete!\n";
        }
        catch(const std::exception& e){
            std::cerr<<"FAIL! --- " << e.what();
        }
        std::cerr<<"\n=MAIN CHECK=\n";
        std::cerr << "Armor valid: \n";
        std::cerr << "\tMartial: ";
        checkMartial(*GenArmor, *p);
        std::cerr << "\tShield: ";
        checkShield(*GenArmor, *p);
    }
    catch(const std::exception& e){
        std::cerr<<"FAIL! --- " << e.what();
    }
}

void Test::checkMartial(const Armor &a, const Player &p){
    if(p.getCanMartialArmor() == true) std::cerr<<"OK\n";
    else {
        if(p.getCanMartialArmor() == a.getIsMartial()) std::cerr<<"OK\n";
        else std::cerr<<"FAIL\n";
    }
}

void Test::checkShield(const Armor &a, const Player &p){
    if(p.getCanShield() == true) std::cerr<<"OK\n";
    else {
        if(p.getCanShield() == a.getIsShield()) std::cerr<<"OK\n";
        else std::cerr<<"FAIL\n";
    }
}

void Test::readArmor(const Armor &GenArmor){
    std::cerr << "\tname: " << GenArmor.getName() << '\n';
    std::cerr << "\tquality: "<< GenArmor.getDesc() << '\n';
    std::cerr << "\tprice: " << GenArmor.getPrice() << '\n';
    std::cerr << "\tinitiative" << GenArmor.getInitiative() << '\n';
    std::cerr << "\tisMartial" << GenArmor.getIsMartial() << '\n';
    std::cerr << "\tisShield" << GenArmor.getIsShield() << '\n';
    std::cerr << "\tmagDerBonus" << GenArmor.getMagDefBonus() << '\n';
    std::cerr << "\tdefBonus" << GenArmor.getDefBonus() << '\n';
    std::cerr << "\tmagDefAtr" << attributes[static_cast<size_t>(GenArmor.getMagDefAtr())];
    std::cerr << "\tdefAtr" << attributes[static_cast<size_t>(GenArmor.getDefAtr())];
}
//=== SCENARIOS TESTS

//=== OTHER
void Test::checkCost(const Item &i){
    std::cerr << "\tcost: " << i.getPrice() << '\n';
}

void Test::checkCostToLevel(const Item &i, const Player &p){
    int maxPrice = 0;
    int price = i.getPriceModified();
    if(p.getLevel()>=40){
        std::cerr << "\tcost: " << price << "\t==>\tOK\n";
    }else{
        if(p.getLevel()>=30){
            maxPrice = 2000;
        }else if(p.getLevel()>=20){
            maxPrice = 1500;
        }else if(p.getLevel()>=10){
            maxPrice = 1000;
        }else if(p.getLevel()>=5){
            maxPrice = 500;
        }else{
            std::cerr << "FAIL --- TOO LOW PLAYER LEVEL\n";
        }
        if(price > maxPrice)
            std::cerr << "\tcost: " << price << "\t==>\tFAIL --- TOO MUCH VALUE OF ITEM\n";
        else
            std::cerr << "\tcost: " << price << "\t==>\tOK\n";
    }
}
