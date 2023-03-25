#pragma once
#include "Rooms.hpp"
class RoomManager
{
	std::vector< std::vector<std::shared_ptr<Rooms> >> rooms;
	std::shared_ptr<Direction> dir;
	public:
	void manageAndDrawDoors();
	RoomManager();
	~RoomManager();
};

