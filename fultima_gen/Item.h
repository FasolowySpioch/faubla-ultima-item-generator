#pragma once
#include <iostream>
#include <string>

class Item
{
protected:
	std::string _name;
	std::string _desc;
	int _zenith_cost;

	virtual void generateDesc();
	virtual void calculateCost();

public:
	virtual std::string getName();
	virtual std::string getDesc();
	virtual int getPrice();
};

