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
    
    WIDTH = GetScreenWidth();
	HEIGHT = GetScreenHeight();

	valencyTwo = {
		"../assets/images/chemistry/Zinc(Zn).png",
		"../assets/images/chemistry/Copper(Cu).png",
		"../assets/images/chemistry/Oxygen(O2).png"
	};

	valencyOne = {
		"../assets/images/chemistry/Silver(Ag).png",
		"../assets/images/chemistry/Gold(Au).png",
		"../assets/images/chemistry/Soldium(Na).png",
		"../assets/images/chemistry/Hydrogen(H2).png"
	};

	saver = 0;

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

	for(int i=0;i<3;i++)
	{
		answersRec[i] = {200+i*100.f, 400, 250, 250};
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
		theChosenThree.push_back(LoadTexture(theChosenThreeStrings[i].c_str()));	
	}

	for (int i = 0; i < 3; i++)
	{
		theChosenThree[i].width = 250;
		theChosenThree[i].height = 300;
	}

	for (int i = 0; i < 3; i++)
	{
		DrawTexture(theChosenThree[i],200*i+200,500,WHITE);
		DrawRectangleRec(answersRec[i], LIME);
	}

}

CheckValency::~CheckValency()
{

}