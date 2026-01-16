#ifndef FULTIMA_GEN_ITEMGENERATORSYSTEM_H
#define FULTIMA_GEN_ITEMGENERATORSYSTEM_H

#include "GeneratorStrategy.h"
#include "QualityGenerator.h"
#include <map>

class ItemGeneratorSystem
{
    std::map<ItemType, std::unique_ptr<GeneratorStrategy>> strategies;
    std::map<ItemType, std::unique_ptr<QualityGenerator>> quality_gen;
    std::mt19937 mt;

    ItemType getRandomItemType();
    static bool isItemPriceValid(const Item &item, const Player &player);

public:
    ItemGeneratorSystem();

    std::unique_ptr<Item> generateItem(const Player &player, ItemType type);
    void assignQuality(ItemType type, Item *item);
};


#endif //FULTIMA_GEN_ITEMGENERATORSYSTEM_H
