#include "pchGame.hpp"
#include "DoorsManager.hpp"

DoorsManager::DoorsManager()
{
	door = LoadTexture("../assets/images/UI elements/door.png");
	positions = {
		{0, GetScreenHeight() / 2.f},
		{GetScreenWidth() / 2.f, (float)GetScreenHeight()},
		{(float)GetScreenWidth(), GetScreenHeight() / 2.f}
	};
}

DoorsManager::~DoorsManager()
{
	UnloadTexture(door);
}

void DoorsManager::drawDoors()
{
	for (auto& position : positions)
	{
		//DrawTextureV(door, position, WHITE);
		DrawCircleV(position, 200, Fade(PURPLE, 0.5f));
	}
}

int DoorsManager::isNearDoor(Rectangle heroPos)
{
	for (auto i = 0;i<positions.size();i++)
	{
		if(CheckCollisionCircleRec(positions[i], 200, heroPos))
		{
			DrawCircleV(positions[i], 200, Fade(PURPLE, 1));
			return i;
		}
	}
}

void DoorsManager::enterDoor(int&inx)
{
	if(IsKeyPressed(KEY_W))
	{
		//Draw array of levels of index = inx
		switch (inx)
		{
			case 0:
			{
				//Load level 1
				break;
			}
			case 1:
			{
				//Load level 2
				break;
			}
			case 2:
			{
				//Load level 3
				break;
			}
			default:
				break;
		}
	}
}