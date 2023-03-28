#pragma once
#include "Navigator.hpp"
class DoorsManager
{
	Texture2D door;
	std::shared_ptr<Navigator> dir;
public:
	std::unordered_map<std::string, Vector2>positionsOfDoors;
	DoorsManager();
	~DoorsManager();
	void drawDoors();
	std::string isNearDoor(Rectangle& heroPosition);
	void enterDoor(std::string& index);
};