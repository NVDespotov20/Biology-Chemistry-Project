#include "pchGame.hpp"
#include "Magazine.hpp"

Magazine::Magazine()
{
}
Magazine::Magazine(int door)
{
	this->door = door;
	player = std::make_shared<Player>();
	dir = Direction::getInstantiation();
	player->LoadSprites(60);
}
Magazine::~Magazine()
{
	player->UnLoadTextures();
}

void Magazine::drawMagazine()
{
	player->join();
	checkMagazineDoors();
}

void Magazine::checkMagazineDoors()
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