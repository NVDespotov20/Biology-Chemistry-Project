#pragma once
#include "Player.hpp"
#include "Teacher.hpp"
#include "Inventory.hpp"
class RunningRoom
{
	std::shared_ptr<Teacher>teacher;
	std::shared_ptr<InventorySystem>inventory;
	std::string stringDirHolder;
	std::shared_ptr<Player>player;
	std::shared_ptr<Direction>dir;
	int doors;
	public:
	RunningRoom();
	RunningRoom(int doors);
	~RunningRoom();
	void drawRunningRoom();
	void checkDoors();
};

