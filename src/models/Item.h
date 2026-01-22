#ifndef FULTIMA_TEMP_ITEM_H
#define FULTIMA_TEMP_ITEM_H

#include "IJsonSerializable.h"
#include <string>
#include <string_view>


enum class ItemType { WEAPON, ARMOR, ACCESSORY, RANDOM };

class Item : public IJsonSerializable
{
protected:
    std::string _name;
    std::string _desc;
    const int _default_price;
    int _price;
    int _quality_price;

public:
    Item();
    Item(std::string_view name, std::string_view desc, int default_price, int add_price = 0);
    ~Item() override = default;

    virtual ItemType getItemType() const = 0;
    QJsonObject toJson() const override;

    const std::string& getName() const;
    const std::string& getDesc() const;
    int getPrice() const;
    int getPriceModified() const;
    int getQualityPrice() const;

    void setName(std::string_view n);
    void setDesc(std::string_view d);
    void setDefaultDesc();
    void setDefaultPrice();
    void addToPrice(int add);
    void setQualityPrice(int q_price);
};


#endif //FULTIMA_TEMP_ITEM_H
