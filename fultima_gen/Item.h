#pragma once
#include <iostream>
#include <string>

class Item
{
private:
	std::string _name;
	std::string _desc;
	int _zenith_cost;
public:
	virtual std::string getName();
	virtual std::string getDesc();
	virtual int getPrice();

	virtual void generateDesc() = 0;
	virtual void calculateCost() = 0;
};

