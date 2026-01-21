#ifndef FULTIMA_GEN_ISERIALIZABLE_H
#define FULTIMA_GEN_ISERIALIZABLE_H

#include <QJsonObject>


class IJsonSerializable
{
public:
    virtual ~IJsonSerializable() = default;

    virtual QJsonObject toJson() const = 0;
};


#endif //FULTIMA_GEN_ISERIALIZABLE_H