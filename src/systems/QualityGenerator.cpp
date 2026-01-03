#include "QualityGenerator.h"
#include "../io/JsonReader.h"

QualityGenerator::QualityGenerator(const std::string &file_path)
{
    // rng init
    std::random_device seed;
    _mt = std::mt19937(seed());

    // loading the file into cache
    JsonReader reader;
    _cache_qualities = reader.loadQualities(QString::fromStdString(file_path));
}


const Quality& QualityGenerator::generateRandomQuality(ItemType type)
{
    std::vector<const Quality*> legal_qualities;

    if (type == ItemType::WEAPON)
    {
        for (const Quality& quality : _cache_qualities)
        {
            if (quality.isOffensive)
                legal_qualities.push_back(&quality);
        }
    }
    else
    {
        for (const Quality& quality : _cache_qualities)
                legal_qualities.push_back(&quality);
    }

    std::uniform_int_distribution<> dist(0, legal_qualities.size() - 1);

    return *legal_qualities[dist(_mt)];
}
