#include "pchGame.hpp"
#include "DoorsManager.hpp"

DoorsManager::DoorsManager()
{
	door = LoadTexture("../assets/images/UI elements/door.png");
	dir = Direction::getInstantiation();
	positionsOfDoors = {
		{"left", {0, GetScreenHeight() / 2.f}},
		{"down", {GetScreenWidth() / 2.f, (float)GetScreenHeight()}},
		{"right", {(float)GetScreenWidth(), GetScreenHeight() / 2.f}}
	};
}

DoorsManager::~DoorsManager()
{
	UnloadTexture(door);
}

void DoorsManager::drawDoors()
{
	for (const auto& [key, position] : positionsOfDoors)
	{
		//DrawTextureV(door, position, WHITE);
		DrawCircleV(position, 200, Fade(PURPLE, 0.5f));
	}
}

std::string DoorsManager::isNearDoor(Rectangle& heroPos)
{
	for (const auto& [key, position] : positionsOfDoors)
	{
		if (CheckCollisionCircleRec(position, 200, heroPos))
		{
			DrawCircleV(position, 200, Fade(PURPLE, 1));
			return key;
		}

	}
	return "";
}

void DoorsManager::enterDoor(std::string& inx)
{
	if (IsKeyPressed(KEY_Q))
	{
		//Draw array of levels of index = inx
		switch (inx[0])
		{
		case 'u':
		{
			//Load level 1
			dir->i--;
			dir->j = 2;
			break;
		}
		case 'd':
		{
			//Load level 2
			dir->i++;
			dir->j = 2;
			break;
		}
		case 'l':
		{
			//Load level 3
			dir->j--;
			break;
		}
		case 'r':
		{
			//Load level 3
			dir->j++;
			break;
		}
		}
	}
}