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
			(50 + i * 200) * WIDTH / 1920.f,
			800 * HEIGHT / 1080.f,
			150 * WIDTH / 1920.f,
			150 * HEIGHT / 1080.f
		};
	}

	for (int i = 0; i < 3; i++)
	{
		containersRec[i] = {
			(30 + i * 600) * WIDTH / 1920.f,
			470 * HEIGHT / 1080.f,
			590 * WIDTH / 1920.f,
			500 * HEIGHT / 1080.f
		};
	}
	
}



void CheckValency::saveValency()
{
	for (int i = 0; i < 3; i++)
	{
        // Compare the file paths using the == operator
		if (theChosenThreeStrings[i] == valencyTwo[0])
		{
			saver = i;	
		}
		
	}
}

void CheckValency::drawAndCheckElementsAndHolders()
{
	mousePoint = GetMousePosition();

	for (int i = 0; i < 3; i++)
	{
		if (saver == i)
		{
			rightAnswersArray[i] = 2;
		}
		else
		{
			rightAnswersArray[i] = 1;
		}

	}

	for (int i = 0; i < 3; i++)
	{
		theChosenThree.push_back(LoadTexture(theChosenThreeStrings[i].c_str()));	
	}

	for (int i = 0; i < 3; i++)
	{
		theChosenThree[i].width = 200;
		theChosenThree[i].height = 250;

		DrawTexture(theChosenThree[i], 600 * i + 235, 450, WHITE);
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
			DrawText(std::to_string(i).c_str(), 600 + (j-2) * 650 + i *200, 770, 50, BLACK);
		}
	}

	for (int i = 1; i < 10; i++)
	{
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousePoint, answersRec[i]))
		{
			//std::cout << "yes" << std::endl;
			givenAnswers[i] = i;
		}
	}

	if (givenAnswers[0] != 0 or givenAnswers[1] != 0 or givenAnswers[2] != 0)
	{
		for (int i = 0; i < 3; i++)
		{
			//::cout << "given :" << givenAnswers[i] << "        right: " << rightAnswersArray[i] << std::endl;
		}
	}
	
}

CheckValency::~CheckValency()
{

}