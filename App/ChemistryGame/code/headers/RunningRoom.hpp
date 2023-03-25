#pragma once
#include "Player.hpp"
#include "Teacher.hpp"
class RunningRoom
{
	std::shared_ptr<Player>player;
	std::shared_ptr<Teacher>teacher;
	int doors;
	std::string stringDirHolder;
	public:
	RunningRoom();
	RunningRoom(int doors);
	~RunningRoom();
	void draw();
	void checkDoors();
};

