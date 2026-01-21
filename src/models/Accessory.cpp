#include "Accessory.h"

Accessory::Accessory(const std::string_view name, const std::string_view desc, const int default_price, const int price)
    : Item(name, desc, default_price, price)
{
}

ItemType Accessory::getItemType() const { return ItemType::ACCESSORY; }

QJsonObject Accessory::toJson() const
{
    QJsonObject json;

    json["Type"] = "Accessory";
    json["Name"] = QString::fromStdString(_name);
    json["Desc"] = QString::fromStdString(_desc);
    json["Default_Price"] = _default_price;
    json["Price"] = _price;

    return json;
}
