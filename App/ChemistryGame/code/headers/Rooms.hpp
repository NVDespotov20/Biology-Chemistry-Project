#pragma once
#include "RunningRoom.hpp"
#include "LastRoom.hpp"
#include "Magazine.hpp"
class Rooms: public RunningRoom, public LastRoom, public Magazine
{
	public:
	Rooms();
	~Rooms();
	Rooms(int door);
};

