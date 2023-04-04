#pragma once
#include "MixElements.hpp"
#include "ChasingRoom.hpp"
#include "LastRoom.hpp"
#include "Shop.hpp"
class Rooms: public ChasingRoom, public LastRoom, public Shop
{
	public:
	Rooms();
	~Rooms();
	Rooms(int door);
};

