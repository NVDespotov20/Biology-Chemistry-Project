#pragma once

class DoorsManager
{
	Texture2D door;
	std::vector<Vector2>positions;
public:
	DoorsManager();
	~DoorsManager();
	void drawDoors();
	int isNearDoor(Rectangle heroPosition);
	void enterDoor(int& index);
};