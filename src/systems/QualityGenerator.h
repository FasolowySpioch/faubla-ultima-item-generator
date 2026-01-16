#ifndef FULTIMA_GEN_QUALITYGENERATOR_H
#define FULTIMA_GEN_QUALITYGENERATOR_H

#include "../models/Quality.h"
#include "../models/Item.h"
#include <vector>
#include <string>
#include <random>
#include <memory>

class QualityGenerator
{
    std::vector<Quality> _cache_qualities;
    std::mt19937 _mt;

public:
    explicit QualityGenerator(const std::string& file_path);

    const Quality& generate();
    void applyRandomQualityTo(Item* item);
};


#endif //FULTIMA_GEN_QUALITYGENERATOR_H