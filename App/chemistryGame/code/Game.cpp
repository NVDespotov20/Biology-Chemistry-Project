#include "pchGame.hpp"
#include "Game.hpp"

Game::Game()
{
	HEIGHT = GetScreenHeight();
	WIDTH = GetScreenWidth();
	roomManager = std::make_shared<RoomManager>();
	fontSize = HEIGHT / 36;
	backButton = Button("Menu", 0, 20, HEIGHT / 7, HEIGHT / 20, fontSize); //size of back button
}

//destructor - unloads and closes everything
Game::~Game()
{

}

//The main loop where we call all the functions
void Game::mainLoop()
{
	mousePoint = GetMousePosition();
	if (CheckCollisionPointRec(mousePoint, backButton.getBoundingBox()) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		auto manager = Navigator::getInstantiation();
		manager->dir = Navigator::Navigate::MENU;
	}
	backButton.draw(0.4f, 1, RED, BLACK);
	roomManager->manageAndDrawRooms();
}
