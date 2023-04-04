#pragma once

class CheckValency
{
public:

	CheckValency();
	~CheckValency();

	void drawAndCheckElementsAndHolders(bool &loadMiniGame);
	bool checkAccuracy();
	void unload(); 

	static std::shared_ptr<CheckValency> getInstantiation();

	int counterForAccuracy;
	int saver;
	int rightAnswersArray[3];

	std::vector<int> givenAnswers;

	std::vector<std::string> theChosenThreeStrings;
	std::vector<std::string> valencyTwo;
	std::vector<std::string> valencyOne;

	std::vector<Texture2D> theChosenThree;

	Rectangle backbutton;
	Rectangle answersRec1[3];
	Rectangle answersRec2[3];
	Rectangle answersRec3[3];
	Rectangle containersRec[3];

	Texture2D background;
	Texture2D backbuttonTexture;
	Texture2D buttonsTextures[3];
	Texture2D metalOrNonmetalChoice[2];

	unsigned seed;

	//random engine from random library
	std::mt19937 gen;

	
private:
	Vector2 mousePoint;
	static std::shared_ptr<CheckValency> instantiate_;
	int WIDTH;
	int HEIGHT;
};