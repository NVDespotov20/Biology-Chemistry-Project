#include "pchGame.hpp"
#include "CheckValency.hpp"

CheckValency::CheckValency() 
{
    
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

	saver = 0;

	//random seed for the numbers
	seed = std::chrono::steady_clock::now().time_since_epoch().count();

	//generator of new random number with the seed
	gen.seed(seed);

	//std::shuffle(elementsTexturesStrings.begin(), elementsTexturesStrings.end(), gen);

	
	std::shuffle(valencyOne.begin(), valencyOne.end(), gen);
	std::shuffle(valencyTwo.begin(), valencyTwo.end(), gen);
	
	for (int i = 0; i < 3; i++)
	{
		valencyTwo[i] = "../assets/images/chemistry/" + valencyTwo[i] + ".png";
		valencyOne[i] = "../assets/images/chemistry/" + valencyOne[i] + ".png";
	}

    theChosenThreeStrings.push_back((valencyTwo[0].c_str()));

	for(int i = 0; i < 2; i++)
	{
		theChosenThreeStrings.push_back((valencyOne[i].c_str()));
	}

    std::shuffle(theChosenThreeStrings.begin(), theChosenThreeStrings.end(), gen);
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
	for (int i = 0; i < 3; i++)
	{
		if (saver == i)
		{
			answersArray[i] = 2;
		}
		else
		{
			answersArray[i] = 1;
		}

	}

	for (int i = 0; i < 3; i++)
	{
        DrawTexture(theChosenThree[i], WIDTH/4, HEIGHT/3,BLUE);
	}
}

CheckValency::~CheckValency()
{

}