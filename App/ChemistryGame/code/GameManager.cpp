#include "pchGame.hpp"
#include "GameManager.hpp"

GameManager::GameManager()
{
	// Initialization of the window and setting name and starting coordinates of the window
	InitWindow(0, 0, "Chemistry GameManager");

	// Set our GameManager to run at 60 frames-per-second
	SetTargetFPS(60);

	//Set our GameManager to be on fullscreen
	ToggleFullscreen();
    game = std::make_shared<Game>();
    menu = std::make_shared<Menu>();

    shouldQuit = false;

}

//destructor - unloads and closes everything
GameManager::~GameManager()
{

	CloseWindow();
}

void GameManager::start()
{

    while (!WindowShouldClose() && !shouldQuit)
    {

        BeginDrawing();
        ClearBackground(LIGHTGRAY);
        shouldQuit = manageGame();
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
            return true;
        }
    }
}
