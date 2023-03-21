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
	Rectangle submitAnswer;

	Texture2D isSelected;

	Texture2D naElement;
	Texture2D cElement;
	Texture2D nElement;
	Texture2D oElement;
	Texture2D fElement;
	Texture2D pElement;
	Texture2D clElement;
	Texture2D hElement;
	Texture2D znElement;
	Texture2D cuElement;
	Texture2D auElement;
	Texture2D agElement;
	Texture2D sElement;

	Texture2D backgroundOfTable;

	std::vector<Texture2D> elementsTextures;

	std::vector<Texture2D> metalElementsTextures;

	std::vector<Texture2D> nonmetalElementsTextures;

	//seed that we make different every time
	unsigned seed;

	//random engine from random library
	std::mt19937 gen;

	void drawElementsAndHolders();
	void moveElements();
	bool checkForSubmission();
	bool checkForCorection();

private:
	int WIDTH;
	int HEIGHT;

	Vector2 mousepoint;
};