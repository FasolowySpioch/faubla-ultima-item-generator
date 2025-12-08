#pragma once
#include <iostream>
#include <string>
#include "Enums.h"
//#include "json.hpp"

class Item
{
protected:
	std::string _name, _desc;
	int _zenith_cost;

public:
	Item() : _name(""), _desc(""), _zenith_cost(0) {}
	Item(std::string name, std::string desc, int price) :
		_name(name), _desc(desc), _zenith_cost(price) {
	}
	virtual std::string getName();
	virtual std::string getDesc();
	virtual int getPrice();

	virtual void setName(std::string n);
	virtual void setDesc(std::string d);
	virtual void setPrice(int p);

	//virtual void calculateCost(int b_cost, int mod_cost = 0);
};

