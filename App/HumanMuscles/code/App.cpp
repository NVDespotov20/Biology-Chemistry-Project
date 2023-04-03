#include "pch.hpp"
#include "App.hpp"
#include "Button.hpp"

std::shared_ptr<App> App::instantiate_ = nullptr;

App::App()
{
	// Initialize members
	WIDTH = GetScreenWidth() * 0.889f;
	HEIGHT = GetScreenHeight() * 0.818f;

	offsetX = GetScreenWidth() - WIDTH;
	offsetY = GetScreenHeight() - HEIGHT;
	mousePoint = { 0,0 };

	selectedMuscle = nullptr;

	muscleNames[0] = "Chest";
	muscleNames[1] = "Core";
	muscleNames[2] = "Forearms";
	muscleNames[3] = "Quads";
	muscleNames[4] = "Calves";
	muscleNames[5] = "Shoulders";
	muscleNames[6] = "Biceps";
	muscleNames[7] = "Triceps";
	muscleNames[8] = "Traps";
	muscleNames[9] = "Lats";
	muscleNames[10] = "Glutes";
	muscleNames[11] = "Hamstrings";
	sizeOfmuscleButtons = sizeof(muscles) / sizeof(muscles[0]);
	load();
	setSizes();
	setButtons();
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
	background = LoadTexture("../../ChemistryGame/assets/images/chemistry/Objects/Monitor.png");
	nextButton = LoadTexture("../assets/images/UI elements/next.png");
	previousButton = LoadTexture("../assets/images/UI elements/previous.png");
	humanBody = LoadTexture("../assets/images/muscles/body.png");

	for (int i = 0; i < sizeOfmuscleButtons; ++i)
	{
		std::string path = "../assets/images/muscles/" + muscleNames[i] + ".png";
		muscleTextures[i] = LoadTexture(path.c_str());
	}
}

inline void App::unload()
{
	UnloadTexture(background);
	UnloadTexture(humanBody);
	UnloadTexture(nextButton);
	UnloadTexture(previousButton);
	for (int i = 0; i < sizeOfmuscleButtons; ++i)
		UnloadTexture(muscleTextures[i]);
}

void App::checkInput()
{
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousePoint, nextButtonRec))
	{
		sideOfHumanRec.x = sideOfHumanRec.x + humanBody.width / 3.f;

		if (selectedMuscle)
			selectedMuscle = nullptr;

		if (!muscleInfo.empty())
			muscleInfo = "";
		return;
	}

	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousePoint, previousButtonRec))
	{
		sideOfHumanRec.x = sideOfHumanRec.x - humanBody.width / 3.f;

		if (selectedMuscle)
			selectedMuscle = nullptr;

		if (!muscleInfo.empty())
			muscleInfo = "";
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
	fontSize = HEIGHT / 36;

	backButton = Button("Exit", offsetX / 2, offsetY / 2, HEIGHT / 8, HEIGHT / 21.6, fontSize); //size of back button

	nextButton.width = WIDTH / 38.4f;
	nextButton.height = HEIGHT / 14.4f;

	previousButton.width = WIDTH / 38.4f;
	previousButton.height = HEIGHT / 14.4f;

	nextButtonRec = { offsetX / 2 + WIDTH / 1.5f, offsetY / 2 + HEIGHT / 2.f, (float)nextButton.width ,(float)nextButton.height };
	previousButtonRec = { offsetX / 2 + WIDTH / 3.8f, offsetY / 2 + HEIGHT / 2.f, (float)nextButton.width ,(float)nextButton.height };

	humanBody.width = (WIDTH + offsetX) / 2.f;
	humanBody.height = (HEIGHT + offsetY) / 2.f;

	for (int i = 0; i < sizeOfmuscleButtons; ++i)
	{
		muscleTextures[i].width = humanBody.width;
		muscleTextures[i].height = humanBody.height;
	}

	lineOfButtons[0] = { offsetX / 2 + WIDTH - WIDTH / 4.f, offsetY / 2 + 0.f };
	lineOfButtons[1] = { offsetX / 2 + WIDTH - WIDTH / 4.f, offsetY / 2 + HEIGHT };

	sideOfHumanRec = { 0, 0, (float)humanBody.width / 3.f, (float)humanBody.height };
	sideOfHumanVec = { offsetX / 2 + WIDTH / 2.5f, offsetY / 2 + HEIGHT / 4.f };


}

void App::setButtons()
{
	float	buttonHeight = HEIGHT / 21.6f,
		spaceBetweenButtons = HEIGHT / 36.f,
		buttonY = (HEIGHT - (sizeOfmuscleButtons * buttonHeight + (sizeOfmuscleButtons - 1) * spaceBetweenButtons)) / 2;

	for (int i = 0; i < sizeOfmuscleButtons; ++i, buttonY += buttonHeight + spaceBetweenButtons)
	{
		muscles[i] = Button("BUTTON", offsetX / 2 + WIDTH - WIDTH / 5.f, offsetY / 2 + buttonY, WIDTH / 6.f, HEIGHT / 21.6f, fontSize);
		muscles[i].setLabel(muscleNames[i].c_str());
	}

}

void App::drawUI()
{
	mousePoint = GetMousePosition();

	checkInput();

	DrawTexturePro(background,
		Rectangle{ 0,0, (float)background.width, (float)background.height },
		Rectangle{ 0,0,WIDTH + offsetX ,HEIGHT + offsetY },
		Vector2{ 0,0 },
		0, WHITE);

	backButton.draw(0.4f, 1, RED, BLACK);

	if (selectedMuscle)
	{
		DrawTextureRec(humanBody, sideOfHumanRec, sideOfHumanVec, Fade(GRAY, 0.6f));
		DrawTextureRec(*selectedMuscle, sideOfHumanRec, sideOfHumanVec, WHITE);
	}
	else
		DrawTextureRec(humanBody, sideOfHumanRec, sideOfHumanVec, WHITE);

	DrawTexture(nextButton, nextButtonRec.x, nextButtonRec.y, WHITE);
	DrawTexture(previousButton, previousButtonRec.x, previousButtonRec.y, WHITE);

	for (int i = 0; i < sizeOfmuscleButtons; ++i)
	{
		muscles[i].draw(0.4f, 10, BLUE, BLACK);
		if (CheckCollisionPointRec(mousePoint, muscles[i].getBoundingBox()))
		{
			muscles[i].draw(0.4f, 10, SKYBLUE, BLACK);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
				showInfo(i);
		}
	}

	DrawLineEx(lineOfButtons[0], lineOfButtons[1], 5, BLACK);
	if (muscleInfo.empty())
		return;
	DrawRectangle( offsetX / 2, offsetY / 2, previousButtonRec.x - offsetX / 2, HEIGHT - offsetY / 2, ORANGE);
	DrawText(muscleInfo.c_str(), WIDTH / 192 + offsetX / 2, HEIGHT / 10.8f + offsetY / 2, fontSize, BLACK);
}


void App::showInfo(int indexOfMuscle)
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

	fReader.openFile("../assets/textFiles/" + muscleNames[indexOfMuscle] + ".txt");
	std::string tmp = fReader.getText();
	
	if (!muscleInfo.empty() && muscleInfo == tmp)
	{
		selectedMuscle = nullptr;
		muscleInfo = "";
		return;
	}
	fReader.closeFile();
	muscleInfo = tmp;
	selectedMuscle = &muscleTextures[indexOfMuscle];

	if (indexOfMuscle == 0 || indexOfMuscle == 1 || indexOfMuscle == 2 || indexOfMuscle == 3 || indexOfMuscle == 4)
	{
		sideOfHumanRec.x = 0; // Front view
		return;
	}

	if (indexOfMuscle == 5 || indexOfMuscle == 6 || indexOfMuscle == 7)
	{
		sideOfHumanRec.x = (WIDTH + offsetX) / 1.5f; // Side view
		return;
	}

	sideOfHumanRec.x = (WIDTH + offsetX) / 3.f; // Back view
}