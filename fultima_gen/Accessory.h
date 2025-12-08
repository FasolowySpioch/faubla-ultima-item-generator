#pragma once
#include "Item.h"
class Accessory :
    public Item
{
public:
    Accessory() : Item() {}
    Accessory(std::string name, std::string desc, int price) :
		Item(name, desc, price) {
	}
};

