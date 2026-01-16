#ifndef FULTIMA_GEN_WEAPONGENERATOR_H
#define FULTIMA_GEN_WEAPONGENERATOR_H

#include "GeneratorStrategy.h"
#include <random>

class WeaponGenerator final : public GeneratorStrategy
{
    std::vector<std::unique_ptr<Weapon>> _cache_weapons;

    static bool isWeaponUsable(const Player &player, const Weapon &weapon);
    [[nodiscard]] std::vector<const Weapon*> filterByPlayerPreference(const Player &player) const;
    [[nodiscard]] std::vector<const Weapon*> filterByPlayerAttributesHard(const Player &player) const;
    [[nodiscard]] std::vector<const Weapon*> filterByPlayerAttributesSoft(const Player &player) const;

public:
    explicit WeaponGenerator(const std::string &file_path);

    std::unique_ptr<Item> generate(const Player &player) override;
};


#endif //FULTIMA_GEN_WEAPONGENERATOR_H