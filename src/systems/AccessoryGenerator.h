#ifndef FULTIMA_GEN_ACCESSORYGENERATOR_H
#define FULTIMA_GEN_ACCESSORYGENERATOR_H

#include "GeneratorStrategy.h"

class Accessory : public GeneratorStrategy
{
public:
    std::unique_ptr<Item> generate(const Player &player) override;
};



#endif //FULTIMA_GEN_ACCESSORYGENERATOR_H