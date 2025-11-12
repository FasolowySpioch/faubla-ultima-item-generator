#include "Item.h"

std::string Item::getName() { return _name; }
std::string Item::getDesc() { return _desc; }
int Item::getPrice() { return _zenith_cost; }
std::string Item::getFilePath() { return _file_path; }

void Item::setName(std::string n) { _name = n; }
void Item::setFilePath(std::string fp) { _file_path = fp; }

void Item::calculateCost(int b_cost, int mod_cost = 0) {
	_zenith_cost = b_cost + mod_cost;
}

void Item::setDesc(std::string d) { _desc = d; }