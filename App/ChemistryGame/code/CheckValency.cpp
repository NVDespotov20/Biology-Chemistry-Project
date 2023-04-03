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
	
	backbutton = {700,750,600,300};

	buttonsTextures[0] = LoadTexture("../assets/images/chemistry/Buttons/HolderOne.png");
	buttonsTextures[1] = LoadTexture("../assets/images/chemistry/Buttons/HolderTwo.png");
	buttonsTextures[2] = LoadTexture("../assets/images/chemistry/Buttons/HolderThree.png");

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

	for(int i = 0; i < 2; i++)
	{
		theChosenThreeStrings.push_back((valencyOne[i].c_str()));
	}

    std::shuffle(theChosenThreeStrings.begin(), theChosenThreeStrings.end(), gen);


	for (int i = 0; i < 3; i++)
	{
		containersRec[i] = {
			float(55 + i * 610) ,
			50,
			590,
			500
		};

		answersRec1[i] = {
			200.f *i + 75,
			375,
			150, 
			150
		};

		answersRec2[i] = {
			200.f * (i+3) + 85,
			375,
			150,
			150
		};

		answersRec3[i] = {
			200.f * (i+6) + 95,
			375,
			150,
			150
		};

		theChosenThree.push_back(LoadTexture(theChosenThreeStrings[i].c_str()));

		buttonsTextures[i].width = 160;
		buttonsTextures[i].height = 160;
	}

	background = LoadTexture("../assets/images/chemistry/Objects/TableBackground.png");

	background.width = WIDTH;
	background.height = HEIGHT;
}

void CheckValency::drawAndCheckElementsAndHolders(bool& loadMiniGame)
{
	mousePoint = GetMousePosition();

	DrawTexture(background, 0,0,WHITE);

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

		theChosenThree[i].width = 200;
		theChosenThree[i].height = 250;

		DrawTexture(theChosenThree[i], float(250 + i * 600), 100, WHITE);
		DrawRectangleLinesEx(containersRec[i], 10, BLACK);

		DrawRectangleRec(answersRec1[i], BLANK);
		DrawRectangleRec(answersRec2[i], BLANK);
		DrawRectangleRec(answersRec3[i], BLANK);

		DrawTexture(buttonsTextures[0], 70 + 610*i, 370, WHITE);
		DrawTexture(buttonsTextures[1], 270 + 610*i, 370, WHITE);
		DrawTexture(buttonsTextures[2], 470 + 610*i, 370, WHITE);
		
	}


	for (int i = 0; i < 3; i++)
	{
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			if (givenAnswers.size() < 3)
			{
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
		}
	}

	DrawRectangleRounded(backbutton,10,10,BLUE);

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

