#include <pch.hpp>
#include "App.hpp"
#include "Button.hpp"

std::shared_ptr<App> App::instantiate_ = nullptr;

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

std::shared_ptr<App> App::getInstantiation()
{
	if (instantiate_ == nullptr) {
		instantiate_ = std::shared_ptr<App>(new App);
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
	fontSize = HEIGHT / 27;
	
	backButton = Button ("", 0, 0, HEIGHT / 21.6, HEIGHT / 21.6, fontSize); //size of back button

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

	for (float i = 0, x = HEIGHT / 1.18f; i < 8; ++i, x -= HEIGHT / 13.5f)
		muscles[(int)i] = Button("BUTTON", WIDTH - WIDTH / 5.f, HEIGHT - x, WIDTH / 6.f, HEIGHT / 21.6f, fontSize);
	muscles[0].setLabel("Biceps");
	muscles[1].setLabel("Traps");
	muscles[2].setLabel("Legs");
	muscles[3].setLabel("Triceps");
	muscles[4].setLabel("Shoulders");
	muscles[5].setLabel("Back");
	muscles[6].setLabel("Chest");
	muscles[7].setLabel("Core");
}

void App::drawHumanAndButtons()
{
	mousePoint = GetMousePosition();

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

	if (CheckCollisionPointRec(mousePoint, backButton.getBoundingBox()) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		auto manager = pch::getInstantiation();
		manager->dir = pch::Direction::MENU;
	}

	BeginDrawing();

		DrawRectangleRounded(backButton.getBoundingBox(), 0.4f, 1, Fade(RED, 0.5f));

		DrawTextureRec(humanBody, sideOfHumanRec, sideOfHumanVec, WHITE);

		DrawTexture(nextButton, (float)WIDTH / 1.5f, (float)HEIGHT / 2.f, WHITE);
		DrawTexture(previousButton, (float)WIDTH / 3.8f, (float)HEIGHT / 2.f, WHITE);

	for (int i = 0; i < 8; ++i)
	{
		muscles[i].draw(0.4f, 10, BLUE, BLACK);
		if (CheckCollisionPointRec(mousePoint, muscles[i].getBoundingBox()))
		{
			muscles[i].draw(0.4f, 10, SKYBLUE, BLACK);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				showVideosAndInfo(i);
			}
		}
	}

	DrawLineEx(lineOfButtons[0], lineOfButtons[1], 5, BLACK);

}


void App::showVideosAndInfo(int indexOfMuscle)
{
	if (indexOfMuscle == 0 or indexOfMuscle == 3 or indexOfMuscle == 4)
	{
		sideOfHumanRec.x = 2 * (WIDTH / 3.f);
	}
	else if (indexOfMuscle == 1 or indexOfMuscle == 2 or indexOfMuscle == 6 or indexOfMuscle == 7)
	{
		sideOfHumanRec.x = 2 * (WIDTH / 2.f);
	}
	else
	{
		sideOfHumanRec.x = 2 * (WIDTH / 1.5);
	}
}