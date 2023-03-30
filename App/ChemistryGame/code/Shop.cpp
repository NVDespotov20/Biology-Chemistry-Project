#include "pchGame.hpp"
#include "Shop.hpp"

Shop::Shop()
{

}

Shop::Shop(int door)
{
	this->door = door;
	player = std::make_shared<Player>();
	dir = Navigator::getInstantiation();
	player->LoadSprites(60);
}

Shop::~Shop()
{
	player->UnLoadTextures();
}

void Shop::drawShop()
{
	//player->join();
	checkShopDoors();
}

void Shop::checkShopDoors()
{
	switch (door)
	{
		case 1:
		{
			//remove unneeded doors
			if (dir->j > 2) {
				player->positionsOfDoors.erase("down");
				player->positionsOfDoors.erase("right");
			}
			else {
				player->positionsOfDoors.erase("down");
				player->positionsOfDoors.erase("left");
			}


			//draw and check if player is near door
			player->drawDoors();
			std::string stringDirHolder = player->isNearDoor(player->move);
			player->enterDoor(stringDirHolder);
		}
	}
}