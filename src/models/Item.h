#ifndef FULTIMA_TEMP_ITEM_H
#define FULTIMA_TEMP_ITEM_H

#include <string>
#include <string_view>


enum class ItemType { WEAPON, ARMOR, ACCESSORY };

class Item
{
    std::string _name;
    std::string _desc;
    int _zenith_cost;

public:
    Item();
    Item(std::string_view name, std::string_view desc, int price);
    virtual ~Item() = 0;

    const std::string& getName() const;
    const std::string& getDesc() const;
    int getPrice() const;

    void setName(std::string_view n);
    void setDesc(std::string_view d);
    void setPrice(int p);
};



#endif //FULTIMA_TEMP_ITEM_H
