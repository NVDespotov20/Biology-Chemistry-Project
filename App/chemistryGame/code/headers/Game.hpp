#pragma once
#include "Player.hpp"
#include "Teacher.hpp"
#include "pchGame.hpp"

class Game
{
public:
	Game();
	~Game();

	void mainLoop();

	std::shared_ptr<Player>player;
	std::shared_ptr<Teacher>teacher;
private:

};