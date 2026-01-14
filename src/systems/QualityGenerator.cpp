#include "QualityGenerator.h"
#include "../io/JsonReader.h"

QualityGenerator::QualityGenerator(const std::string &file_path)
{
    // rng init
    std::random_device seed;
    _mt = std::mt19937(seed());

    // loading the file into cache
    JsonReader reader;
    _cache_qualities = JsonReader::loadQualities(QString::fromStdString(file_path));
}


const Quality& QualityGenerator::generate(ItemType type)
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

    if (legal_qualities.empty())
        return Quality();

    std::uniform_int_distribution<> dist(0, legal_qualities.size() - 1);

    return *legal_qualities[dist(_mt)];
}

void QualityGenerator::applyRandomQualityTo(const ItemType type, Item* item)
{
    if (!item) return;

    const Quality& q = generate(type);

    item->setDefaultDesc();
    item->setDefaultPrice();

    item->setDesc(q.desc);
    item->increasePriceBy(q.cost_add);
}
