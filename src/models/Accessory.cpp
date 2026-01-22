#include "Accessory.h"

Accessory::Accessory(const std::string_view name, const std::string_view desc, const int default_price, const int price)
    : Item(name, desc, default_price, price - default_price)
{
}


ItemType Accessory::getItemType() const { return ItemType::ACCESSORY; }

QJsonObject Accessory::toJson() const
{
    QJsonObject json = Item::toJson();

    json["Type"] = "Accessory";

    return json;
}
