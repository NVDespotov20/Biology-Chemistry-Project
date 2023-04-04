#include "pchGame.hpp"
#include "RoomManager.hpp"

RoomManager::RoomManager()
{
	rooms = {
	   {std::make_shared<Rooms>(1),  std::make_shared<Rooms>(2), std::make_shared<Rooms>(3),  std::make_shared<Rooms>(2),  std::make_shared<Rooms>(1)},
	   {std::make_shared<Rooms>(1),  std::make_shared<Rooms>(2), std::make_shared<Rooms>(4),  std::make_shared<Rooms>(2),  std::make_shared<Rooms>(1)},
	   {std::make_shared<Rooms>(1)}
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
			
		if (dir->j > 2)
			rooms[dir->i][dir->j] = std::make_shared<Rooms>(5 - dir->j);
		else
			rooms[dir->i][dir->j] = std::make_shared<Rooms>(dir->j + 1);

		rooms[dir->i][dir->j]->drawChasingRoom();
		
	}
	else
	{

		if (dir->i == rooms.size() - 1)
			rooms[dir->i][0]->drawLastRoom();
		else if (dir->j == 0 || dir->j == rooms[0].size() - 1)
			rooms[dir->i][dir->j]->drawShop();
		else
			rooms[dir->i][dir->j]->drawChasingRoom();
	}
}
RoomManager::~RoomManager()
{
}
