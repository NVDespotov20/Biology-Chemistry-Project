#include "pchGame.hpp"
#include "ChasingRoom.hpp"


ChasingRoom::ChasingRoom()
{
	////make them smart and delete by themselve
	//player = std::make_shared<Player>();
	//teacher = std::make_shared<Teacher>();
	

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

	//loads sprites of the moving people
	player->LoadSprites(60);
	teacher->LoadSprites();

	stringsBackgroundName = {
		"SpawnRoom",
		"RoomOne",
		"RoomTwo",
		"RoomThree"
	};
	
	for (int i = 0; i < 4; i++)
	{
		stringsBackgroundName.at(i) = "../assets/image/chemistry/Rooms/"+ stringsBackgroundName.at(i) + ".png";
	}

	loadSplitElementsMiniGame = 0;
	loadCheckValencyMiniGame = 0;
	miniGameSplitElementsPlayed = false;
	miniGameCheckValencyPlayed = false;
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

		if (CheckCollisionCircleRec(positionOfMiniGamePlace, 100, player->move) && IsKeyPressed(KEY_P) && !miniGameCheckValencyPlayed)
		{
			checkValency = CheckValency::getInstantiation();
			loadCheckValencyMiniGame = true;
		}
	}

	if (dir->j == 2 && dir->i == 0)
	{
		//right bot
	}

	if (dir->j == 2 && dir->i == 1)
	{
		//center bot
		positionOfMiniGamePlace = { 1000, 600 };
		DrawCircleV(positionOfMiniGamePlace, 100, ORANGE);

		if (CheckCollisionCircleRec(positionOfMiniGamePlace, 100, player->move) && IsKeyPressed(KEY_P) && !miniGameSplitElementsPlayed)
		{
			splitElements = SplitElements::getInstantiation();
			loadSplitElementsMiniGame = true;
		}
	}

	//also for right
	if (loadCheckValencyMiniGame)
	{
		drawCheckValencyMiniGame();
		return;
	}

	if (loadSplitElementsMiniGame)
	{
		drawSplitElementsMiniGame();
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

void ChasingRoom::drawCheckValencyMiniGame()
{ 
	DrawTexture(background,0,0,WHITE); 
	
	checkValency->drawAndCheckElementsAndHolders(loadCheckValencyMiniGame);

	if (checkValency->givenAnswers.size() != 3)
	{
	miniGameCheckValencyPlayed = false;
	return;
	}
	miniGameCheckValencyPlayed = true;

	bool tmp = checkValency->checkAccuracy();
	if (tmp)
	{
		teacher->setActive(!tmp);
	}
	else
	{
		money->addMoney();
	}
	loadCheckValencyMiniGame = false;
}

void ChasingRoom::drawSplitElementsMiniGame()
{
	splitElements->drawAndMoveElementsAndHolders(loadSplitElementsMiniGame);


	if (splitElements->checkerForMetals.size() != 4 or splitElements->nonmetalsHolders.size() != 4)
	{
	miniGameSplitElementsPlayed = false;
	return;
	}
	miniGameSplitElementsPlayed = true;
	bool tmp = splitElements->checkElements();
	if (tmp) money->addMoney();
	teacher->setActive(!tmp);
	loadSplitElementsMiniGame = false;
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
