#pragma once
#include <Dialog/Enum.hpp>
#include <Dialog/Dialog.hpp>
#include <Player/Player.hpp>
class Player;

class Dialogs : public Dialog, public Singleton<Dialogs>
{
public:

	void Create(std::shared_ptr<Player> Player, const DialogID& ID, const DialogStyle& style, const std::string& text, const std::string& infotxt, const std::string& button1, const std::string& button2)
	{
		//sampgdk::ShowPlayerDialog(Player, static_cast<uint16_t>(ID), text.c_str(), "", button1.c_str(), button2.c_str());
		sampgdk::ShowPlayerDialog(Player->GetID(), static_cast<uint16_t>(ID), static_cast<uint16_t>(style), text.c_str(), infotxt.c_str(), button1.c_str(), button2.c_str());
	}
	template <typename ...Args>
	void Create(std::shared_ptr<Player> Player, const DialogID& ID, const DialogStyle& style, const std::string& text,  const std::string& infos, const std::string& button1, const std::string& button2)
	{
		sampgdk::ShowPlayerDialog(Player->GetID(), static_cast<uint16_t>(ID), static_cast<uint16_t>(style),text.c_str(), infos.c_str(), button1.c_str(), button2.c_str());
	}

	void Execute(std::shared_ptr<Player> Player, const DialogID& ID, int Response);
private:
	std::string info;
};

