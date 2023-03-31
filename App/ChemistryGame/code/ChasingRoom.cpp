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

ChasingRoom::ChasingRoom(int doors) : WIDTH(GetScreenWidth()), HEIGHT(GetScreenHeight()), doors(doors)
{
	//make them smart and delete by themselve
	player = std::make_shared<Player>();
	teacher = Teacher::getInstantiation();

	//singleton Instantiation
	inventory = InventorySystem::getInstantiation();
	money = Money::getInstantiation();
	items = Items::getInstantiation();
	dir = Navigator::getInstantiation();
	checkValency = CheckValency::getInstantiation();

	//loads sprites of the moving people
	player->LoadSprites(60);
	teacher->LoadSprites();

	stringsBackgroundName = {
		"../assets/images/chemistry/SpawnRoom.png",
		"../assets/images/chemistry/RoomOne.png",
		"../assets/images/chemistry/RoomTwo.png",
		"../assets/images/chemistry/RoomThree.png"
	};

	loadMiniGame = 0;
	miniGamePlayed = false;
	positionOfMiniGamePlace = { 0,0 };
}

ChasingRoom::~ChasingRoom()
{


}

void ChasingRoom::drawChasingRoom()
{

	money->drawMoney();
	
	//check if a map elemts have to draw mini game
	if (dir->j == 3 && dir->i == 0)
	{
		//right up
		positionOfMiniGamePlace = { 1000, 200 };
		DrawCircleV(positionOfMiniGamePlace, 100, RED);

		if (CheckCollisionCircleRec(positionOfMiniGamePlace, 100, player->move) && IsKeyPressed(KEY_P) && !miniGamePlayed)
		{
			splitElements = SplitElements::getInstantiation();
			loadMiniGame = true;
		}
	}
	//also for right
	if (loadMiniGame)
	{
		drawMiniGame();
		return;
	}

	//left down
	if (dir->j == 1 && dir->i == 1)
	{
		inventory->isPickedUp(player->move, items->item, items->normalItemsPos);
		items->drawNormalItems();
	}
	//update teacher
	teacher->update(player->playerCords, player->move);
	teacher->draw();

	//update player
	player->joinInRoom();

	if (IsKeyDown(KEY_TAB))
		inventory->drawInventory(items->item);
	//check doors
	checkDoors();
}

void ChasingRoom::drawMiniGame()
{
	//splitElements->drawAndMoveElementsAndHolders(loadMiniGame);

	checkValency->drawAndCheckElementsAndHolders();

	//if (splitElements->checkerForMetals.size() != 4 or splitElements->nonmetalsHolders.size() != 4)
	//{
	//miniGamePlayed = false;
	//return;
	//}
	//miniGamePlayed = true;
	//bool tmp = splitElements->checkElements();
	//if (tmp) money->addMoney();
	//teacher->setActive(!tmp);
	//loadMiniGame = false;
}




void ChasingRoom::checkDoors()
{
	switch (this->doors)
	{
	case 1:
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

	break;

	case 2:
	
		player->positionsOfDoors.erase("down");

		//draw and check if player is near door
		player->drawDoors();
		stringDirHolder = player->isNearDoor(player->move);
		player->enterDoor(stringDirHolder);

	break;

	case 3:
	
		//draw and check if player is near door
		player->drawDoors();
		stringDirHolder = player->isNearDoor(player->move);
		player->enterDoor(stringDirHolder);

	break;

	case 4:
	
		player->positionsOfDoors.insert({ "up", {GetScreenWidth() / 2.f, 0} });

		//draw and check if player is near door
		player->drawDoors();
		stringDirHolder = player->isNearDoor(player->move);
		player->enterDoor(stringDirHolder);

	break;
	}
}
