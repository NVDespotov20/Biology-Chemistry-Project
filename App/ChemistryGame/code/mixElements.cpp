#include "pchGame.hpp"
#include "MixElements.hpp"

mixElements::mixElements()
{
	water = LoadTexture("../assets/images/chemistry/Elements/Water(H2O).png");
	backbuttonTexture = LoadTexture("../assets/images/chemistry/Buttons/BackButton.png");
	backbuttonTexture.width = 220;
	backbuttonTexture.height = 150;
	elementsTexturesStrings = {
	"Zinc(Zn)",
	"Copper(Cu)",
	"Silver(Ag)",
	"Gold(Au)",
	"Soldium(Na)",
	"Sulfur(S)",
	"Phosphorus(P)",
	"Carbon(C)",
	"Chlorine(Cl2)"
	};

	seed = std::chrono::steady_clock::now().time_since_epoch().count();

	//generator of new random number with the seed
	gen.seed(seed);

	std::shuffle(elementsTexturesStrings.begin(), elementsTexturesStrings.end(), gen);

	for (int i = 0; i < 2; i++)
	{
		fiveChosen.push_back("../assets/images/chemistry/Elements/" + elementsTexturesStrings[i] + ".png");
		fiveChosen.push_back("../assets/images/chemistry/Elements/Hydrogen(H2).png");
	}
	fiveChosen.push_back("../assets/images/chemistry/Elements/Oxygen(O2).png");

	std::shuffle(fiveChosen.begin(), fiveChosen.end(), gen);

	for (int i = 0; i < 5; i++)
	{
		elementsTextures.push_back(LoadTexture(fiveChosen.at(i).c_str()));
		elementsTextures[i].width = 160;
		elementsTextures[i].height = 160;
	}

	v1.resize(4);
	v2.resize(4);

	//generate new seed
	gen.seed(seed);


	//set the range for the x and y where the normal items can appear
	range = std::uniform_int_distribution<int>(150, WIDTH - 150);
	range2 = std::uniform_int_distribution<int>(150, HEIGHT - 150);

	for (int i = 0; i < v1.size(); i++)
	{
		//filling the vector with random values
		v1[i] = range(gen);
		v2[i] = range2(gen);
	}
	elementPos = {
		{v1[0], v2[0]},
		{v1[1], v2[1]},
		{v1[2], v2[2]},
		{v1[3], v2[3]}
	};
}

mixElements::~mixElements()
{
	UnloadTexture(backbuttonTexture);
	UnloadTexture(water);
	for (int i = 0; i < 5; i++)
	{
		UnloadTexture(elementsTextures[i]);
	}
}

void mixElements::Draw(bool& loadMiniGame)
{
	for (int i = 0; i < 5; i++)
	{
		DrawTextureV(elementsTextures[i], elementPos[i], Fade(WHITE, 0.5f));
	}
}

