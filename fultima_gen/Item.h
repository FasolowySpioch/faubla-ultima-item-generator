#pragma once
#include <iostream>
#include <string>
#include "Enums.h"
//#include "json.hpp"

class Item
{
protected:
	std::string _name, _desc, _file_path;
	int _zenith_cost;

public:
	virtual std::string getName();
	virtual std::string getDesc();
	virtual int getPrice();
	virtual std::string getFilePath();

	virtual void setName(std::string n);
	virtual void setFilePath(std::string fp);
	virtual void setDesc(std::string d);

	virtual void calculateCost(int b_cost, int mod_cost = 0);
};

