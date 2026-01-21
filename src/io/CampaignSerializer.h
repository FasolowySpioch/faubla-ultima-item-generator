#ifndef FULTIMA_GEN_CAMPAIGNSERIALIZER_H
#define FULTIMA_GEN_CAMPAIGNSERIALIZER_H

#include "../core/CampaignManager.h"
#include <QString>


class CampaignSerializer
{
    static std::unique_ptr<Player> playerFromJson(QJsonObject json_player);
    static std::unique_ptr<Item> itemFromJson(QJsonObject json_item);

public:
    static bool save(const CampaignManager &mng, const QString &file_path);
    static bool load(CampaignManager &mng, const QString &file_path);
};


#endif //FULTIMA_GEN_CAMPAIGNSERIALIZER_H