#ifndef FULTIMA_TEMP_ACCESSORY_H
#define FULTIMA_TEMP_ACCESSORY_H

#include "Item.h"
#include <string_view>

class Accessory : public Item
{
public:
    Accessory() = default;
    Accessory(std::string_view name, std::string_view desc, int default_price, int price);

    ItemType getItemType() const override;
    QJsonObject toJson() const override;
};


#endif //FULTIMA_TEMP_ACCESSORY_H