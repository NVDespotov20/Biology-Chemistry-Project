#pragma once

class SplitElements
{

public:
	SplitElements();
	~SplitElements();

	int positionOfMetalsHolder[4];
	int positionOfNonMetalsHolder[4];

	Rectangle holders[2];
	Rectangle box;
	Rectangle elementsInTheBoxRec[4];
	Rectangle elementsInTheBoxRec2[4];

	Texture2D naElement;

	void drawElementsAndHolders();
	void moveElements();
	bool checkForSubmission();
	bool checkForCorection();

private:
	int WIDTH;
	int HEIGHT;
};