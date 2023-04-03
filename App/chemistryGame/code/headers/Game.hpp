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
	int fontSize;
	bool loadingComplete;
public:
	Game();
	~Game();
	void mainLoop();
	float WIDTH;
	float HEIGHT;

};