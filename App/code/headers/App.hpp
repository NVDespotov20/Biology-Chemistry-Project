#pragma once
#include <raylib.h>
#include<iostream>
#include <string>
class App
{
public:

	~App();
	void loop();
	

	void setSizes();
	void showVideosAndInfo(int indexOfMuscle);
	static App* getInstantiation();

private:
	//Texture2D backButtonTex;
	Rectangle backButtonRec;
	App();
	static App* instantiate_;

	void load();
	void unload();

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
};