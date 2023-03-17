// chemistryGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <raylib.h>
#include "Player.hpp"
//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
	// Initialization
	//--------------------------------------------------------------------------------------
	const int screenWidth = 800;
	const int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
	//--------------------------------------------------------------------------------------

	Player player;
	player.LoadSprites(60);
	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		// TODO: Update your variables here
		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(RAYWHITE);
		player.CheckDir();
		player.Movement();
		DrawTexturePro(player.playerSprite, player.view, player.move, Vector2{ 10, 10 }, 0, WHITE);


		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	player.UnLoadTextures();
	// De-Initialization
	//--------------------------------------------------------------------------------------
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}