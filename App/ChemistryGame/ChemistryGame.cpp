#include <pch.hpp>
#include "player.hpp"

int main()
{
	//create window
	InitWindow(0, 0, "Chemistry game");
		
	//set window to fullscreen
	ToggleFullscreen();

	//set fps
	SetTargetFPS(60);
		
	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(LIGHTGRAY);
		Player player;
		player.LoadSprites(10);
		player.Movement();
		player.CheckDir();
		player.CheckWalls();
		player.UnLoadTextures();

		EndDrawing();
	}	
	return 0;	

}

