#include "ArmorGenerator.h"
#include "../io/JsonReader.h"


ArmorGenerator::ArmorGenerator(const std::string &file_path)
{
    // rng init
    std::random_device seed;
    _mt = std::mt19937(seed());

    // loading the file
    JsonReader reader;
    const std::vector<std::unique_ptr<Item>> loadedItems = JsonReader::loadItems(QString::fromStdString(file_path), ItemType::ARMOR);

    // caching the file and casting to derived class
    _cache_armors.reserve(loadedItems.size());
    for (auto& item : loadedItems)
    {
        if (auto* armor_ptr = dynamic_cast<Armor*>(item.get()))
            _cache_armors.push_back(std::make_unique<Armor>(*armor_ptr));
    }
}


bool ArmorGenerator::isArmorUsable(const Player &player, const Armor &armor)
{
    if (!player.getCanMartialWeapon() && armor.getIsMartial())
        return false;
    if (!player.getCanShield() && armor.getIsShield())
        return false;

    return true;
}

std::unique_ptr<Item> ArmorGenerator::generate(const Player &player)
{
    std::vector<Armor*> armors_final;

    // pick up armors that player can use
    for (auto &a : _cache_armors)
    {
        if (!isArmorUsable(player, *a))
            continue;

        armors_final.push_back(a.get());
    }

    // if still empty, then either:
    // - there's no armors matching the requirements (like, in the file)
    // - OR player is meant to have absolutely nothing
    if (armors_final.empty())
        return nullptr;
        // throw exception ??

    // choosing random armor to return
    std::uniform_int_distribution<> dist(0, armors_final.size() - 1);

    return std::make_unique<Armor>(*armors_final[dist(_mt)]);
}