#ifndef FULTIMA_GEN_APPCONTROLLER_H
#define FULTIMA_GEN_APPCONTROLLER_H

#include <QString>

#include "../core/CampaignManager.h"
#include "../systems/ItemGeneratorSystem.h"

class AppController
{
    std::unique_ptr<CampaignManager> repository;
    std::unique_ptr<ItemGeneratorSystem> generator;

public:
    AppController();

    // void loadCampaign(const QString& file_path);    // add load/save feature
    // void saveCampaign(const QString& file_path);    // add load/save feature
    // void deleteCampaign(const QString& file_path);  // add load/save feature
    // void newCampaign();     // add load/save feature

    void savePlayer(std::unique_ptr<Player> player) const;
    void removePlayer(size_t idx) const;       // fingers crossed that it'll be as easy as passing the index from UI list/table
    void saveItem(std::unique_ptr<Item> item) const;
    void removeItem(size_t idx) const;
    void editPlayer(size_t idx, std::unique_ptr<Player> edited_player) const;
    void editItem(size_t idx, std::unique_ptr<Item> edited_item) const;

    [[nodiscard]] std::unique_ptr<Item> generateItem(ItemType type, const Player &player) const;
    [[nodiscard]] std::unique_ptr<Item> generateRandomItem(const Player &player) const;
    [[nodiscard]] std::unique_ptr<Item> generateItemForRandomPlayer() const;      // random player + random item
    void rerollQuality(Item *item) const;

};


#endif //FULTIMA_GEN_APPCONTROLLER_H