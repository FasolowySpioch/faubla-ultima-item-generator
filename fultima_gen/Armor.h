#pragma once
#include "Item.h"
class Armor :
    public Item
{
private:
    int _iniciative;
    bool _isMartial;
    std::string _m_defense, _defense;

public:
    std::string getMDef();
    std::string getDef();
    bool getIsMartial();
    int getIniciative();

    void setIniciative(int i);
    void setIsMartial(bool m);
    void setMDefense(std::string md);
    void setDefense(std::string d);
};

