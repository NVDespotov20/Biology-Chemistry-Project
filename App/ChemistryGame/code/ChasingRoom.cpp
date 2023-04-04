#include "pchGame.hpp"
#include "ChasingRoom.hpp"

ChasingRoom::ChasingRoom()
{

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

	tableBackground = LoadTexture("../assets/images/chemistry/Objects/TableBackground.png");
	tableBackground.width = GetScreenWidth();
	tableBackground.height = GetScreenHeight();

	stringsBackgroundName = {
		"SpawnRoom",
		"RoomOne",
		"RoomTwo",
		"RoomThree"
	};

	points = {
		{ WIDTH / 2, 100 },
		{ WIDTH / 2 + 50, 150 },
		{ WIDTH / 2 + 25, 225 },
		{ WIDTH / 2 - 25, 225 },
		{ WIDTH / 2 - 50, 150 },
		{ WIDTH / 2 - 20, 125 },
		{ WIDTH / 2 + 20, 125 }
	};

	rightArrow = LoadTexture("../assets/images/UI Elements/RightArrow.png");
	rightArrow.width = 350;
	rightArrow.height = 200;

	seed = std::chrono::steady_clock::now().time_since_epoch().count();

	//generator of new random number with the seed
	gen.seed(seed);

	//std::shuffle(elementsTexturesStrings.begin(), elementsTexturesStrings.end(), gen);

	std::shuffle(stringsBackgroundName.begin(), stringsBackgroundName.end(), gen);

	menuButton = { 0, 20, HEIGHT / 7.f, HEIGHT / 20.f };

	loadSplitElementsMiniGame = 0;
	loadCheckValencyMiniGame = 0;
	miniGameSplitElementsPlayed = false;
	miniGameCheckValencyPlayed = false;
	positionOfMiniGamePlace = { 0,0 };
}

ChasingRoom::~ChasingRoom()
{
	unload();
}

void ChasingRoom::load()
{
	//load
	table = LoadTexture("../assets/images/chemistry/Objects/Table.png");
	table.width = 200;
	table.height = 200;

	leftDoor = LoadTexture("../assets/images/chemistry/Objects/DoorLeft.png");
	leftDoor.width = 200;
	leftDoor.height = 200;

	rightDoor = LoadTexture("../assets/images/chemistry/Objects/DoorRight.png");
	rightDoor.width = 200;
	rightDoor.height = 200;

	downDoor = LoadTexture("../assets/images/chemistry/Objects/DoorDown.png");
	downDoor.width = 200;
	downDoor.height = 200;

	upDoor = LoadTexture("../assets/images/chemistry/Objects/DoorUp.png");
	upDoor.width = 200;
	upDoor.height = 200;

	doorsPositons[0].x = 25;
	doorsPositons[0].y = 450;

	doorsPositons[1].x = 1690;
	doorsPositons[1].y = 450;

	doorsPositons[2].x = 850;
	doorsPositons[2].y = 30;

	doorsPositons[3].x = 850;
	doorsPositons[3].y = 855;

	spawnPointBackground = LoadTexture("../assets/images/chemistry/Rooms/SpawnRoom.png");
	spawnPointBackground.width = GetScreenWidth();
	spawnPointBackground.height = GetScreenHeight();
	teacher->LoadSprites();
	player->LoadSprites(60);

	for (int i = 0; i < 4; i++)
	{
		stringsBackgroundName.at(i) = "../assets/images/chemistry/Rooms/" + stringsBackgroundName.at(i) + ".png";
	}

	for (int i = 0; i < 4; i++)
	{
		if (stringsBackgroundName.at(i) != "../assets/images/chemistry/Rooms/SpawnRoom.png")
		{
			texturesBackgrounds.push_back(LoadTexture(stringsBackgroundName.at(i).c_str()));
			texturesBackgrounds.push_back(LoadTexture(stringsBackgroundName.at(i).c_str()));
			texturesBackgrounds.push_back(LoadTexture(stringsBackgroundName.at(i).c_str()));
		}
	}

	std::shuffle(texturesBackgrounds.begin(), texturesBackgrounds.end(), gen);
	for (int i = 0; i < 6; i++)
	{
		texturesBackgrounds.at(i).width = WIDTH;
		texturesBackgrounds.at(i).height = HEIGHT;
	}

	inventory->load();
	items->load();

}

void ChasingRoom::drawChasingRoom()
{
	
	//check if a map elemts have to draw mini game
	if (dir->j == 3 && dir->i == 0)
	{
		//right up
		DrawTexture(texturesBackgrounds.at(0),0,0,WHITE);
		DrawTexture(leftDoor, doorsPositons[0].x, doorsPositons[0].y, WHITE);
		positionOfMiniGamePlace = { 1600, 200 };
		DrawCircleV(positionOfMiniGamePlace, 100, BLANK);
		DrawTexture(table, 1480, 100, WHITE);
		if (CheckCollisionCircleRec(positionOfMiniGamePlace, 100, player->move) && IsKeyPressed(KEY_P) && !miniGameSplitElementsPlayed)
		{
			splitElements = SplitElements::getInstantiation();
			loadSplitElementsMiniGame = true;
		}
	}

	if (dir->j == 2 && dir->i == 0)
	{
		//center top
		DrawTexture(spawnPointBackground,0,0,WHITE);
		DrawTexture(leftDoor, doorsPositons[0].x, doorsPositons[0].y, WHITE);
		DrawTexture(rightDoor, doorsPositons[1].x, doorsPositons[1].y, WHITE);
		DrawTexture(downDoor, doorsPositons[3].x, doorsPositons[3].y, WHITE);
	}

	if (dir->j == 2 && dir->i == 1)
	{
		DrawTexture(texturesBackgrounds.at(1), 0, 0, WHITE);
		DrawTexture(leftDoor, doorsPositons[0].x, doorsPositons[0].y, WHITE);
		DrawTexture(rightDoor, doorsPositons[1].x, doorsPositons[1].y, WHITE);
		DrawTexture(upDoor, doorsPositons[2].x, doorsPositons[2].y, WHITE);
		DrawTexture(downDoor, doorsPositons[3].x, doorsPositons[3].y, WHITE);
		//center bot
		positionOfMiniGamePlace = { 1600, 225 };
		DrawCircleV(positionOfMiniGamePlace, 100, BLANK);
		DrawTexture(table, 1480, 100, WHITE);
		if (CheckCollisionCircleRec(positionOfMiniGamePlace, 100, player->move) && IsKeyPressed(KEY_P) && !miniGameCheckValencyPlayed)
		{
			checkValency = CheckValency::getInstantiation();
			loadCheckValencyMiniGame = true;
		}
	}
	if (dir->j == 1 && dir->i == 0)
	{
		//left top or bio room
		positionOfMiniGamePlace = { 325, 800 };
		DrawTexture(texturesBackgrounds.at(2), 0, 0, WHITE);
		DrawCircleV(positionOfMiniGamePlace, 100, PINK);
		DrawTexture(table, 200, 650, WHITE);
	}

	//also for right
	if (loadCheckValencyMiniGame)
	{
		drawCheckValencyMiniGame();
		return;
	}

	if (dir->j == 3 && dir->i == 1)
	{//bot right
		DrawTexture(texturesBackgrounds.at(3), 0, 0, WHITE);
		DrawTexture(leftDoor, doorsPositons[0].x, doorsPositons[0].y, WHITE);
		//fyre
	}

	if (dir->j == 1 && dir->i == 1)
	{//bot left
		positionOfMiniGamePlace = { 300, 200 };
		DrawTexture(texturesBackgrounds.at(4), 0, 0, WHITE);
		DrawTexture(rightDoor, doorsPositons[1].x, doorsPositons[1].y, WHITE);
		DrawCircleV(positionOfMiniGamePlace, 100, BLANK);
		DrawTexture(table, 170, 100, WHITE);

		if (IsKeyPressed(KEY_P) && CheckCollisionCircleRec(positionOfMiniGamePlace, 100, player->move) && inventory->itemsInInventoryPos.size() == 4)
		{
			money->addMoney();
			for (int i = 0; i < 4; i++)
			{
				inventory->itemsInInventoryPos.pop_back();
			}
		}
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
		DrawTexture(rightDoor, doorsPositons[1].x, doorsPositons[1].y, WHITE);
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

	DrawRectangleRounded(menuButton, 0.5 ,0, RED);
	DrawText("Menu", 32.5, 30, HEIGHT /36,BLACK);
	DrawRectangle(160,20,50,55,DARKGRAY);
	money->drawMoney();
	checkDoors();
	
}

void ChasingRoom::drawCheckValencyMiniGame()
{ 
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

void ChasingRoom::unload()
{
	for (int i = 0; i < 4; i++)
	{
		UnloadTexture(texturesBackgrounds[i]);
	}
	
	UnloadTexture(spawnPointBackground);
	UnloadTexture(table);
	UnloadTexture(tableBackground);
	UnloadTexture(rightArrow);

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

	case 2:
		if (dir->j > 2) {
			player->positionsOfDoors.erase("down");
			player->positionsOfDoors.erase("right");
		}else{

			player->positionsOfDoors.erase("down");
			player->positionsOfDoors.erase("left");
		}

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
