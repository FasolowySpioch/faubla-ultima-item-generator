#ifndef FULTIMA_GEN_ACCESSORYGENERATOR_H
#define FULTIMA_GEN_ACCESSORYGENERATOR_H

#include "GeneratorStrategy.h"
#include "../models/Accessory.h"
#include <random>

class AccessoryGenerator final : public GeneratorStrategy
{
    std::vector<std::unique_ptr<Accessory>> _cache_accessories;

public:
    explicit AccessoryGenerator(const std::string &file_path);

    std::unique_ptr<Item> generate(const Player &player) override;
};


#endif //FULTIMA_GEN_ACCESSORYGENERATOR_H