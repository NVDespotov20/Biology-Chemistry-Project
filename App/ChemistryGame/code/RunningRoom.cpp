#include "pchGame.hpp"
#include "RunningRoom.hpp"

RunningRoom::RunningRoom()
{
	//make them smart and delete by themselve
	player = std::make_shared<Player>();
	teacher = std::make_shared<Teacher>();
	//loads sprites of the moving people
	player->LoadSprites(60);
	teacher->LoadSprites();
}

RunningRoom::RunningRoom(int doors)
{
	//make them smart and delete by themselve
	player = std::make_shared<Player>();
	teacher = std::make_shared<Teacher>();
	dir = Direction::getInstantiation();
	//loads sprites of the moving people
	player->LoadSprites(60);
	teacher->LoadSprites();
	this->doors = doors;

}

RunningRoom::~RunningRoom()
{
	player->UnLoadTextures();
	//teacher->UnLoadTextures();

}

void RunningRoom::draw()
{

	teacher->update(player->playerCords, player->move);
	teacher->draw();
	//update player
	player->join();
	checkDoors();
}

void RunningRoom::checkDoors()
{
	switch (this->doors)
	{
		case 1:
		{
			//remove unneeded doors
			if (dir->j > 2){
				player->positionsOfDoors.erase("down");
				player->positionsOfDoors.erase("right");
			}
			else {
				player->positionsOfDoors.erase("down");
				player->positionsOfDoors.erase("left");
			}


			//draw and check if player is near door
			player->drawDoors();
			stringDirHolder = player->isNearDoor(player->move);
			player->enterDoor(stringDirHolder);
			break;
		}
		case 2:
		{
			player->positionsOfDoors.erase("down");

			//draw and check if player is near door
			player->drawDoors();
			stringDirHolder = player->isNearDoor(player->move);
			player->enterDoor(stringDirHolder);
			break;
		}
		case 3:
		{
			//draw and check if player is near door
			player->drawDoors();
			stringDirHolder = player->isNearDoor(player->move);
			player->enterDoor(stringDirHolder);
			break;
		}
		case 4:
		{
			player->positionsOfDoors.insert({ "up", {GetScreenWidth() / 2.f, 0} });

			//draw and check if player is near door
			player->drawDoors();
			stringDirHolder = player->isNearDoor(player->move);
			player->enterDoor(stringDirHolder);
			break;
		}
	}
}

