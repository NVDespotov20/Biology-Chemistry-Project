// chemistryGame.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <raylib.h>
#include "Player.hpp"
#include "Teacher.hpp"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------

int main(void)
{
	// Initialization
	//--------------------------------------------------------------------------------------
	InitWindow(0, 0, "Chemistry game");
	ToggleFullscreen();
	SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
	//--------------------------------------------------------------------------------------

	Player player;
	Teacher teacher;
	player.LoadSprites(60);
	teacher.LoadSprites();
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
		teacher.Update(player.playerCords, player.move);
		teacher.Draw(1);

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	player.UnLoadTextures();
	// De-Initialization
	//--------------------------------------------------------------------------------------
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------
}