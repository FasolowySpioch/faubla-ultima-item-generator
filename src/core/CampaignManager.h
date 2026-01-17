#ifndef FULTIMA_GEN_CAMPAIGNMANAGER_H
#define FULTIMA_GEN_CAMPAIGNMANAGER_H

#include "../models/Player.h"
#include "../models/Item.h"
#include <vector>
#include <memory>

class CampaignManager
{
     std::vector<std::unique_ptr<Item>> _items;
     std::vector<std::unique_ptr<Player>> _players;

public:
     CampaignManager() = default;
     ~CampaignManager() = default;

     // ==== Items methods ====

     void addItem(std::unique_ptr<Item> item);
     // void deleteItem(Item* item);
     void deleteItem(size_t idx);
     void deleteAllItems();
     Item& getItem(size_t idx) const;
     const std::vector<std::unique_ptr<Item>>& getItems() const;
     void replaceItem(size_t idx, std::unique_ptr<Item> item);

     // ==== Players methods ====

     void addPlayer(std::unique_ptr<Player> player);
     // void deletePlayer(Player* player);
     void deletePlayer(size_t idx);
     void deleteAllPlayers();
     Player& getPlayer(size_t idx) const;
     const std::vector<std::unique_ptr<Player>>& getPlayers() const;
     void replacePlayer(size_t idx, std::unique_ptr<Player> player);
};


#endif //FULTIMA_GEN_CAMPAIGNMANAGER_H