#include "QualityGenerator.h"
#include "../io/JsonReader.h"
#include <QRandomGenerator>


QualityGenerator::QualityGenerator(const QString &file_path)
{
    _cache_qualities = JsonReader::loadQualities(file_path);
}


const Quality& QualityGenerator::generate()
{
    if (_cache_qualities.empty())
    {
        static Quality emptyQ;
        return emptyQ;
    }

    const int idx = QRandomGenerator::global()->bounded(3);

    return _cache_qualities[idx];
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
