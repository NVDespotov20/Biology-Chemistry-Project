#include "pchGame.hpp"
#include "ChasingRoom.hpp"


ChasingRoom::ChasingRoom()
{
	////make them smart and delete by themselve
	//player = std::make_shared<Player>();
	//teacher = std::make_shared<Teacher>();
	//

	////loads sprites of the moving people
	//player->LoadSprites(60);
	//teacher->LoadSprites();
}

ChasingRoom::ChasingRoom(int doors)
{
	//variables that we use to make everything responsive
	WIDTH = GetScreenWidth();
	HEIGHT = GetScreenHeight();

	//make them smart and delete by themselve
	player = std::make_shared<Player>();
	teacher = std::make_shared<Teacher>();
	inventory = InventorySystem::getInstantiation();
	items = Items::getInstantiation();
	dir = Navigator::getInstantiation();
	//loads sprites of the moving people
	player->LoadSprites(60);
	teacher->LoadSprites();
	this->doors = doors;
	loadMiniGame = 0;
	positionOfMiniGamePlace = { 0,0 };

	
}

ChasingRoom::~ChasingRoom()
{
	

}

void ChasingRoom::drawChasingRoom()
{
	//check if a map elemts have to draw mini game
	if (dir->j == 3 && dir->i == 0)
	{
		positionOfMiniGamePlace = { 1000, 200 };
		DrawCircleV(positionOfMiniGamePlace, 100, RED);

		if (CheckCollisionCircleRec(positionOfMiniGamePlace, 100, player->move) && IsKeyPressed(KEY_P))
		{
			splitElements = SplitElements::getInstantiation();
			loadMiniGame = true;
		}
	}
	if (dir->j == 1 && dir->i == 1)
	{
		inventory->isPickedUp(player->move, items->item, items->normalItemsPos);
		items->drawNormalItems();
		
	}
	//draw mini game
	if (loadMiniGame) {
		splitElements->drawAndMoveElementsAndHolders(loadMiniGame);
		if (player->checkerForMetals.size() == 4)
			splitElements->checkElements();
	}
	else
	{
		//update teacher
		teacher->update(player->playerCords, player->move);
		teacher->draw();

		//update player
		player->join();

		if (IsKeyDown(KEY_TAB))
			inventory->drawInventory(items->item);
		//check doors
		checkDoors();
	}
}


void ChasingRoom::checkDoors()
{
	switch (this->doors)
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
			stringDirHolder = player->isNearDoor(player->move);
			player->enterDoor(stringDirHolder);

		}break;
		case 2:
		{
			player->positionsOfDoors.erase("down");

			//draw and check if player is near door
			player->drawDoors();
			stringDirHolder = player->isNearDoor(player->move);
			player->enterDoor(stringDirHolder);
		}break;
		case 3:
		{
			//draw and check if player is near door
			player->drawDoors();
			stringDirHolder = player->isNearDoor(player->move);
			player->enterDoor(stringDirHolder);

		}break;
		case 4:
		{
			player->positionsOfDoors.insert({ "up", {GetScreenWidth() / 2.f, 0} });

			//draw and check if player is near door
			player->drawDoors();
			stringDirHolder = player->isNearDoor(player->move);
			player->enterDoor(stringDirHolder);

		}break;
	}
}

