#pragma once
#include "SplitElements.hpp"
#include "RunningRoom.hpp"
#include "RoomManager.hpp"

class Game
{
public:
	Game();
	~Game();
	std::shared_ptr<RunningRoom>runningRoom;
	std::shared_ptr<RoomManager>manager;
	void mainLoop();
private:

};