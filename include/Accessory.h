#ifndef FULTIMA_TEMP_ACCESSORY_H
#define FULTIMA_TEMP_ACCESSORY_H

#include "Item.h"

class Accessory : public Item
{
public:
    Accessory() = default;
    Accessory(std::string_view name, std::string_view desc, int price);
};


#endif //FULTIMA_TEMP_ACCESSORY_H