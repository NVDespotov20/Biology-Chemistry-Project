#pragma once
#include "Player.hpp"
class Shop
{
	std::shared_ptr<Player>player;
	std::shared_ptr<Direction>dir;
	int door;
	public:
	Shop(int door);
	Shop();
	~Shop();
	void drawShop();
	void checkShopDoors();
};

