#include "Accessory.h"

Accessory::Accessory(const std::string_view name, const std::string_view desc, const int price)
    : Item(name, desc, price)
{
}
