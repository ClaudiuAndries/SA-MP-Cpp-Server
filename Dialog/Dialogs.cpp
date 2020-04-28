#include <stdafx.h>
#include <Dialog/Dialog.hpp>
#include <Dialog/Dialogs.hpp>



void Dialogs::Execute(std::shared_ptr<Player> Player, const DialogID& ID, int Response)
{
	auto player = Player->GetID();
	switch (ID)
	{
		case Login:
		{
			sampgdk::SendClientMessage(player, -1, "Dialog login!");
		}
	}
	
}
