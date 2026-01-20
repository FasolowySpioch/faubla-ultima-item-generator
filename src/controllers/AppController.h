#ifndef FULTIMA_GEN_APPCONTROLLER_H
#define FULTIMA_GEN_APPCONTROLLER_H

#include "../core/CampaignManager.h"
#include "../systems/ItemGeneratorSystem.h"
#include "../io/CampaignSerializer.h"

class AppController
{
    CampaignManager repository;
    ItemGeneratorSystem generator;

public:
    bool loadCampaign(const QString& file_path);    // (std::string_view) ??
    bool saveCampaign(const QString& file_path) const;
    static bool deleteCampaign(const QString& file_path);

    void savePlayer(std::unique_ptr<Player> player);
    void removePlayer(size_t idx);       // fingers crossed that it'll be as easy as passing the index from UI list/table
    void saveItem(std::unique_ptr<Item> item);
    void removeItem(size_t idx);
    void editPlayer(size_t idx, std::unique_ptr<Player> edited_player);
    void editItem(size_t idx, std::unique_ptr<Item> edited_item);

    [[nodiscard]] std::unique_ptr<Item> generateItem(ItemType type, const Player &player);
    [[nodiscard]] std::unique_ptr<Item> generateRandomItem(const Player &player);
    [[nodiscard]] std::unique_ptr<Item> generateItemForRandomPlayer();      // random player + random item
    void rerollQuality(Item *item);

    const std::vector<std::unique_ptr<Item>>& getItemsRepository() const;
    const std::vector<std::unique_ptr<Player>>& getPlayersRepository() const;
};


#endif //FULTIMA_GEN_APPCONTROLLER_H