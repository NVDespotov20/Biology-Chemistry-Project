#include "pchGame.hpp"
#include "Rooms.hpp"

Rooms::Rooms()
{
	
}

Rooms::~Rooms()
{
}

Rooms::Rooms(int door) : RunningRoom(door), LastRoom(door), Magazine(door)
{
	std::cout << "Copy" << std::endl;
}
