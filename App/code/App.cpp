#include <App.hpp>
#include <AppManager.hpp>

App* App::instantiate_ = nullptr;
App::App()
{
	
	// Initialize members
	WIDTH = GetScreenWidth();
	HEIGHT = GetScreenHeight();

	mousePoint = { 0,0 };
	
	
	load();
	
	setSizes();
	
}
App::~App()
{
	unload();
}

App* App::getInstantiation()
{
	if (instantiate_ == nullptr) {
		instantiate_ = new App();
	}
	return instantiate_;
}
inline void App::load()
{
	nextButton = LoadTexture("../assets/images/UI elements/next.png");
	previousButton = LoadTexture("../assets/images/UI elements/previous.png");
	humanBody = LoadTexture("../assets/images/muscles/Human_body.png");
}

inline void App::unload()
{
	UnloadTexture(humanBody);
	UnloadTexture(nextButton);
	UnloadTexture(previousButton);
}

void App::setSizes()
{
	backButtonRec = { 0,0, 50, 50};//size of back button

	nextButton.width = WIDTH / 38.4f;
	nextButton.height = HEIGHT / 14.4f;

	previousButton.width = WIDTH / 38.4f;
	previousButton.height = HEIGHT / 14.4f;

	nextButtonRec = { WIDTH / 1.5f, HEIGHT / 2.f, (float)nextButton.width ,(float)nextButton.height };
	previousButtonRec = { WIDTH / 3.8f, HEIGHT / 2.f, (float)nextButton.width ,(float)nextButton.height };

	humanBody.width = WIDTH / 2.f;
	humanBody.height = HEIGHT / 2.f;

	lineOfButtons[0] = { WIDTH - WIDTH / 4.f, 0.f };
	lineOfButtons[1] = { WIDTH - WIDTH / 4.f, HEIGHT };

	sideOfHumanRec = { WIDTH / 3.f, HEIGHT, (float)humanBody.width / 3.f, (float)humanBody.height };
	sideOfHumanVec = { WIDTH / 2.5f, HEIGHT / 4.f };

	for (float i = 0, x = HEIGHT / 1.18f; i < 8; ++i, x -= HEIGHT / 13.5f) {
		buttonsRec[(int)i] = { WIDTH - WIDTH / 5.f, HEIGHT - x, WIDTH / 6.f, HEIGHT / 21.6f };
		// Use this to recalculate the height offsets for drawing the muscle text
		// The formula is --> HEIGHT / HEIGHT - ( y of button ) + ( height of button ) / number
		// std::cout << "Y offset (inverted): " <<HEIGHT / (HEIGHT - ((HEIGHT - x) + (HEIGHT / 21.6f) / 10.f)) << '\n';
	}
}

void App::loop()
{
		mousePoint = GetMousePosition();

		ClearBackground(LIGHTGRAY);
		DrawRectangleRounded(backButtonRec, 15, 1, Fade(RED, 0.5f));
		if (CheckCollisionPointRec(mousePoint, backButtonRec) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			AppManager* manager = AppManager::getInstantiation();
			manager->dir = manager->MENU;
		}

		DrawTextureRec(humanBody, sideOfHumanRec, sideOfHumanVec, WHITE);

		DrawTexture(nextButton, (float)WIDTH / 1.5f, (float)HEIGHT / 2.f, WHITE);
		DrawTexture(previousButton, (float)WIDTH / 3.8f, (float)HEIGHT / 2.f, WHITE);


		// Fix unable to alt-tab
		if (!IsWindowFocused())
			MinimizeWindow();

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousePoint, nextButtonRec))
		{
			sideOfHumanRec.x = sideOfHumanRec.x + WIDTH / 1.5f;
		}

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousePoint, previousButtonRec))
		{
			sideOfHumanRec.x = sideOfHumanRec.x - WIDTH / 1.5f;
		}

		for (int i = 0; i < 8; ++i) 
		{
			DrawRectangleRounded(buttonsRec[i], 20, 10, BLUE);
			if (CheckCollisionPointRec(mousePoint, buttonsRec[i]))
			{
				DrawRectangleRounded(buttonsRec[i], 20, 10, Fade(SKYBLUE, .5f));
				if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
				{
					indexOfButtons = i;
					showVideosAndInfo(indexOfButtons);
				}

			}
		}
		DrawLineEx(lineOfButtons[0], lineOfButtons[1], 5, BLACK);

		// Offsets for drawing the muscle text recalculate via the formula in setSizes()
		DrawText("Biceps", WIDTH - WIDTH / 6.7, HEIGHT - HEIGHT /	  1.18648f, 40, BLACK);
		DrawText("Traps", WIDTH - WIDTH / 6.8, HEIGHT - HEIGHT /	  1.30081f, 40, BLACK);
		DrawText("Legs", WIDTH - WIDTH / 6.9, HEIGHT - HEIGHT /		  1.43951f, 40, BLACK);
		DrawText("Triceps", WIDTH - WIDTH / 6.4, HEIGHT - HEIGHT /	  1.61133f, 40, BLACK);
		DrawText("Shoulders", WIDTH - WIDTH / 5.89, HEIGHT - HEIGHT / 1.82972f, 40, BLACK);
		DrawText("Back", WIDTH - WIDTH / 7.1, HEIGHT - HEIGHT /		  2.11659f, 40, BLACK);
		DrawText("Chest", WIDTH - WIDTH / 6.95, HEIGHT - HEIGHT /	  2.51014f, 40, BLACK);
		DrawText("Core", WIDTH - WIDTH / 7.1, HEIGHT - HEIGHT /		  3.08347f, 40, BLACK);


}


void App::showVideosAndInfo(int indexOfMuscle)
{
	if (indexOfMuscle == 0)
	{
		// play biceps video
		sideOfHumanRec.x = 2 * (WIDTH / 3.f);
	}

}