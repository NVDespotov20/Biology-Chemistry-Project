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
		{ WIDTH / 2, HEIGHT / 10.8f },
		{ WIDTH / 1.909f, HEIGHT / 7.2f },
		{ WIDTH / 1.949f, HEIGHT / 4.8f },
		{ WIDTH / 2.053f, HEIGHT / 4.8f },
		{ WIDTH / 2.11f, HEIGHT / 7.2f },
		{ WIDTH / 2.043f, HEIGHT / 8.64f },
		{ WIDTH / 1.96f, HEIGHT / 8.64f }
	};

	rightArrow = LoadTexture("../assets/images/UI Elements/RightArrow.png");
	rightArrow.width = WIDTH / 5.486f;
	rightArrow.height = HEIGHT / 5.4f;

	seed = std::chrono::steady_clock::now().time_since_epoch().count();

	//generator of new random number with the seed
	gen.seed(seed);

	//std::shuffle(elementsTexturesStrings.begin(), elementsTexturesStrings.end(), gen);

	std::shuffle(stringsBackgroundName.begin(), stringsBackgroundName.end(), gen);

	menuButton = { 0,  HEIGHT / 54, WIDTH / 12.468f, HEIGHT / 20.f };

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
	table.width = WIDTH / 9.6f;
	table.height = HEIGHT / 5.4f;

	leftDoor = LoadTexture("../assets/images/chemistry/Objects/DoorLeft.png");
	leftDoor.width = WIDTH / 9.6f;
	leftDoor.height = HEIGHT / 5.4f;

	rightDoor = LoadTexture("../assets/images/chemistry/Objects/DoorRight.png");
	rightDoor.width = WIDTH / 9.6f;
	rightDoor.height = HEIGHT / 5.4f;

	downDoor = LoadTexture("../assets/images/chemistry/Objects/DoorDown.png");
	downDoor.width = WIDTH / 9.6f;
	downDoor.height = HEIGHT / 5.4f;

	upDoor = LoadTexture("../assets/images/chemistry/Objects/DoorUp.png");
	upDoor.width = WIDTH / 9.6f;
	upDoor.height = HEIGHT / 5.4f;

	doorsPositons[0].x = WIDTH / 76.8f;
	doorsPositons[0].y = HEIGHT / 2.4f;

	doorsPositons[1].x = WIDTH / 1.131f;
	doorsPositons[1].y = HEIGHT / 2.4f;

	doorsPositons[2].x = WIDTH / 2.259f;
	doorsPositons[2].y = HEIGHT / 36.f;

	doorsPositons[3].x = WIDTH / 2.259f;
	doorsPositons[3].y = HEIGHT / 1.263f;

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
		DrawTexture(texturesBackgrounds.at(0), 0, 0, WHITE);
		DrawTexture(leftDoor, doorsPositons[0].x, doorsPositons[0].y, WHITE);
		positionOfMiniGamePlace = { WIDTH / 1.2f, HEIGHT / 5.4f };
		DrawCircleV(positionOfMiniGamePlace, WIDTH / 192, BLANK);
		DrawTexture(table, WIDTH / 1.297f, HEIGHT / 10.8f, WHITE);
		if (CheckCollisionCircleRec(positionOfMiniGamePlace, WIDTH / 192, player->move) && IsKeyPressed(KEY_P) && !miniGameSplitElementsPlayed)
		{
			splitElements = SplitElements::getInstantiation();
			loadSplitElementsMiniGame = true;
		}
	}

	if (dir->j == 2 && dir->i == 0)
	{
		//center top
		DrawTexture(spawnPointBackground, 0, 0, WHITE);
		DrawTexture(leftDoor, doorsPositons[0].x, doorsPositons[0].y, WHITE);
		DrawTexture(rightDoor, doorsPositons[1].x, doorsPositons[1].y, WHITE);
		DrawTexture(downDoor, doorsPositons[3].x, doorsPositons[3].y, WHITE);
	}

	if (dir->j == 2 && dir->i == 1)
	{
		//center bottom
		DrawTexture(texturesBackgrounds.at(1), 0, 0, WHITE);
		DrawTexture(leftDoor, doorsPositons[0].x, doorsPositons[0].y, WHITE);
		DrawTexture(rightDoor, doorsPositons[1].x, doorsPositons[1].y, WHITE);
		DrawTexture(upDoor, doorsPositons[2].x, doorsPositons[2].y, WHITE);
		DrawTexture(downDoor, doorsPositons[3].x, doorsPositons[3].y, WHITE);
		positionOfMiniGamePlace = { WIDTH / 1.2f, HEIGHT / 4.8f };
		DrawCircleV(positionOfMiniGamePlace, WIDTH / 192, BLANK);
		DrawTexture(table, WIDTH / 1.297f, HEIGHT / 10.8f, WHITE);
		if (CheckCollisionCircleRec(positionOfMiniGamePlace, WIDTH / 192, player->move) && IsKeyPressed(KEY_P) && !miniGameCheckValencyPlayed)
		{
			checkValency = CheckValency::getInstantiation();
			loadCheckValencyMiniGame = true;
		}
	}
	if (dir->j == 1 && dir->i == 0)
	{
		//left top or bio room
		positionOfMiniGamePlace = { WIDTH / 5.908f, HEIGHT / 1.35f };
		DrawTexture(texturesBackgrounds.at(2), 0, 0, WHITE);
		DrawTexture(rightDoor, doorsPositons[1].x, doorsPositons[1].y, WHITE);
		DrawCircleV(positionOfMiniGamePlace, WIDTH / 192, PINK);
		DrawTexture(table, WIDTH / 9.6f, HEIGHT / 1.662f, WHITE);
		if (CheckCollisionCircleRec(positionOfMiniGamePlace, WIDTH / 192, player->move) && IsKeyPressed(KEY_P))
		{
			
		}
	}

	//also for right
	if (loadCheckValencyMiniGame)
	{
		drawCheckValencyMiniGame();
		return;
	}

	if (dir->j == 3 && dir->i == 1)
	{
		//bot right
		DrawTexture(texturesBackgrounds.at(3), 0, 0, WHITE);
		DrawTexture(leftDoor, doorsPositons[0].x, doorsPositons[0].y, WHITE);
		//fyre
	}

	if (dir->j == 1 && dir->i == 1)
	{
		//bot left
		positionOfMiniGamePlace = { WIDTH / 6.4f, HEIGHT / 5.4f };
		DrawTexture(texturesBackgrounds.at(4), 0, 0, WHITE);
		DrawTexture(rightDoor, doorsPositons[1].x, doorsPositons[1].y, WHITE);
		DrawCircleV(positionOfMiniGamePlace, WIDTH / 192, BLANK);
		DrawTexture(table, WIDTH / 11.294f, HEIGHT / 10.8f, WHITE);

		if (IsKeyPressed(KEY_P) && CheckCollisionCircleRec(positionOfMiniGamePlace, WIDTH / 192, player->move) && inventory->itemsInInventoryPos.size() == 4)
		{
			money->addMoney();
			for (int i = 0; i < 4; i++)
			{
				inventory->itemsInInventoryPos.pop_back();
			}
		}
		inventory->isPickedUp(player->move, items->item, items->normalItemsPos);
		DrawTexture(rightDoor, doorsPositons[1].x, doorsPositons[1].y, WHITE);
		items->drawNormalItems();
	}

	if (loadSplitElementsMiniGame)
	{
		drawSplitElementsMiniGame();
		return;
	}

	//update teacher
	teacher->update(player->playerCords, player->move);
	teacher->draw();

	//update player
	player->joinInRoom();

	if (IsKeyDown(KEY_TAB))
		inventory->drawInventory(items->item);
	//check doors

	DrawRectangleRounded(menuButton, 0.5, 0, RED);
	DrawText("Menu", WIDTH / 59.077f, HEIGHT / 36, HEIGHT / 36, BLACK);
	DrawRectangle(WIDTH / 12, HEIGHT / 54, WIDTH / 38.4f, HEIGHT / 19.636f, DARKGRAY);
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
