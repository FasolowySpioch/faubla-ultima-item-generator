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


const Quality& QualityGenerator::generate()
{
    if (_cache_qualities.empty())
        return Quality();

    std::uniform_int_distribution<> dist(0, _cache_qualities.size() - 1);

    return _cache_qualities[dist(_mt)];
}

void QualityGenerator::applyRandomQualityTo(Item* item)
{
    if (!item) return;

    const Quality& q = generate();

    item->setDefaultDesc();
    item->setDefaultPrice();

    item->setDesc(q.desc);
    item->increasePriceBy(q.cost_add);
}
