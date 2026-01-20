#include "AppController.h"

#include <QFile>


bool AppController::loadCampaign(const QString& file_path)
{
    repository.clear();
    return CampaignSerializer::load(repository, file_path);
}

bool AppController::saveCampaign(const QString& file_path) const
{
    return CampaignSerializer::save(repository, file_path);
}

bool AppController::deleteCampaign(const QString& file_path)
{
    return QFile::remove(file_path);
}


void AppController::savePlayer(std::unique_ptr<Player> player)
{
    repository.addPlayer(std::move(player));
}

void AppController::removePlayer(const size_t idx)
{
    repository.deletePlayer(idx);
}

void AppController::saveItem(std::unique_ptr<Item> item)
{
    repository.addItem(std::move(item));
}

void AppController::removeItem(const size_t idx)
{
    repository.deleteItem(idx);
}

void AppController::editPlayer(const size_t idx, std::unique_ptr<Player> edited_player)
{
    repository.replacePlayer(idx, std::move(edited_player));
}

void AppController::editItem(const size_t idx, std::unique_ptr<Item> edited_item)
{
    repository.replaceItem(idx, std::move(edited_item));
}


std::unique_ptr<Item> AppController::generateItem(const ItemType type, const Player &player)
{
    return generator.generateItem(type, player);
}

std::unique_ptr<Item> AppController::generateRandomItem(const Player &player)
{
    return generator.generateItem(ItemType::RANDOM, player);
}

std::unique_ptr<Item> AppController::generateItemForRandomPlayer()
{
    const Player random_pl = repository.getRandomPlayer();

    return generator.generateItem(ItemType::RANDOM, random_pl);
}

void AppController::rerollQuality(Item *item)
{
    generator.assignQuality(item->getItemType(), item);
}


const std::vector<std::unique_ptr<Item>>& AppController::getItemsRepository() const
{
    return repository.getItems();
}

const std::vector<std::unique_ptr<Player>>& AppController::getPlayersRepository() const
{
    return repository.getPlayers();
}
