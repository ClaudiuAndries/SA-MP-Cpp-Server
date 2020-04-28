#include <stdafx.h>
#include <Player/Player.hpp>
#include <Dialog/Dialogs.hpp>
#include <KeyStatement/KeyStatement.hpp>

using sampgdk::logprintf;


void SAMPGDK_CALL PrintTickCountTimer(int timerid, void* params) {
        logprintf("Tick count: %d", GetTickCount());
}

void Connection()
{
        MYSQL* mysql = mysql_init(nullptr);
        if (!mysql_real_connect(mysql, "localhost", "root", "", "test", 0, NULL, 0))
        {
                logprintf("Failed to connect to database: Error: %s\n", mysql_error(mysql));
        }
        else
        {
                logprintf("Connection succes!");
        }
        //CreateObject(186, 480.89099, -1498.52380, 20.47701,   90.00000, 0.00000, 96.18013);
     
}

PLUGIN_EXPORT bool PLUGIN_CALL OnGameModeInit()
{
        Connection();
        sampgdk::SetGameModeText("C++!");
        sampgdk::AddPlayerClass(0, 1958.3783f, 1343.1572f, 15.3746f, 269.1425f, 0, 0, 0, 0, 0, 0);
        sampgdk::SetTimer(1000, true, PrintTickCountTimer, 0);
        return true;
}

PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerConnect(int playerid) 
{
        Player::Add(playerid);
        sampgdk::SendClientMessage(playerid, 0xFFFFFFFF, "Welcome to the HelloWorld server!");
       
        return true;
}


PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerDisconnect(int playerid, int reason)
{
        return true;
}
PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerRequestClass(int playerid, int classid) 
{
        sampgdk::SetPlayerPos(playerid, 1958.3783f, 1343.1572f, 15.3746f);
        sampgdk::SetPlayerCameraPos(playerid, 1958.3783f, 1343.1572f, 15.3746f);
        sampgdk::SetPlayerCameraLookAt(playerid, 1958.3783f, 1343.1572f, 15.3746f, CAMERA_CUT);
        return true;
}

PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerCommandText(int playerid, const char* cmdtext) 
{
        if (strcmp(cmdtext, "/hello") == 0) 
        {
                char name[MAX_PLAYER_NAME];
                sampgdk::GetPlayerName(playerid, name, sizeof(name));
                char message[MAX_CLIENT_MESSAGE];
                sprintf(message, "Hello %s!", name);
                sampgdk::SendClientMessage(playerid, 0x00FF00FF, message);
                return true;
        }

        if (strcmp(cmdtext, "/spawn") == 0)
        {
                auto Player = Player::GetPlayer(playerid);
                Player->Spawn();
                return true;
        }

        if (strcmp(cmdtext, "/dialog") == 0)
        {
                auto Player = Player::GetPlayer(playerid);
                //sampgdk::ShowPlayerDialog(playerid, static_cast<int>(DialogID::Register), static_cast<int>(DialogStyle::Message), "Hello", "Test", "OK", "cancel");
                Dialogs::GetInstance()->Create(Player, DialogID::Login, DialogStyle::Text, "Hello", "Buna ziua !", "Ok", "Cancel");
                return true;
        }
        return false;
}

PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerSpawn(int PlayerID)
{
        return false;
}


PLUGIN_EXPORT bool PLUGIN_CALL OnDialogResponse(int PlayerID, int Dialog, int Response, int ListItem, const char* InputText)
{
        auto Player = Player::GetPlayer(PlayerID);
        Dialogs::GetInstance()->Execute(Player, static_cast<DialogID>(Dialog), Response);
        return false;
}

PLUGIN_EXPORT bool PLUGIN_CALL  OnPlayerKeyStateChange(int PlayerID, int NewKeys, int OldKeys)
{
      
        auto Player = Player::GetPlayer(PlayerID);
        KeyStatement::GetInstance()->Execute(Player, NewKeys);
        return false;
}

PLUGIN_EXPORT unsigned int PLUGIN_CALL Supports() 
{
        return sampgdk::Supports() | SUPPORTS_PROCESS_TICK;
}

PLUGIN_EXPORT bool PLUGIN_CALL Load(void** ppData)
{
        return sampgdk::Load(ppData);
}

PLUGIN_EXPORT void PLUGIN_CALL Unload() 
{
        sampgdk::Unload();
}

PLUGIN_EXPORT void PLUGIN_CALL ProcessTick() {
        sampgdk::ProcessTick();
}