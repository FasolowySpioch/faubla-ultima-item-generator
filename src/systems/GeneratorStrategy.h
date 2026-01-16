#ifndef FULTIMA_GEN_GENERATORSTRATEGY_H
#define FULTIMA_GEN_GENERATORSTRATEGY_H

#include "../models/Item.h"
#include "../models/Player.h"
#include <memory>
#include <random>

class GeneratorStrategy
{
protected:
    std::mt19937 _mt;

public:
    virtual ~GeneratorStrategy() = default;
    virtual std::unique_ptr<Item> generate(const Player& player) = 0;
};


#endif //FULTIMA_GEN_GENERATORSTRATEGY_H