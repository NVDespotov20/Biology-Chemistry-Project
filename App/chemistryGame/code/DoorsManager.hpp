#pragma once

class DoorsManager
{
	Texture2D door;
	std::vector<Vector2>positions;
public:
	DoorsManager();
	~DoorsManager();
	void drawDoors();
	int isNearDoor(Vector2 heroPosition);
	void enterDoor(int index);
};