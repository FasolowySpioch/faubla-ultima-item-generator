#pragma once
#include "Item.h"
class Weapon :
    public Item
{
private:
    std::string _type, _dmg_desc;
	Atributes _accuracy1, _accuracy2;
	int _accuracy_bonus;
	DMGType _dmg_type;
	bool _isSingleHanded, _isRange, _isMartial;
	//Quality podpada pod desc ogólnie, bo z perspektywy kodu bêdzie to osobno
public:
	Weapon() : Item(), _type(""), _dmg_desc(""), _accuracy1(Atributes::WLP), _accuracy2(Atributes::WLP),
		_accuracy_bonus(0), _dmg_type(DMGType::PHYSICAL), _isSingleHanded(true), _isRange(false), _isMartial(false) {}
	Weapon(std::string name, std::string desc, int price, std::string type, std::string dmg_desc,
		Atributes accuracy1, Atributes accuracy2, int accuracy_bonus, DMGType dmg_type,
		bool isSingleHanded, bool isRange, bool isMartial) :
		Item(name, desc, price), _type(type), _dmg_desc(dmg_desc),
		_accuracy1(accuracy1), _accuracy2(accuracy2), _accuracy_bonus(accuracy_bonus),
		_dmg_type(dmg_type), _isSingleHanded(isSingleHanded), _isRange(isRange), _isMartial(isMartial) {}
	
	std::string getType();
	std::string getDmgDesc();
	Atributes getAccuracy1();
	Atributes getAccuracy2();
	int getAccuracyBonus();
	DMGType getDmgType();
	bool getIsSingleHanded();
	bool getIsRange();
	bool getIsMartial();
	void setType(std::string t);
	void setDmgDesc(std::string dd);
	void setAccuracy1(Atributes a1);
	void setAccuracy2(Atributes a2);
	void setAccuracyBonus(int ab);
	void setDmgType(DMGType dt);
	void setIsSingleHanded(bool ish);
	void setIsRange(bool ir);
	void setIsMartial(bool im);
};

