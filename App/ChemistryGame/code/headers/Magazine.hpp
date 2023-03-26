#pragma once
#include "Player.hpp"
class Magazine
{
	std::shared_ptr<Player>player;
	std::shared_ptr<Direction>dir;
	int door;
	public:
	Magazine(int door);
	Magazine();
	~Magazine();
	void drawMagazine();
	void checkMagazineDoors();
};

