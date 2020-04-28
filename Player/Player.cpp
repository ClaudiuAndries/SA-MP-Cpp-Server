#include <stdafx.h>
#include <Player/Player.hpp>

Player::Player(uint16_t ID)
{
	char name[MAX_PLAYER_NAME];
	sampgdk::GetPlayerName(ID, name, sizeof(name));
	char message[MAX_CLIENT_MESSAGE];
	sprintf(message, "Hello %s!", name);
	sampgdk::SendClientMessage(ID, -1, message);

	n_atribute.emplace(PlayerData::ID, ID);

}

void Player::Add(uint16_t ID)
{
	m_data.emplace(ID, std::make_shared<Player>(ID));
}

void Player::Remove(uint16_t ID)
{
	m_data.erase(ID);
}

std::shared_ptr<Player> Player::GetPlayer(uint16_t ID)
{
	return m_data.at(ID);
}

const int16_t Player::GetID() const
{
	return static_cast<uint16_t>(PlayerData::ID);
}



void Player::Spawn()
{
	sampgdk::SpawnPlayer(n_atribute.at(PlayerData::ID));
}

std::string Player::GetName()
{
	char name[MAX_PLAYER_NAME];
	sampgdk::GetPlayerName(n_atribute.at(PlayerData::ID), name, sizeof(name));
	return name;
}


std::unordered_map<uint16_t, std::shared_ptr<Player>> Player::m_data;
std::unordered_map<PlayerData, int16_t> Player::n_atribute;