#include "Item.h"

Item::Item()
    : _default_price(0)
    , _price(0)
{
}

Item::Item(const std::string_view name, const std::string_view desc, const int default_price, const int add_price)
    : _name(name)
    , _desc(desc)
    , _default_price(default_price)
    , _price(_default_price + add_price)
{
}

QJsonObject Item::toJson() const
{
    QJsonObject json;

    json["Name"] = QString::fromStdString(_name);
    json["Desc"] = QString::fromStdString(_desc);
    json["Default_Price"] = _default_price;
    json["Price"] = _price;

    return json;
}

const std::string& Item::getName() const { return _name; }
const std::string& Item::getDesc() const { return _desc; }
int Item::getPrice() const { return _default_price; }
int Item::getPriceModified() const { return _price; }

void Item::setName(const std::string_view n) { _name = n; }
void Item::setDesc(const std::string_view d) { _desc = d; }
void Item::setDefaultDesc() { _desc = "No quality."; }
void Item::setDefaultPrice() { _price = _default_price; }
void Item::increasePriceBy(const int add) { _price = _default_price + add; }
