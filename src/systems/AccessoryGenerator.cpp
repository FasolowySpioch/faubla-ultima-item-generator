#include "AccessoryGenerator.h"
#include "../io/JsonReader.h"


// Generate empty item, the Quality is assigned later
std::unique_ptr<Item> AccessoryGenerator::generate(const Player &player)
{
    return std::make_unique<Accessory>();
}
