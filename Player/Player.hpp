#pragma once
#include <Player/Enum.h>
class Player
{
public:
	Player(uint16_t ID);
	static void Add(uint16_t ID);
	static void Remove(uint16_t ID);
	static std::shared_ptr<Player> GetPlayer(uint16_t ID);

	const int16_t GetID() const;
	void Spawn();
	std::string GetName();
private:

	static std::unordered_map<uint16_t, std::shared_ptr<Player>> m_data;
	static std::unordered_map<PlayerData, int16_t> n_atribute;
};
