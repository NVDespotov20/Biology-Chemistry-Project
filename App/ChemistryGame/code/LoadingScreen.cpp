#include "pchGame.hpp"
#include "LoadingScreen.hpp"

LoadingScreen::LoadingScreen() : loaded(false), bgTexture(Texture2D())
{
	bgTexture = LoadTexture("<insert path to texture>");
	loaded = false;
	loadingThread = std::thread{ draw };
}

LoadingScreen::~LoadingScreen()
{
	loaded = true;
	loadingThread.join();
	UnloadTexture(bgTexture);
}

void LoadingScreen::draw()
{
	//texture loading screen

	while(loaded)
	{
		ClearBackground(ORANGE);
		//draw loading screen
	}
}