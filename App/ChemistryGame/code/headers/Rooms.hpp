#pragma once
#include "RunningRoom.hpp"
#include "LastRoom.hpp"
#include "Shop.hpp"
class Rooms: public RunningRoom, public LastRoom, public Shop
{
	public:
	Rooms();
	~Rooms();
	Rooms(int door);
};

