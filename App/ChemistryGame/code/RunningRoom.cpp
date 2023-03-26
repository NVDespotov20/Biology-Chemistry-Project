#include "pchGame.hpp"
#include "RunningRoom.hpp"

RunningRoom::RunningRoom()
{
	////make them smart and delete by themselve
	//player = std::make_shared<Player>();
	//teacher = std::make_shared<Teacher>();
	//

	////loads sprites of the moving people
	//player->LoadSprites(60);
	//teacher->LoadSprites();
}

RunningRoom::RunningRoom(int doors)
{
	//variables that we use to make everything responsive
	WIDTH = GetScreenWidth();
	HEIGHT = GetScreenHeight();

	//make them smart and delete by themselve
	player = std::make_shared<Player>();
	teacher = std::make_shared<Teacher>();
	inventory = InventorySystem::getInstantiation();
	dir = Direction::getInstantiation();
	//loads sprites of the moving people
	player->LoadSprites(60);
	teacher->LoadSprites();
	this->doors = doors;
	positionOfMiniGamePlace = { 0,0 };
	loadMiniGame = 0;

	item = LoadTexture("../assets/images/chemistry/item.png");
	//setting sizes of variables
	item.width = 50;
	item.height = 50;


	//random seed using chrono library
	seed = std::chrono::steady_clock::now().time_since_epoch().count();

	//resize vector
	v1.resize(4);
	v2.resize(4);

	//generate new seed
	gen.seed(seed);


	//set the range for the x and y where the normal items can appear
	range = std::uniform_int_distribution<int>(1, WIDTH - WIDTH / 17);
	range2 = std::uniform_int_distribution<int>(1, HEIGHT - HEIGHT / 15);

	for (int i = 0; i < v1.size(); i++)
	{
		//filling the vector with random values
		v1[i] = range(gen);
		v2[i] = range2(gen);
	}
	normalItemsPos = {
		{v1[0], v2[0]},
		{v1[1], v2[1]},
		{v1[2], v2[2]},
		{v1[3], v2[3]}
	};
}

RunningRoom::~RunningRoom()
{
	UnloadTexture(item);
}

void RunningRoom::drawRunningRoom()
{
	if (dir->j == 3 && dir->i == 0)
	{
		positionOfMiniGamePlace = { 1000, 200 };
		DrawCircleV(positionOfMiniGamePlace, 100, RED);

	}
	if (CheckCollisionCircleRec(positionOfMiniGamePlace, 100, player->move) && IsKeyPressed(KEY_Q)) {
		loadMiniGame = true;
	}
	if (loadMiniGame) {
		player->drawAndMoveElementsAndHolders();
	}
	else
	{
		teacher->update(player->playerCords, player->move);
		teacher->draw();
		//update player
		player->join();
		inventory->isPickedUp(player->move, item, normalItemsPos);
		drawNormalItems();
		if (IsKeyDown(KEY_E))
		{
			inventory->drawInventory(item);
		}
		//check doors
		checkDoors();
	}
}

void RunningRoom::drawNormalItems()
{
	//draw the items but on 50% opacity
	for (auto& position : normalItemsPos)
	{
		DrawTextureV(item, position, Fade(WHITE, 0.5f));
	}
}
void RunningRoom::checkDoors()
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

