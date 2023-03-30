#pragma once
#include "Game.hpp"
#include "Menu.hpp"
#include "Navigator.hpp"
class GameManager
{
private:
	std::shared_ptr<Game> game;
	std::shared_ptr<Menu> menu;
	bool shouldQuit;
public:
	GameManager();
	~GameManager();
	void start();
	bool manageGame();
};
