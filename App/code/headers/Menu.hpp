#pragma once
#include<raylib.h>
class Menu
{
public:
	Menu();
	~Menu();
	void loop();
	static Menu* getInstantiation();
private:
	static Menu* instantiate_;
	void unload();
	void load();
	Texture2D menuBackground;
	Rectangle menuBackgroundRec;

	
};

