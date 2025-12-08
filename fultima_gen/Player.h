#pragma once
#include <string>
#include "Enums.h"

class Player
{
private:
	int _level;
	Atributes _primary_die1, _primary_die2;
	std::string _preffered_weapon_type;
	// std::string _preffered_armor_type; (?)
	bool _canMartialWeapon, _canMartialArmor, _canRange, _canShield;
	std::string _name;
public:
	Player() : _level(5), _primary_die1(Atributes::WLP), _primary_die2(Atributes::WLP),
		_preffered_weapon_type(""), _canMartialWeapon(false), _canMartialArmor(false),
		_canRange(false), _canShield(false), _name("") {
	}
	Player(int level, Atributes primary_die1, Atributes primary_die2,
		std::string preffered_weapon_type, bool canMartialWeapon,
		bool canMartialArmor, bool canRange, bool canShield,
		std::string name) :
		_level(level), _primary_die1(primary_die1), _primary_die2(primary_die2),
		_preffered_weapon_type(preffered_weapon_type), _canMartialWeapon(canMartialWeapon),
		_canMartialArmor(canMartialArmor), _canRange(canRange), _canShield(canShield),
		_name(name) {
	}
	int getLevel();
	Atributes getPrimaryDie1();
	Atributes getPrimaryDie2();
	std::string getPrefferedWeaponType();
	bool getCanMartialWeapon();
	bool getCanMartialArmor();
	bool getCanRange();
	bool getCanShield();
	std::string getName();

	void setLevel(int level);
	void setPrimaryDie1(Atributes pd1);
	void setPrimaryDie2(Atributes pd2);
	void setPrefferedWeaponType(std::string pwt);
	void setCanMartialWeapon(bool cmw);
	void setCanMartialArmor(bool cma);
	void setCanRange(bool cr);
	void setCanShield(bool cs);
	void setName(std::string name);
	
};

