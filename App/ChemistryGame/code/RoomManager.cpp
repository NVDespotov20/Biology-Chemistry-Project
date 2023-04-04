#include "pchGame.hpp"
#include "RoomManager.hpp"

RoomManager::RoomManager()
{
	rooms = {
	   { std::make_shared<Rooms>(2), std::make_shared<Rooms>(3),  std::make_shared<Rooms>(2),   },
	   { std::make_shared<Rooms>(2), std::make_shared<Rooms>(4),  std::make_shared<Rooms>(2),   },
	   { std::make_shared<Rooms>(1)}
	};
	dir = Navigator::getInstantiation();
}
void RoomManager::load()
{
	for (auto& room : rooms)
	{
		for (auto& textures : room)
		{
			if (textures != nullptr)
				textures->load();
		}
	}
}

void RoomManager::unload()
{
	for (auto& room : rooms)
	{
		for (auto& textures : room)
		{
			if (textures != nullptr)
				RoomManager::unload();
		}
	}
}
void RoomManager::manageAndDrawRooms()
{
	if (dir->i != rooms.size() - 1 && rooms[dir->i][dir->j] == nullptr)
	{
		rooms[dir->i][dir->j]->drawChasingRoom();
		
	}
	else
	{

		if (dir->i == rooms.size() - 1)
			rooms[dir->i][0]->drawLastRoom();
		else
			rooms[dir->i][dir->j]->drawChasingRoom();
	}
}
RoomManager::~RoomManager()
{
}
