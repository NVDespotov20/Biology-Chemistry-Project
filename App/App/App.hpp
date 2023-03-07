#pragma once
#include "raylib.h"
class App
{
public:
	Vector2 mousePoint;

	Texture2D humanBody;

	Texture2D nextButton;
	Texture2D previousButton;

	Rectangle nextButtonRec;
	Rectangle previousButtonRec;

	Rectangle sideOfHumanRec;
	Vector2 sideOfHumanVec;
	float sideOfHumanFloat;

	App();
	~App();
	void loop();

private:

};