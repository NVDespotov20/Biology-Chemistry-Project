#include "pchGame.hpp"
#include "GameManager.hpp"

GameManager::GameManager()
{
	// Initialization of the window and setting name and starting coordinates of the window


	InitWindow(0, 0, "Escape the IT");
	ToggleFullscreen();
	SetTargetFPS(60);

	BeginDrawing();
	{
		DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), WHITE);
		Vector2 textSize = MeasureTextEx(GetFontDefault(), "LOADING...", GetScreenWidth() / 11.294f, 1);
		DrawText("LOADING...", (GetScreenWidth() - textSize.x) / 2, (GetScreenHeight() - textSize.y) / 2, GetScreenWidth() / 11.294f, BLACK);
	}
	EndDrawing();

	//Set our GameManager to be on fullscreen
	game = std::make_shared<Game>();
	menu = std::make_shared<Menu>();

	//shouldQuit = false;
}

//destructor - unloads and closes everything
GameManager::~GameManager()
{
	//UnloadTexture(loadingSprite);
	CloseWindow();
}

void GameManager::start()
{

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(LIGHTGRAY);
		manageGame();
		EndDrawing();
	}
}

bool GameManager::manageGame()
{
	//create pch instance
	std::shared_ptr<Navigator> gameNavigator = Navigator::getInstantiation();
	switch (gameNavigator->dir)
	{
	case Navigator::Navigate::GAME:
	{
		game->mainLoop();
		return false;
	}
	case Navigator::Navigate::MENU:
	{
		menu->drawMainMenu();
		return false;
	}
	case Navigator::Navigate::QUIT:
	{
		EndDrawing();
		CloseWindow();
		exit(0);
	}
	}
}