#include "Item.h"

Item::Item()
    : _zenith_cost(0)
{
}

Item::Item(const std::string_view name, const std::string_view desc, const int price)
    : _name(name)
    , _desc(desc)
    , _zenith_cost(price)
{
}

std::string_view Item::getName() const { return _name; }
std::string_view Item::getDesc() const { return _desc; }
int Item::getPrice() const { return _zenith_cost; }

void Item::setName(const std::string_view n) { _name = n; }
void Item::setDesc(const std::string_view d) { _desc = d; }
void Item::setPrice(const int p) { _zenith_cost = p; }
