#pragma once
#include <Dialog/Enum.hpp>

class Dialog
{
public:

	inline  DialogID GetDialogID() 
	{
		return ID;
	}

	inline const DialogStyle GetDialogStyle() const
	{
		return Style;
	}

	inline const std::string GetDialogTitle() const
	{
		return caption;
	}

	inline const std::string GetDialogInfo() const
	{
		return info;
	}

	inline const std::string GetFirstButton() const
	{
		return button1;
	}
	inline const std::string GetSecondButton() const
	{
		return button2;
	}
protected:
	//dialogid, style, caption[], info[], button1[], button2[])
	DialogID ID;
	DialogStyle Style;
	std::string caption;
	std::string info;
	std::string button1;
	std::string button2;
};
