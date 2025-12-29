#ifndef FULTIMA_GEN_ARMORGENERATOR_H
#define FULTIMA_GEN_ARMORGENERATOR_H

#include "GeneratorStrategy.h"

class ArmorGenerator : public GeneratorStrategy
{
public:
    std::unique_ptr<Item> generate(const Player &player) override;
};


#endif //FULTIMA_GEN_ARMORGENERATOR_H