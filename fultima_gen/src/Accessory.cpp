//
// Created by Micha on 9.12.2025.
//

#include "../include/Accessory.h"

Accessory::Accessory(const std::string_view name, const std::string_view desc, const int price)
    : Item(name, desc, price)
{
}
