#pragma once
#include "Navigator.hpp"
#include "Teacher.hpp"
class DoorsManager
{
	Texture2D door;
	std::vector<std::string> randomDoorsLabelsStrings;
	std::vector<std::string> randomizedLabelsStrings;
	unsigned seed;

	//random engine from random library
	std::mt19937 gen;

	//implement random with <random>

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