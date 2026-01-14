#include "AccessoryGenerator.h"
#include "../io/JsonReader.h"


AccessoryGenerator::AccessoryGenerator()
{
    // rng init
    std::random_device seed;
    _mt = std::mt19937(seed());
}

// == how should it be even generated????? ==
//Answer: Generate empty item and assign a quality to it. Congrats item is done, just check if cost is valid. I will create some namegen later maybe
std::unique_ptr<Item> AccessoryGenerator::generate(const Player &player)
{
    return std::make_unique<Accessory>();
}
