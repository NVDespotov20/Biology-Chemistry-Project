#include "pchGame.hpp"
#include "RoomManager.hpp"

RoomManager::RoomManager()
{
	rooms = {
	   {nullptr, nullptr, std::make_shared<Rooms>(3), nullptr, nullptr},
	   {nullptr, nullptr, std::make_shared<Rooms>(4), nullptr, nullptr},
	   {std::make_shared<Rooms>(1)}
	};
	dir = Direction::getInstantiation();
}
void RoomManager::manageAndDrawRooms()
{
	if (dir->i != rooms.size() - 1 && rooms[dir->i][dir->j] == nullptr)
	{
		//fill the rooms
		if (dir->j > 2)
			rooms[dir->i][dir->j] = std::make_shared<Rooms>(5 - dir->j);
		else
			rooms[dir->i][dir->j] = std::make_shared<Rooms>(dir->j + 1);

		
		rooms[dir->i][dir->j]->drawRunningRoom();
		
	}
	else
	{

		if (dir->i == rooms.size() - 1)
			rooms[dir->i][0]->drawLastRoom();
		else if (dir->j == 0 || dir->j == rooms[0].size() - 1)
			rooms[dir->i][0]->drawMagazine();
		else
			rooms[dir->i][dir->j]->drawRunningRoom();
	}
}
RoomManager::~RoomManager()
{
}
