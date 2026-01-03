#include "AccessoryGenerator.h"
#include "../io/JsonReader.h"


AccessoryGenerator::AccessoryGenerator(const std::string &file_path)
{
    // rng init
    std::random_device seed;
    _mt = std::mt19937(seed());

    // loading the file
    JsonReader reader;
    const std::vector<std::unique_ptr<Item>> loadedItems = reader.loadItems(QString::fromStdString(file_path), ItemType::ACCESSORY);

    // caching the file and casting to derived class
    _cache_accessories.reserve(loadedItems.size());
    for (auto& item : loadedItems)
    {
        if (auto* accessory_ptr = dynamic_cast<Accessory*>(item.get()))
            _cache_accessories.push_back(std::make_unique<Accessory>(*accessory_ptr));
    }
}

// == how should it be even generated????? ==
std::unique_ptr<Item> AccessoryGenerator::generate(const Player &player)
{
    // if cache is empty, then probably something's wrong with the file
    // (or there's a little chance that player is meant to have absolutely nothing)
    if (_cache_accessories.empty())
        return nullptr;
        // throw exception ??

    // choosing random armor to return
    std::uniform_int_distribution<> dist(0, _cache_accessories.size() - 1);

    return std::make_unique<Accessory>(*_cache_accessories[dist(_mt)]);
}