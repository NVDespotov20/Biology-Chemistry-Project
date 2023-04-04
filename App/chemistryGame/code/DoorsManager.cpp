#include "pchGame.hpp"
#include "DoorsManager.hpp"

DoorsManager::DoorsManager()
{
	WIDTH = GetScreenWidth();
	HEIGHT = GetScreenHeight();
	door = LoadTexture("../assets/images/chemistry/Objects/Door.png");
	dir = Navigator::getInstantiation();
	teacher = Teacher::getInstantiation();
	positionsOfDoors = {
		{"left", {0, HEIGHT / 2.f}},
		{"down", {WIDTH / 2.f, HEIGHT}},
		{"right", {WIDTH, HEIGHT / 2.f}}
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
		DrawCircleV(position, WIDTH / 9.6f, BLANK);

	}
}

std::string DoorsManager::isNearDoor(Rectangle& heroPos)
{
	for (const auto& [key, position] : positionsOfDoors)
	{
		if (CheckCollisionCircleRec(position, WIDTH / 9.6f, heroPos))
		{
			DrawCircleV(position, WIDTH / 9.6f, BLANK);
			return key;
		}

	}
	return "";
}

void DoorsManager::enterDoor(std::string& inx)
{
	if (IsKeyPressed(KEY_E))
	{
		//Draw array of levels of index = inx
		switch (inx[0])
		{
		case 'u':
		{
			teacher->changePosition(Vector2{ WIDTH / 3.84f, HEIGHT / 2.16f });
			teacher->setActive(false);
			//Load level 1
			dir->i--;
			dir->j = 2;
			break;
		}
		case 'd':
		{
			teacher->changePosition(Vector2{ WIDTH / 3.84f, HEIGHT / 2.16f });
			teacher->setActive(false);
			//Load level 2
			dir->i++;
			dir->j = 2;
			break;
		}
		case 'l':
		{
			teacher->changePosition(Vector2{ WIDTH / 3.84f, HEIGHT / 2.16f });
			teacher->setActive(false);
			//Load level 3
			dir->j--;
			break;
		}
		case 'r':
		{
			teacher->changePosition(Vector2{ WIDTH / 3.84f, HEIGHT / 2.16f });
			teacher->setActive(false);
			//Load level 3
			dir->j++;
			break;
		}
		}
	}
}