#pragma once
#include "Rooms.hpp"
#include "Navigator.hpp"
class RoomManager
{
	std::vector< std::vector<std::shared_ptr<Rooms> >> rooms;
	std::shared_ptr<Navigator> dir;
	public:
	void manageAndDrawRooms();
	void load();
	void unload();
	RoomManager();
	~RoomManager();
};

