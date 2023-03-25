#pragma once

class SplitElements
{

public:
	SplitElements();
	~SplitElements();

	int positionOfMetalsHolder[4];
	int positionOfNonMetalsHolder[4];

	Rectangle elementsInTheBoxRec[4];
	Rectangle elementsInTheBoxRec2[4];
	Rectangle elementsInTheHolders[4];
	Rectangle elementsInTheHolders2[4];
	Rectangle choice[2];
	Rectangle submitAnswer;

	Texture2D backgroundOfTable;
	
	std::vector<std::string> elementsTexturesStrings;

	int saverForIndexOfElement;

	bool chooseMetalOrNonmetal;

	std::vector<std::string> checkerForMetals;

	std::vector<Texture2D> elementsTextures;

	std::vector<std::string> elementsStrings;

	std::vector<std::string> metalElementsStrings;

	std::vector<std::string> nonmetalElementsStrings;

	std::vector<Texture2D> metalsHolders;

	std::vector<Texture2D> nonmetalsHolders;

	//seed that we make different every time
	unsigned seed;

	//random engine from random library
	std::mt19937 gen;

	void drawAndMoveElementsAndHolders();
	bool checkForSubmission();
	bool checkForCorection();
	void unload();
private:
	int WIDTH;
	int HEIGHT;

	Vector2 mousepoint;

	void checkElements();
};