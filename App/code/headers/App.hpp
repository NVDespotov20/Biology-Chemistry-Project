#pragma once
#include "raylib.h"
class App
{
public:
	int indexOfButtons;

	float WIDTH;
	float HEIGHT;

	Texture2D humanBody;
	Texture2D nextButton;
	Texture2D previousButton;

	Rectangle nextButtonRec;
	Rectangle previousButtonRec;
	Rectangle sideOfHumanRec;
	Rectangle buttonsRec[8];

	Vector2 mousePoint;
	Vector2 sideOfHumanVec;
	Vector2 lineOfButtons[2];

	App();
	~App();
	void loop();
	void showVideosAndInfo(int indexOfMuscle);


private:

};