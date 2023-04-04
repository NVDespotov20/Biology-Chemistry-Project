#include "pchGame.hpp"
#include "CheckValency.hpp"

std::shared_ptr<CheckValency> CheckValency::instantiate_ = nullptr;

std::shared_ptr<CheckValency> CheckValency::getInstantiation()
{
	if (instantiate_ == nullptr) {
		instantiate_ = std::shared_ptr<CheckValency>(new CheckValency);
	}
	return instantiate_;
}

CheckValency::CheckValency()
{
	//mousePoint = GetMousePosition();
	WIDTH = GetScreenWidth();
	HEIGHT = GetScreenHeight();

	counterForAccuracy = 0;

	valencyTwo = {
		"Zinc(Zn)",
		"Copper(Cu)",
		"Oxygen(O2)"
	};

	valencyOne = {
		"Silver(Ag)",
		"Gold(Au)",
		"Soldium(Na)",
		"Hydrogen(H2)"
	};

	backbutton = { WIDTH / 2.743f, HEIGHT / 1.309f, WIDTH / 3.2f, HEIGHT / 5.4f };

	buttonsTextures[0] = LoadTexture("../assets/images/chemistry/Buttons/HolderOne.png");
	buttonsTextures[1] = LoadTexture("../assets/images/chemistry/Buttons/HolderTwo.png");
	buttonsTextures[2] = LoadTexture("../assets/images/chemistry/Buttons/HolderThree.png");

	label = LoadTexture("../assets/images/chemistry/Buttons/CheckValency.png");

	backbuttonTexture = LoadTexture("../assets/images/chemistry/Buttons/BackButton.png");
	backbuttonTexture.width = WIDTH / 3.2f;
	backbuttonTexture.height = HEIGHT / 2.4f;

	for (int i = 0; i < 4; i++)
	{
		valencyOne[i] = "../assets/images/chemistry/Elements/" + valencyOne[i] + ".png";
		if (i < 3)
		{
			valencyTwo[i] = "../assets/images/chemistry/Elements/" + valencyTwo[i] + ".png";
		}
	}

	//random seed for the numbers
	seed = std::chrono::steady_clock::now().time_since_epoch().count();

	//generator of new random number with the seed
	gen.seed(seed);

	//std::shuffle(elementsTexturesStrings.begin(), elementsTexturesStrings.end(), gen);

	std::shuffle(valencyOne.begin(), valencyOne.end(), gen);
	std::shuffle(valencyTwo.begin(), valencyTwo.end(), gen);

	theChosenThreeStrings.push_back((valencyTwo[0].c_str()));

	for (int i = 0; i < 2; i++)
	{
		theChosenThreeStrings.push_back((valencyOne[i].c_str()));
	}

	std::shuffle(theChosenThreeStrings.begin(), theChosenThreeStrings.end(), gen);


	for (int i = 0; i < 3; i++)
	{
		containersRec[i] = {
			WIDTH / 34.909f + i * WIDTH / 3.148f,
			HEIGHT / 21.6f,
			WIDTH / 3.254f,
			HEIGHT / 2.16f
		};

		answersRec1[i] = {
			WIDTH / 9.6f * i + WIDTH / 25.6f,
			HEIGHT / 2.88f,
			WIDTH / 12.8f,
			HEIGHT / 7.2f
		};

		answersRec2[i] = {
			WIDTH / 9.6f * (i + 3) + WIDTH / 22.588f,
			HEIGHT / 2.88f,
			WIDTH / 12.8f,
			HEIGHT / 7.2f
		};

		answersRec3[i] = {
			WIDTH / 9.6f * (i + 6) + WIDTH / 20.210f,
			HEIGHT / 2.88f,
			WIDTH / 12.8f,
			HEIGHT / 7.2f
		};

		theChosenThree.push_back(LoadTexture(theChosenThreeStrings[i].c_str()));

		buttonsTextures[i].width = WIDTH / 12;
		buttonsTextures[i].height = HEIGHT / 6.75;
	}

	background = LoadTexture("../assets/images/chemistry/Objects/TableBackground.png");

	background.width = WIDTH;
	background.height = HEIGHT;
}

void CheckValency::drawAndCheckElementsAndHolders(bool& loadMiniGame)
{
	mousePoint = GetMousePosition();

	DrawTexture(background, 0, 0, WHITE);

	for (int i = 0; i < 3; i++)
	{
		// Compare the file paths using the == operator
		if (theChosenThreeStrings[i] == valencyTwo[0])
		{
			saver = i;
		}

	}

	for (int i = 0; i < 3; i++)
	{
		rightAnswersArray[i] = 1 + i * 3;
		if (saver == i)
		{
			rightAnswersArray[i]++;
		}

		theChosenThree[i].width = WIDTH / 9.6f;
		theChosenThree[i].height = HEIGHT / 4.32f;

		DrawTexture(theChosenThree[i], WIDTH / 7.68f + i * WIDTH / 3.2f, HEIGHT / 10.8f, WHITE);
		DrawRectangleLinesEx(containersRec[i], HEIGHT / 108, BLACK);

		DrawRectangleRec(answersRec1[i], BLANK);
		DrawRectangleRec(answersRec2[i], BLANK);
		DrawRectangleRec(answersRec3[i], BLANK);

		DrawTexture(buttonsTextures[0], WIDTH / 26 + WIDTH / 3.148f * i, HEIGHT / 2.919f, WHITE);
		DrawTexture(buttonsTextures[1], WIDTH / 7.111f + WIDTH / 3.148f * i, HEIGHT / 2.919f, WHITE);
		DrawTexture(buttonsTextures[2], WIDTH / 4.085f + WIDTH / 3.148f * i, HEIGHT / 2.919f, WHITE);
	}


	for (int i = 0; i < 3; i++)
	{
		if (!IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
			continue;
		if (givenAnswers.size() >= 3)
			continue;

		if (CheckCollisionPointRec(mousePoint, answersRec1[i]))
		{
			if (givenAnswers.size() == 0)
			{
				givenAnswers.push_back(i + 1);
			}
		}

		if (CheckCollisionPointRec(mousePoint, answersRec2[i]))
		{
			if (givenAnswers.size() == 1)
			{
				givenAnswers.push_back(3 * i + 1);
			}
		}

		if (CheckCollisionPointRec(mousePoint, answersRec3[i]))
		{
			if (givenAnswers.size() == 2)
			{
				givenAnswers.push_back(3 * i + 1);
			}
		}
	}

	DrawTexture(backbuttonTexture, WIDTH / 2.743f, HEIGHT / 1.543f, WHITE);
	DrawRectangleRounded(backbutton, WIDTH / 192, HEIGHT / 108, BLANK);

	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(mousePoint, backbutton))
	{
		loadMiniGame = false;
	}
}


bool CheckValency::checkAccuracy()
{

	for (int i = 0; i < 3; i++)
	{
		if (givenAnswers[i] == rightAnswersArray[i])
		{
			++counterForAccuracy;
			break;
		}

	}

	//if you did right you earn money if not then RUN the teacher starts to chase you
	return (counterForAccuracy == 3);

}

CheckValency::~CheckValency()
{
	unload();
}

void CheckValency::unload()
{
	for (int i = 0; i < 3; i++)
	{
		UnloadTexture(theChosenThree[i]);
	}

}
