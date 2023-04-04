#pragma once
#include "MixElements.hpp"
#include "ChasingRoom.hpp"
#include "LastRoom.hpp"

class Rooms: public ChasingRoom, public LastRoom
{
	public:
	Rooms();
	~Rooms();
	Rooms(int door);
};

