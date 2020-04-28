#pragma once

enum DialogID : uint8_t
{
	Register = 0,
	Login,
	Sex,
	Age
};

enum DialogStyle : uint8_t
{
	Message = 0,	//DIALOG_STYLE_MSGBOX = 0,
	Text,		//DIALOG_STYLE_INPUT,
	List,		//DIALOG_STYLE_LIST,
	Password,	//DIALOG_STYLE_PASSWORD,
	Tablist,	//DIALOG_STYLE_TABLIST,
	TablistH	//DIALOG_STYLE_TABLIST_HEADERS,
};