#pragma once
#include "SplitElements.hpp"
#include "ChasingRoom.hpp"
#include "RoomManager.hpp"
#include "Button.hpp"

class Game
{
private:
	std::shared_ptr<RoomManager>roomManager;
	Button backButton;
	Vector2 mousePoint;
	float WIDTH;
	float HEIGHT;
	int fontSize;
public:
	Game();
	~Game();
	void mainLoop();

};