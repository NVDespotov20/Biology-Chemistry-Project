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

	givenAnswers.resize(3);

    WIDTH = GetScreenWidth();
	HEIGHT = GetScreenHeight();

	background.width = WIDTH;
	background.height = HEIGHT;

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

void CheckValency::drawAndCheckElementsAndHolders(bool& loadMiniGame)
{
	mousePoint = GetMousePosition();

	for (int i = 0; i < 3; i++)
	{
		if (saver == i)
		{
			rightAnswersArray[i] = 2 + i * 3;
		}
		else
		{
			rightAnswersArray[i] = 1 + i * 3;
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


	//int k = 1;
	//while (k < 10)
	//{
	//	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousePoint, answersRec[k]))
	//	{
	//		if (givenAnswers.size() < 3)
	//		{
	//			if (givenAnswers.size() > 1 && k < 4)
	//			{
	//				givenAnswers.push_back(k);
	//			}
	//			if (givenAnswers.size() == 1 && k < 7 && k >3)
	//			{
	//				givenAnswers.push_back(k);
	//			}
	//			if(givenAnswers.size() > 1 && k > 7)
	//			{
	//				givenAnswers.push_back(k);
	//			}
	//		}
	//		k++;
	//	}
	//}

	//if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousePoint, answersRec[0]) && givenAnswers.at(0))
	//{

	//}

	//if (givenAnswers.size() == 3)
	//{
	//	for (int i = 0; i < 3; i++)
	//	{
	//		std::cout << "given index:   " << i << "    given answer:   " << givenAnswers.at(i) << "    right index: " << i << "right answer:" << rightAnswersArray[i];
	//	}
	//	std::cout << std::endl;
	//}

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

