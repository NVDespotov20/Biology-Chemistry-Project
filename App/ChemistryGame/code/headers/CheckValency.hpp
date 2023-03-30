#pragma once
#
class CheckValency
{
public:

	CheckValency();
	~CheckValency();

	void saveValency(); 
	void drawAndCheckElementsAndHolders();

	int WIDTH;
	int HEIGHT;

	int saver;

	std::vector<std::string> theChosenThreeStrings;

	std::vector<std::string> valencyTwo;

	std::vector<std::string> valencyOne;

	std::vector<Texture2D> theChosenThree;

	int answersArray[3]; 

	unsigned seed;

	//random engine from random library
	std::mt19937 gen;


private:


};