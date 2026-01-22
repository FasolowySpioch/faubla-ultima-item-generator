#ifndef FULTIMA_GEN_QUALITYGENERATOR_H
#define FULTIMA_GEN_QUALITYGENERATOR_H

#include "../models/Quality.h"
#include "../models/Item.h"
#include <vector>
#include <string>
#include <random>


class QualityGenerator
{
    std::vector<Quality> _cache_qualities;

public:
    explicit QualityGenerator(const QString& file_path);

    const Quality& generate();
    void applyRandomQualityTo(Item* item);
};


#endif //FULTIMA_GEN_QUALITYGENERATOR_H