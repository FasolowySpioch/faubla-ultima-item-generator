#ifndef FULTIMA_GEN_QUALITY_H
#define FULTIMA_GEN_QUALITY_H

#include <string>

struct Quality
{
    std::string desc;
    int cost_add;
    bool isOffensive;   // false == Defensive

    Quality() : cost_add(0), isOffensive(false) {}

    Quality(const std::string_view _desc, const int _cost_add, const bool _isOffensive)
        : desc(_desc)
        , cost_add(_cost_add)
        , isOffensive(_isOffensive)
    {}
};

#endif //FULTIMA_GEN_QUALITY_H