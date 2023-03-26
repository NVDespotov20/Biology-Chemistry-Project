#include "pchGame.hpp"
#include "Game.hpp"

Game::Game()
{
	// Initialization of the window and setting name and starting coordinates of the window
	InitWindow(0, 0, "Chemistry game");

	// Set our game to run at 60 frames-per-second
	SetTargetFPS(60);

	//Set our game to be on fullscreen
	ToggleFullscreen();
	manager = std::make_shared<RoomManager>();

}

//destructor - unloads and closes everything
Game::~Game()
{

	CloseWindow();
}

//The main loop where we call all the functions
void Game::mainLoop()
{
	while (!WindowShouldClose())
	{

		BeginDrawing();

		////set background
		ClearBackground(RAYWHITE);

		//player->drawAndMoveElementsAndHolders();
		manager->manageAndDrawRooms();

		EndDrawing();
	}
}
