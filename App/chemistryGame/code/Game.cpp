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

	//make them smart and delete by themselve
	player = std::make_shared<Player>();
	teacher = std::make_shared<Teacher>();

	//loads sprites of the moving people
	player->LoadSprites(60);
	teacher->LoadSprites();
}

//destructor - unloads and closes everything
Game::~Game()
{
	player->UnLoadTextures();

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

		player->CheckDir();
		player->Movement();

		//draw player
		DrawTexturePro(player->playerSprite, player->view, player->move, Vector2{ 10, 10 }, 0, WHITE);

		teacher->Update(player->playerCords, player->move);
		teacher->Draw();
		player->drawnormalItems();

		//takes parameters for the coordinates of the player
		player->isPickedUp(player->move);

		//draws inventory when you click E
		if (IsKeyDown(KEY_E))
		{
			player->drawInventory();
		}
		//player->drawElementsAndHolders();
		player->drawDoors();
		player->isNearDoor(player->move);
		EndDrawing();
	}
}
