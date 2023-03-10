#pragma once
#include "raylib.h"
class App
{
public:

	float WIDTH;
	float HEIGHT;
	Vector2 mousePoint; 

	Texture2D humanBody;

	Texture2D nextButton;
	Texture2D previousButton ;

	Rectangle nextButtonRec ;
	Rectangle previousButtonRec ;

	Rectangle sideOfHumanRec;
	Vector2 sideOfHumanVec;


	App();
	~App();
	void loop();

private:

};