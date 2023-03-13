#pragma once
#include<raylib.h>
#include<Menu.hpp>
#include<Options.hpp>
#include<App.hpp>
class AppManager
{
public:
	enum Direction
	{
		MENU,
		APP,
		OPTIONS,
		QUIT
	}dir;
	~AppManager();
	void manage();
	void loop();
	static AppManager* getInstantiation();
private:
	static AppManager* instantiate_;
	AppManager();
};

