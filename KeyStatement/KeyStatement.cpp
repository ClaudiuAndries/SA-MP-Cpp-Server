#include <stdafx.h>
#include <Player/Player.hpp>
#include <KeyStatement/KeyStatement.hpp>

void KeyStatement::Execute(std::shared_ptr<Player> Player, int Key)
{
	auto Playerid = Player->GetID();
	switch (Key)
	{
		case KEY_FIRE:
		{
			sampgdk::SendClientMessage(Playerid, -1, "KeyFire");
			break;
		}
		case KEY_CROUCH:
		{
			sampgdk::SendClientMessage(Playerid, -1, "KEY_CROUCH");
			break;
		}
		case KEY_ACTION:
		{
			sampgdk::SendClientMessage(Playerid, -1, "KEY_ACTION");
			break;
		}
	}
}
