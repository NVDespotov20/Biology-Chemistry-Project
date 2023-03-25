#include "pchGame.hpp"
#include "RunningRoom.hpp"

RunningRoom::RunningRoom()
{
	//make them smart and delete by themselve
	player = std::make_shared<Player>();
	teacher = std::make_shared<Teacher>();
	stringDirHolder = "";
	//loads sprites of the moving people
	player->LoadSprites(60);
	teacher->LoadSprites();
}

RunningRoom::RunningRoom(int doors)
{
	//make them smart and delete by themselve
	player = std::make_shared<Player>();
	teacher = std::make_shared<Teacher>();
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
	
		player->CheckDir();
		player->Movement();

		//draw player
		DrawTexturePro(player->playerSprite, player->view, player->move, Vector2{ 10, 10 }, 0, WHITE);

		teacher->Update(player->playerCords, player->move);
		teacher->Draw();
		player->drawnormalItems();

		//takes parameters for the coordinates of the player
		player->isPickedUp(player->move);
		checkDoors();
		//draws inventory when you click E
		if (IsKeyDown(KEY_E))
		{
			player->drawInventory();
		}
}

void RunningRoom::checkDoors()
{
	switch (this->doors)
	{
		case 2: {
			player->positionsOfDoors.erase("center");
			player->drawDoors();
			stringDirHolder = player->isNearDoor(player->move);
			player->enterDoor(stringDirHolder);
			break;
		}
		case 3: {
			player->drawDoors();
			stringDirHolder = player->isNearDoor(player->move);
			player->enterDoor(stringDirHolder);
			break;
		}
		case 4: {
			player->positionsOfDoors.insert({ "up", {GetScreenWidth() / 2.f, 0} });
			player->drawDoors();
			stringDirHolder = player->isNearDoor(player->move);
			player->enterDoor(stringDirHolder);
			break;
		}
	}
}

