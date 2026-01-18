#include "AppController.h"

AppController::AppController()
    : repository(std::make_unique<CampaignManager>())
    , generator(std::make_unique<ItemGeneratorSystem>())
{}

void AppController::savePlayer(std::unique_ptr<Player> player) const
{
    repository->addPlayer(std::move(player));
}

void AppController::removePlayer(const size_t idx) const
{
    repository->deletePlayer(idx);
}

void AppController::saveItem(std::unique_ptr<Item> item) const
{
    repository->addItem(std::move(item));
}

void AppController::removeItem(const size_t idx) const
{
    repository->deleteItem(idx);
}

void AppController::editPlayer(const size_t idx, std::unique_ptr<Player> edited_player) const
{
    repository->replacePlayer(idx, std::move(edited_player));
}

void AppController::editItem(const size_t idx, std::unique_ptr<Item> edited_item) const
{
    repository->replaceItem(idx, std::move(edited_item));
}

std::unique_ptr<Item> AppController::generateItem(const ItemType type, const Player &player) const
{
    return generator->generateItem(type, player);
}

std::unique_ptr<Item> AppController::generateRandomItem(const Player &player) const
{
    return generator->generateItem(ItemType::RANDOM, player);
}

std::unique_ptr<Item> AppController::generateItemForRandomPlayer() const
{
    const Player random_pl = repository->getRandomPlayer();

    return generator->generateItem(ItemType::RANDOM, random_pl);
}

void AppController::rerollQuality(Item *item) const
{
    generator->assignQuality(item->getItemType(), item);
}
