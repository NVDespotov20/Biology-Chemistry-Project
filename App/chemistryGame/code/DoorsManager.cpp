#include "pchGame.hpp"
#include "DoorsManager.hpp"

DoorsManager::DoorsManager()
{
	door = LoadTexture("../../assets/images/UI elements/door.png");
	positions = {
		{200, 500},
		{400, 500},
		{600, 500}
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
		DrawTextureV(door, position, WHITE);
	}
}

int DoorsManager::isNearDoor(Vector2 heroPos)
{
	for (auto i = 0;i<positions.size();i++)
	{
		if(CheckCollisionPointCircle(positions[i], heroPos, 200))
		{
			return i;
		}
	}
}

void DoorsManager::enterDoor(int inx)
{
	if(IsKeyPressed(KEY_W))
	{
		//Draw array of levels of index = inx
	}
}