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
	Armor() : Item(), _iniciative(0), _isMartial(false), _m_defense(""), _defense("") {}
    Armor(std::string name, std::string desc, int price, int iniciative, bool isMartial, std::string m_defense, std::string defense) :
        Item(name, desc, price), _iniciative(iniciative), _isMartial(isMartial), _m_defense(m_defense), _defense(defense) {}
    std::string getMDef();
    std::string getDef();
    bool getIsMartial();
    int getIniciative();

    void setIniciative(int i);
    void setIsMartial(bool m);
    void setMDefense(std::string md);
    void setDefense(std::string d);
};

