#pragma once
#include "Item.h"
class Armor :
    public Item
{
private:
    int _iniciative;
    bool isMartial;
    std::string _quality, _m_defense, _defense;

public:
    std::string getQuality();
    std::string getMDef();
    std::string getDef();

    int getIsMartial();

};

