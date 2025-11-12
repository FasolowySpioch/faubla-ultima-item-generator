#include "Armor.h"
std::string Armor::getMDef() { return _m_defense; }
std::string Armor::getDef() { return _defense;  }
bool Armor::getIsMartial() { return _isMartial; }
int Armor::getIniciative() { return _iniciative; }

void Armor::setIniciative(int i) { _iniciative = i; }
void Armor::setIsMartial(bool m) { _isMartial = m; }
void Armor::setMDefense(std::string md) { _m_defense = md; }
void Armor::setDefense(std::string d) { _defense = d; }