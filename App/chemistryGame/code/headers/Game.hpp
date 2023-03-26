#pragma once
#include "SplitElements.hpp"
#include "ChasingRoom.hpp"
#include "RoomManager.hpp"

class Game
{
public:
	Game();
	~Game();
	std::shared_ptr<ChasingRoom>ChasingRoom;
	std::shared_ptr<RoomManager>manager;
	void mainLoop();
private:

};