#include "CampaignManager.h"

#include <stdexcept>


CampaignManager::CampaignManager()
{
    // rng init
    std::random_device seed;
    mt = std::mt19937(seed());
}


void CampaignManager::clear()
{
    _items.clear();
    _players.clear();
}

// ==== Items methods ====

void CampaignManager::addItem(std::unique_ptr<Item> item)
{
    _items.push_back(std::move(item));
}

void CampaignManager::deleteItem(const size_t idx)
{
    if (idx >= _items.size())
        throw std::out_of_range("CampaignManager::deleteItem: index out of range");

    _items.erase(_items.begin() + idx);
}

void CampaignManager::deleteAllItems()
{
    _items.clear();
}

Item& CampaignManager::getItem(const size_t idx) const
{
    if (idx >= _items.size())
        throw std::out_of_range("CampaignManager::getItem: index out of range");

    const auto &ptr = _items.at(idx);
    if (!ptr)
        throw std::runtime_error("CampaignManager::getItem: null unique_ptr at idx" + std::to_string(idx));

    return *ptr;
}

const std::vector<std::unique_ptr<Item>>& CampaignManager::getItems() const
{
    return _items;
}

void CampaignManager::replaceItem(const size_t idx, std::unique_ptr<Item> item)
{
    if (!item)
        throw std::invalid_argument("CampaignManager::replaceItem: Invalid address to item.");
    if (idx >= _items.size())
        throw std::out_of_range("CampaignManager::replaceItem: index out of range");

    _items.at(idx) = std::move(item);
}


// ==== Players methods ====

void CampaignManager::addPlayer(std::unique_ptr<Player> player)
{
    _players.push_back(std::move(player));
}

void CampaignManager::deletePlayer(const size_t idx)
{
    if (idx >= _players.size())
        throw std::out_of_range("CampaignManager::deletePlayer: index out of range");

    _players.erase(_players.begin() + idx);
}

void CampaignManager::deleteAllPlayers()
{
    _players.clear();
}

Player& CampaignManager::getPlayer(const size_t idx) const
{
    if (idx >= _players.size())
        throw std::out_of_range("CampaignManager::getPlayer: index out of range");

    const auto& ptr = _players.at(idx);
    if (!ptr)
        throw std::runtime_error("CampaignManager::getPlayer: null unique_ptr at idx" + std::to_string(idx));

    return *ptr;
}

const Player& CampaignManager::getRandomPlayer()
{
    const int random_idx = std::uniform_int_distribution<>(0, _players.size()-1)(mt);

    return *_players[random_idx].get();
}

const std::vector<std::unique_ptr<Player>>& CampaignManager::getPlayers() const
{
    return _players;
}

void CampaignManager::replacePlayer(const size_t idx, std::unique_ptr<Player> player)
{
    if (!player)
        throw std::invalid_argument("CampaignManager::replacePlayer: Invalid address to player.");
    if (idx >= _players.size())
        throw std::out_of_range("CampaignManager::replacePlayer: index out of range");

    _players.at(idx) = std::move(player);
}