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
	runningRoom = std::make_shared<RunningRoom>();
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

		//player->CheckDir();
		//player->Movement();

		////draw player
		//DrawTexturePro(player->playerSprite, player->view, player->move, Vector2{ 10, 10 }, 0, WHITE);

		//teacher->Update(player->playerCords, player->move);
		//teacher->Draw();
		//player->drawnormalItems();

		////takes parameters for the coordinates of the player
		//player->isPickedUp(player->move);
		////draws inventory when you click E
		//if (IsKeyDown(KEY_E))
		//{
		//	player->drawInventory();
		//}
		//player->drawAndMoveElementsAndHolders();

		////draws inventory when you click E
		//if (IsKeyDown(KEY_E))
		//{
		//	player->drawInventory();
		//}
		//player->drawAndMoveElementsAndHolders();
		//player->drawDoors();
		//player->isNearDoor(player->move);
		manager->manageAndDrawDoors();
		//runningRoom->draw();
		EndDrawing();
	}
}
