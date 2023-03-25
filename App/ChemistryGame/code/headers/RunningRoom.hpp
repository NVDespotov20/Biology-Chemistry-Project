#pragma once
#include "Player.hpp"
#include "Teacher.hpp"
class RunningRoom
{
	std::shared_ptr<Player>player;
	std::shared_ptr<Teacher>teacher;
	std::string stringDirHolder;
	std::shared_ptr<Direction>dir;
	int doors;
	public:
	RunningRoom();
	RunningRoom(int doors);
	~RunningRoom();
	void drawRunningRoom();
	void checkDoors();
};

