#pragma once
#include "RunningRoom.hpp"
#include "LastRoom.hpp"
class Rooms: public RunningRoom, public LastRoom
{
	public:
	Rooms();
	~Rooms();
	Rooms(int other);
};

