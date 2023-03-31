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

	Rectangle answersRec[3];

	//random engine from random library
	std::mt19937 gen;

	static std::shared_ptr<CheckValency> getInstantiation();
	static std::shared_ptr<CheckValency> instantiate_;
private:


};