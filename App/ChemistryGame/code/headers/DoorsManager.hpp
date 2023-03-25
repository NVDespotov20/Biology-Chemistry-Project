#pragma once
class DoorsManager
{
	Texture2D door;
	std::shared_ptr<Direction> dir;
public:
	std::unordered_map<std::string, Vector2>positionsOfDoors;
	DoorsManager();
	~DoorsManager();
	void drawDoors();
	std::string isNearDoor(Rectangle& heroPosition);
	void enterDoor(std::string& index);
};