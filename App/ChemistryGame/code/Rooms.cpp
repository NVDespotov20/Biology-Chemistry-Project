#include "pchGame.hpp"
#include "Rooms.hpp"

Rooms::Rooms()
{
	
}

Rooms::~Rooms()
{
}

Rooms::Rooms(int door) : ChasingRoom(door), LastRoom(door), Shop(door)
{

}
