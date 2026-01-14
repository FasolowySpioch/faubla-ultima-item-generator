#ifndef FULTIMA_GEN_ACCESSORYGENERATOR_H
#define FULTIMA_GEN_ACCESSORYGENERATOR_H

#include "GeneratorStrategy.h"
#include "../models/Accessory.h"
#include <random>

class AccessoryGenerator final : public GeneratorStrategy
{

public:
    explicit AccessoryGenerator();

    std::unique_ptr<Item> generate(const Player &player) override;
};


#endif //FULTIMA_GEN_ACCESSORYGENERATOR_H