#pragma once

class SplitElements
{

public:
	SplitElements();
	~SplitElements();
	
	std::string elementsInTheBox[8];

	int positionOfMetalsHolder[4];
	int positionOfNonMetalsHolder[4];

	Rectangle holders[2];
	Rectangle box;
	Rectangle elementsInTheBoxRec[8];

	void drawElementsAndHolders();
	void moveElements();
	bool checkForSubmission();
	bool checkForCorection();

private:
	int WIDTH;
	int HEIGHT;
};