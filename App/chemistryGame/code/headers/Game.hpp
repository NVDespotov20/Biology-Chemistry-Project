#pragma once
#include "Player.hpp"
#include "Teacher.hpp"
class Game
{
public:
	Game();
	~Game();
	void mainLoop();
	Player*player;
	Teacher*teacher;
private:

};



