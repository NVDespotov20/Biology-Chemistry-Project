#include "pchGame.hpp"
#include "Rooms.hpp"

Rooms::Rooms()
{
	
}

Rooms::~Rooms()
{
}

Rooms::Rooms(int other) : RunningRoom(other)
{
	std::cout << "Copy" << std::endl;
}
