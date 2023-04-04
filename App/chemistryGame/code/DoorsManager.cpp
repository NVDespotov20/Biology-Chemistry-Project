#include "pchGame.hpp"
#include "DoorsManager.hpp"

DoorsManager::DoorsManager()
{
	door = LoadTexture("../assets/images/chemistry/Objects/Door.png");
	dir = Navigator::getInstantiation();
	teacher = Teacher::getInstantiation();
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
		DrawCircleV(position, 200, BLANK);
		
	}
}

std::string DoorsManager::isNearDoor(Rectangle& heroPos)
{
	for (const auto& [key, position] : positionsOfDoors)
	{
		if (CheckCollisionCircleRec(position, 200, heroPos))
		{
			DrawCircleV(position, 200, BLANK);
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
				teacher->changePosition(Vector2{500, 500});
				teacher->setActive(false);
				//Load level 1
				dir->i--;
				dir->j = 2;
				break;
			}
			case 'd':
			{
				teacher->changePosition(Vector2{500, 500});
				teacher->setActive(false);
				//Load level 2
				dir->i++;
				dir->j = 2;
				break;
			}
			case 'l':
			{
				teacher->changePosition(Vector2{500, 500});
				teacher->setActive(false);
				//Load level 3
				dir->j--;
				break;
			}
			case 'r':
			{
				teacher->changePosition(Vector2{500, 500});
				teacher->setActive(false);
				//Load level 3
				dir->j++;
				break;
			}
		}
	}
}