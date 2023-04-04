#include "pchGame.hpp"
#include "MixElements.hpp"

mixElements::mixElements()
{
	water = LoadTexture("../assets/images/chemistry/Elements/Water(H2O).png");
	backbuttonTexture = LoadTexture("../assets/images/chemistry/Buttons/BackButton.png");
	backbuttonTexture.width = WIDTH / 8.727f;
	backbuttonTexture.height = HEIGHT / 7.2f;
	elementsTexturesStrings = {
		"Hydrogen(H2).png",
		"Hydrogen(H2).png",
		"Oxygen(O2).png",
	};

	for (int i = 0; i < 3; i++)
	{
		threeChosen.push_back("../assets/images/chemistry/Elements/" + elementsTexturesStrings[i] + ".png");
	}

	for (int i = 0; i < 3; i++)
	{
		elementsTextures.push_back(LoadTexture(threeChosen.at(i).c_str()));
		elementsTextures[i].width = WIDTH / 12;
		elementsTextures[i].height = HEIGHT / 6.75f;
	}
}

mixElements::~mixElements()
{
	UnloadTexture(backbuttonTexture);
	UnloadTexture(water);
	for (int i = 0; i < 3; i++)
	{
		UnloadTexture(elementsTextures[i]);
	}
}

void mixElements::Draw(bool& loadMiniGame)
{
	for (int i = 0; i < 3; i++)
	{
	
		DrawTexture(elementsTextures[i], WIDTH/9 + i * WIDTH/10, HEIGHT/1.4, WHITE);
	}
}

