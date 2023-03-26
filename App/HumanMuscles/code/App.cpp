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
	humanBody = LoadTexture("../assets/images/muscles/body.png");
}

inline void App::unload()
{
	UnloadTexture(humanBody);
	UnloadTexture(nextButton);
	UnloadTexture(previousButton);
}

void App::switchViews()
{
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousePoint, nextButtonRec))
	{
		sideOfHumanRec.x = sideOfHumanRec.x + WIDTH / 3.f;
		return;
	}

	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousePoint, previousButtonRec))
	{
		sideOfHumanRec.x = sideOfHumanRec.x - WIDTH / 3.f;
		return;
	}

	if (CheckCollisionPointRec(mousePoint, backButton.getBoundingBox()) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		auto manager = pch::getInstantiation();
		manager->dir = pch::Direction::QUIT;
	}
}

void App::setSizes()
{
	fontSize = HEIGHT / 27;
	
	backButton = Button ("Exit", 0, 0, HEIGHT / 8, HEIGHT / 21.6, fontSize); //size of back button

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

	sideOfHumanRec = { 0, 0, (float)humanBody.width / 3.f, (float)humanBody.height };
	sideOfHumanVec = { WIDTH / 2.5f, HEIGHT / 4.f };

	sizeOfmuscleButtons = sizeof(muscles) / sizeof(muscles[0]);
	float	buttonHeight = HEIGHT / 21.6f,
			spaceBetweenButtons = HEIGHT / 36.f,
			buttonY = (HEIGHT - (sizeOfmuscleButtons * buttonHeight + (sizeOfmuscleButtons-1) * spaceBetweenButtons)) / 2;
	for (float i = 0; i < sizeOfmuscleButtons; ++i, buttonY +=  buttonHeight + spaceBetweenButtons)
		muscles[(int)i] = Button("BUTTON", WIDTH - WIDTH / 5.f, buttonY, WIDTH / 6.f, HEIGHT / 21.6f, fontSize);
	muscles[0].setLabel("Chest");
	muscles[1].setLabel("Core");
	muscles[2].setLabel("Forearms");
	muscles[3].setLabel("Quads");
	muscles[4].setLabel("Calves");
	muscles[5].setLabel("Shoulders");
	muscles[6].setLabel("Biceps");
	muscles[7].setLabel("Triceps");
	muscles[8].setLabel("Traps");
	muscles[9].setLabel("Lats");
	muscles[10].setLabel("Glutes");
	muscles[11].setLabel("Hamstrings");
}

void App::drawHumanAndButtons()
{
	mousePoint = GetMousePosition();

	// Check button inputs
	switchViews();

	BeginDrawing();

		backButton.draw(0.4f, 1, RED, BLACK);

		DrawTextureRec(humanBody, sideOfHumanRec, sideOfHumanVec, WHITE);

		DrawTexture(nextButton, WIDTH / 1.5f, HEIGHT / 2.f, WHITE);
		DrawTexture(previousButton, WIDTH / 3.8f, HEIGHT / 2.f, WHITE);

	for (int i = 0; i < sizeOfmuscleButtons; ++i)
	{
		muscles[i].draw(0.4f, 10, BLUE, BLACK);
		if (CheckCollisionPointRec(mousePoint, muscles[i].getBoundingBox()))
		{
			muscles[i].draw(0.4f, 10, SKYBLUE, BLACK);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
				showVideosAndInfo(i);
		}
	}

	DrawLineEx(lineOfButtons[0], lineOfButtons[1], 5, BLACK);

}


void App::showVideosAndInfo(int indexOfMuscle)
{
	/*
		LEGEND:
		
		0	==	Chest
		1	==	Core
		2	==	Forearms
		3	==	Quads
		4	==	Calves
		5	==	Shoulders
		6	==	Biceps
		7	==	Triceps
		8	==	Traps
		9	==	Lats
		10	==	Glutes
		11	==	Hamstrings
	*/
	if (indexOfMuscle == 0 || indexOfMuscle == 1 || indexOfMuscle == 2 || indexOfMuscle == 3 || indexOfMuscle == 4)
	{
		sideOfHumanRec.x = 0; // Front view
		return;
	}

	if (indexOfMuscle == 5 || indexOfMuscle == 6 || indexOfMuscle == 7)
	{
		sideOfHumanRec.x = WIDTH / 1.5f; // Side view
		return;
	}

	sideOfHumanRec.x = WIDTH / 3.f; // Back view
}