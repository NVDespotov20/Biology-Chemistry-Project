#pragma once
#include "Player.hpp"
#include "Navigator.hpp"
class Shop
{
	std::shared_ptr<Player>player;
	std::shared_ptr<Navigator>dir;

	int door;

	Rectangle shopRec;
	Rectangle shopitemsRec[4];

	public:
	Shop(int door);
	Shop();
	~Shop();
	void drawShop();
	void checkShopDoors();
};

