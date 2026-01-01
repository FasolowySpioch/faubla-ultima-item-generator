#ifndef FULTIMA_GEN_WEAPONGENERATOR_H
#define FULTIMA_GEN_WEAPONGENERATOR_H

#include "GeneratorStrategy.h"
#include <random>

class WeaponGenerator : public GeneratorStrategy
{
    std::vector<std::unique_ptr<Weapon>> _cache_weapons;
    std::mt19937 _mt;

    static bool isWeaponUsable(const Player &player, const Weapon &weapon);
    void filterByPlayerPreference(const Player &player, std::vector<const Weapon*> &candidates) const;
    void filterByPlayerAttributesHard(const Player &player, std::vector<const Weapon*> &candidates) const;
    void filterByPlayerAttributesSoft(const Player &player, std::vector<const Weapon*> &candidates) const;

public:
    explicit WeaponGenerator(const std::string& file_path);

    std::unique_ptr<Item> generate(const Player &player) override;
};


#endif //FULTIMA_GEN_WEAPONGENERATOR_H