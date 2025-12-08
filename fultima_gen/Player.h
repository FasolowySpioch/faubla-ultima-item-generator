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
public:
	Player() : _level(5), _primary_die1(Atributes::WLP), _primary_die2(Atributes::WLP), _preffered_weapon_type("") {}
	Player(int level, Atributes primary_die1, Atributes primary_die2, std::string preffered_weapon_type) :
		_level(level), _primary_die1(primary_die1), _primary_die2(primary_die2), _preffered_weapon_type(preffered_weapon_type) {}
	int getLevel();
	Atributes getPrimaryDie1();
	Atributes getPrimaryDie2();
	std::string getPrefferedWeaponType();
	void setLevel(int l);
	void setPrimaryDie1(Atributes pd1);
	void setPrimaryDie2(Atributes pd2);
	void setPrefferedWeaponType(std::string pwt);
};

