#include "pchGame.hpp"
#include "RoomManager.hpp"


RoomManager::RoomManager()
{
	rooms = {
	   {nullptr, nullptr, std::make_shared<Rooms>(3), nullptr, nullptr},
	   {nullptr, nullptr, std::make_shared<Rooms>(4), nullptr, nullptr},
	   {nullptr}
	};
	dir = Direction::getInstantiation();
}
void RoomManager::manageAndDrawDoors()
{
	if (rooms[dir->i][dir->j] == nullptr)
	{
		if (dir->j > 2)
			rooms[dir->i][dir->j] = std::make_shared<Rooms>(5 - dir->j);
		else
			rooms[dir->i][dir->j] = std::make_shared<Rooms>(dir->j + 1);

		rooms[dir->i][dir->j]->draw();
	}
	else
	{

		rooms[dir->i][dir->j]->draw();
	}
}
RoomManager::~RoomManager()
{
}
