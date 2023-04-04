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
	}
}

mixElements::~mixElements()
{
    unload(); 
}

void mixElements::Draw(bool& loadMiniGame);
{

}

mixElements::unload();
{
    UnloadTexture(backbuttonTexture);
    UnloadTexture(water);
   
}