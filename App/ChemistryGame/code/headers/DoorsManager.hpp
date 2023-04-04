#pragma once
#include "Navigator.hpp"
#include "Teacher.hpp"
class DoorsManager
{
	Texture2D door;

	std::shared_ptr<Navigator> dir;
	std::shared_ptr<Teacher> teacher;
public:
	std::unordered_map<std::string, Vector2>positionsOfDoors;
	DoorsManager();
	~DoorsManager();
	void drawDoors();
	std::string isNearDoor(Rectangle& heroPosition);
	void enterDoor(std::string& index);
};