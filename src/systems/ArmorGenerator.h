#ifndef FULTIMA_GEN_ARMORGENERATOR_H
#define FULTIMA_GEN_ARMORGENERATOR_H

#include "GeneratorStrategy.h"
#include "../models/Armor.h"

class ArmorGenerator final : public GeneratorStrategy
{
    std::vector<std::unique_ptr<Armor>> _cache_armors;

    static bool isArmorUsable(const Player &player, const Armor &armor);

public:
    explicit ArmorGenerator(const QString &file_path);

    std::unique_ptr<Item> generate(const Player &player) override;
};


#endif //FULTIMA_GEN_ARMORGENERATOR_H