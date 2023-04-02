#include "pchGame.hpp"
#include "CheckValency.hpp"
#include <iostream>

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

	background.width = GetScreenWidth();
	background.height = GetScreenHeight();

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

	for (int i = 0; i < 9; i++)
	{
		answersRec[i] = {
			200.f *i + 50 ,
			800 ,
			150, 
			150
		};
	}

	for (int i = 0; i < 3; i++)
	{
		containersRec[i] = {
			float(30 + i * 600) ,
			470 ,
			590 ,
			500 
		};
	}
	for (int i = 0; i < 3; i++)
	{
		theChosenThree.push_back(LoadTexture(theChosenThreeStrings[i].c_str()));
	}
	background = LoadTexture("../assets/images/chemistry/Objects/TableBackground.png");
	
}

void CheckValency::drawAndCheckElementsAndHolders(bool& loadMiniGame)
{
	mousePoint = GetMousePosition();

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
	}

	DrawTexture(background, 0, 0, WHITE);
	for (int i = 0; i < 3; i++)
	{
		theChosenThree[i].width = 200;
		theChosenThree[i].height = 250;

		DrawTexture(theChosenThree[i], float(30 + i * 600), 470, WHITE);
		DrawRectangleLinesEx(containersRec[i], 10, BLACK);
	}

	for (int i = 0; i < 9; i++)
	{
		DrawRectangleRec(answersRec[i], LIME);
	}

	for (int i = 1; i < 4; i++)
	{
		for (int j = 1; j < 4; j++)
		{
			DrawText(std::to_string(i).c_str(), 600 + (j - 2) * 650 + i * 200, 770, 50, BLACK);
		}
	}


	for (int i = 0; i < 9; i++)
	{
		if (CheckCollisionPointRec(mousePoint, answersRec[i]))
		{
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
			{
				if (givenAnswers.size() < 3) {
					if (givenAnswers.size() == 0) {
						if (i >= 0 && i <= 2) {
							givenAnswers.push_back(i+1);
						}
					}
					else if (givenAnswers.size() == 1) {
						if (i >= 3 && i <= 5) {
							givenAnswers.push_back(i+1);
						}
					}
					else if (givenAnswers.size() == 2) {
						if (i >= 6 && i <= 8) {
							givenAnswers.push_back(i+1);
						}
					}
				}
			}
		}
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
	UnloadTexture(background); 
}

