#pragma once

class SplitElements
{

public:
	~SplitElements();

	//int arrays for holders
	int positionOfMetalsHolder[4];
	int positionOfNonMetalsHolder[4];

	//rectangles initialization
	Rectangle elementsInTheBoxRec[4];
	Rectangle elementsInTheBoxRec2[4];
	Rectangle elementsInTheHolders[4];
	Rectangle elementsInTheHolders2[4];
	Rectangle choice[2];
	Rectangle backButton;

	//texture initialization
	Texture2D backgroundOfTable;

	//normal vars initialization
	int saverForIndexOfElement;

	bool chooseMetalOrNonmetal;

	//vectors initialization
	std::vector<std::string> elementsTexturesStrings;

	std::vector<std::string> checkerForMetals;

	std::vector<Texture2D> elementsTextures;

	std::vector<std::string> elementsStrings;

	std::vector<std::string> metalElementsStrings;

	std::vector<std::string> nonmetalElementsStrings;

	std::vector<Texture2D> metalsHolders;

	std::vector<Texture2D> nonmetalsHolders;

	int counter;

	//seed that we make different every time
	unsigned seed;

	//random engine from random library
	std::mt19937 gen;

	//function initialization
	void drawAndMoveElementsAndHolders(bool& loadMiniGame);
	void unload();
	static std::shared_ptr<SplitElements> getInstantiation();


	bool checkElements();
private:
	SplitElements();
	static std::shared_ptr<SplitElements> instantiate_;
	//not accessable from other places vars
	int WIDTH;
	int HEIGHT;

	Vector2 mousepoint;

};