#ifndef FULTIMA_GEN_ITEMGENERATORSYSTEM_H
#define FULTIMA_GEN_ITEMGENERATORSYSTEM_H

#include "GeneratorStrategy.h"
#include "QualityGenerator.h"
#include <map>

class ItemGeneratorSystem
{
    std::map<ItemType, std::unique_ptr<GeneratorStrategy>> strategies;
    std::unique_ptr<QualityGenerator> quality_strategy;
    std::mt19937 mt;

public:
    ItemGeneratorSystem();

    std::unique_ptr<Item> generateItem(const Player &player, ItemType type);
    void rerollQuality(ItemType type, Item *item) const;
};


#endif //FULTIMA_GEN_ITEMGENERATORSYSTEM_H
