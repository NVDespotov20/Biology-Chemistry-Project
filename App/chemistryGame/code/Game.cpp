#include "pchGame.hpp"
#include "Game.hpp"
Game::Game()
{

	// Initialization
	//--------------------------------------------------------------------------------------
	InitWindow(0, 0, "Chemistry game");
	ToggleFullscreen();
	SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
	
	player = std::make_shared<Player>();
	teacher = std::make_shared<Teacher>();
	player->LoadSprites(60);
	teacher->LoadSprites();
}

Game::~Game()
{
	player->UnLoadTextures();

	CloseWindow();
}
void Game::mainLoop()
{
	while (!WindowShouldClose())
	{

		BeginDrawing();

		ClearBackground(RAYWHITE);
		player->CheckDir();
		player->Movement();
		DrawTexturePro(player->playerSprite, player->view, player->move, Vector2{ 10, 10 }, 0, WHITE);
		teacher->Update(player->playerCords, player->move);
		teacher->Draw(1);

		EndDrawing();

	}
}
