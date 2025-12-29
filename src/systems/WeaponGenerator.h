#ifndef FULTIMA_GEN_WEAPONGENERATOR_H
#define FULTIMA_GEN_WEAPONGENERATOR_H

#include "GeneratorStrategy.h"

class WeaponGenerator : public GeneratorStrategy
{
public:
    std::unique_ptr<Item> generate(const Player &player) override;
};


#endif //FULTIMA_GEN_WEAPONGENERATOR_H