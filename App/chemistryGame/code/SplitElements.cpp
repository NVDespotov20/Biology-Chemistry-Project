#include "pchGame.hpp"
#include "SplitElements.hpp"

std::shared_ptr<SplitElements> SplitElements::instantiate_ = nullptr;

std::shared_ptr<SplitElements> SplitElements::getInstantiation()
{
	if (instantiate_ == nullptr) {
		instantiate_ = std::shared_ptr<SplitElements>(new SplitElements);
	}
	return instantiate_;
}
SplitElements::SplitElements()
{
	WIDTH = GetScreenWidth();
	HEIGHT = GetScreenHeight();

	//set sizes ofr holders
	positionOfMetalsHolder[0] = HEIGHT - HEIGHT / 1.25;
	positionOfMetalsHolder[1] = HEIGHT - HEIGHT / 1.5;
	positionOfMetalsHolder[2] = HEIGHT - HEIGHT / 2;
	positionOfMetalsHolder[3] = HEIGHT - HEIGHT / 2.25;

	positionOfNonMetalsHolder[0] = HEIGHT - HEIGHT / 1.25;
	positionOfNonMetalsHolder[1] = HEIGHT - HEIGHT / 1.5;
	positionOfNonMetalsHolder[2] = HEIGHT - HEIGHT / 2;
	positionOfNonMetalsHolder[3] = HEIGHT - HEIGHT / 2.25;

	counter = 0;

	//strings of all elements
	elementsTexturesStrings = {
	"Zinc(Zn)",
	"Copper(Cu)",
	"Silver(Ag)",
	"Gold(Au)",
	"Soldium(Na)",
	"Sulfur(S)",
	"Phosphorus(P)",
	"Carbon(C)",
	"Chlorine(Cl2)",
	"Hydrogen(H2)",
	"Oxygen(O2)"
	};

	//random seed for the numbers
	seed = std::chrono::steady_clock::now().time_since_epoch().count();

	//generator of new random number with the seed
	gen.seed(seed);

	backbuttonTexture = LoadTexture("../assets/images/chemistry/Buttons/BackButton.png");
	backbuttonTexture.width = WIDTH / 8.727;
	backbuttonTexture.height = HEIGHT / 7.2;

	//push split metals and nonmetals
	for (int i = 0; i < 5; i++)
	{
		metalElementsStrings.push_back("../assets/images/chemistry/Elements/" + elementsTexturesStrings[i] + ".png");
	}

	for (int i = 5; i < 11; i++)
	{
		nonmetalElementsStrings.push_back("../assets/images/chemistry/Elements/" + elementsTexturesStrings[i] + ".png");
	}

	//shuffle them to get ranodm only 4 of them
	std::shuffle(metalElementsStrings.begin(), metalElementsStrings.end(), gen);
	std::shuffle(nonmetalElementsStrings.begin(), nonmetalElementsStrings.end(), gen);

	//tracks mouse
	mousepoint = GetMousePosition();

	//loadtexture for bg
	backgroundOfTable = LoadTexture("../assets/images/chemistry/Objects/ArrangeTableBackground.png");

	//set size for width & height
	backgroundOfTable.width = GetScreenWidth();
	backgroundOfTable.height = GetScreenHeight();

	//set a boolean to fasle
	chooseMetalOrNonmetal = false;

	//push the random 4 metals and nonmetals to the 8 chosen elements we will display
	for (int i = 0; i < 4; i++)
	{
		elementsStrings.push_back(nonmetalElementsStrings[i]);
		elementsStrings.push_back(metalElementsStrings[i]);
	}

	//shuffle them so we can get each element random position
	std::shuffle(elementsStrings.begin(), elementsStrings.end(), gen);

	//now load the shuffled strings
	for (int i = 0; i < elementsStrings.size(); i++)
	{
		elementsTextures.push_back(LoadTexture(elementsStrings[i].c_str()));
	}

	choiceOfMetalOtNonmetal[0] = LoadTexture("../assets/images/chemistry/Buttons/MetalButton.png");
	choiceOfMetalOtNonmetal[1] = LoadTexture("../assets/images/chemistry/Buttons/NonmetalButton.png");

	//set sizes for each box
	for (int i = 0; i < 4; i++)
	{
		elementsInTheBoxRec[i] = { WIDTH / 3.80f + i * WIDTH / 7.68f, HEIGHT / 4.f + (HEIGHT / 4), WIDTH / 12.f, HEIGHT / 7.f };
		elementsInTheBoxRec2[i] = { WIDTH / 3.80f + i * WIDTH / 7.68f, HEIGHT / 4.5f + (HEIGHT / 40), WIDTH / 12.f, HEIGHT / 7.f };

		elementsInTheHolders[i] = { WIDTH / 15.f,HEIGHT / 6.f + i * HEIGHT/6.17f,WIDTH / 12.2f,HEIGHT / 7.f };
		elementsInTheHolders2[i] = { WIDTH - WIDTH / 6.5f,HEIGHT / 6.f + i * HEIGHT / 6.17f,WIDTH / 12.f,HEIGHT / 7.f };
	}

	//set size for choosing metal or nonmetal
	for (int i = 0; i < 2; i++)
	{
		choiceOfMetalOtNonmetal[i].width = WIDTH / 7.68;
		choiceOfMetalOtNonmetal[i].height = HEIGHT / 4.32;

		choice[i] = { WIDTH / 2.82f + i * WIDTH / 6.4f, HEIGHT / 1.44f, WIDTH /7.68f,HEIGHT/4.32f };
	}

	label = LoadTexture("../assets/images/chemistry/Buttons/SortElement.png");

	//set size for each texture
	for (int i = 0; i < elementsTextures.size(); i++)
	{
		elementsTextures[i].width = WIDTH / 10;
		elementsTextures[i].height = HEIGHT / 5.5;
	}

	//set place and size for back button
	backButton = { WIDTH / 2.f - WIDTH / 20,HEIGHT / 10.f,WIDTH / 10.f,HEIGHT / 20.f };

}

//destructor
SplitElements::~SplitElements()
{
	unload();
}

//unloads everything
void SplitElements::unload()
{
	//UnloadTexture();
	UnloadTexture(backgroundOfTable);
	for (int i = 0; i < elementsStrings.size(); i++)
	{
		UnloadTexture(elementsTextures[i]);
	}
	for (int i = 0; i < metalsHolders.size(); i++)
	{
		UnloadTexture(metalsHolders[i]);
	}
	for (int i = 0; i < nonmetalsHolders.size(); i++)
	{
		UnloadTexture(nonmetalsHolders[i]);
	}
}

void SplitElements::drawAndMoveElementsAndHolders(bool& loadMiniGame)
{
	mousepoint = GetMousePosition();


	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousepoint, backButton))
	{
		loadMiniGame = false;
	}

	DrawTexture(backgroundOfTable, 0, 0, WHITE);

	DrawText("Metals", WIDTH / 12.9, HEIGHT / 10, WIDTH / 54.85f, BLACK);
	DrawText("Nonmetals", WIDTH - WIDTH / 6.4, HEIGHT / 10, WIDTH / 54.85f, BLACK);


	//draw the boxes of the elements
	for (int i = 0; i < 4; i++)
	{
		DrawRectangleRec(elementsInTheBoxRec2[i], BLANK);
		DrawRectangleRec(elementsInTheBoxRec[i], BLANK);

		DrawRectangleRec(elementsInTheHolders[i], BLANK);
		DrawRectangleRec(elementsInTheHolders2[i], BLANK);
	}

	//draw the textures before the users chosse metal or nonmetal
	for (int i = 0; i < elementsTextures.size(); i++)
	{
		if (i < 4)
		{
			DrawTexture(elementsTextures[i], elementsInTheBoxRec2[i].x - WIDTH / 100, elementsInTheBoxRec2[i].y, WHITE);
		}
		else
		{
			DrawTexture(elementsTextures[i], elementsInTheBoxRec[i - 4].x - WIDTH / 100, elementsInTheBoxRec[i - 4].y, WHITE);
		}
	}

	//draw the textures after the users chosse metal or nonmetal
	for (int i = 0; i < metalsHolders.size(); i++)
	{
		DrawTexture(metalsHolders[i], elementsInTheHolders[i].x - WIDTH / 115, elementsInTheHolders[i].y - HEIGHT / 150, WHITE);
	}

	for (int i = 0; i < nonmetalsHolders.size(); i++)
	{
		DrawTexture(nonmetalsHolders[i], elementsInTheHolders2[i].x - WIDTH / 135, elementsInTheHolders2[i].y, WHITE);
	}

	if (chooseMetalOrNonmetal)
	{
		for (int i = 0; i < 2; i++)
		{
			DrawRectangleRec(choice[i], BLACK);
			DrawTexture(choiceOfMetalOtNonmetal[i], WIDTH / 2.82 + i * WIDTH / 6.4, HEIGHT / 1.44, WHITE);
		}

		//if you choose metal if statemant
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousepoint, choice[0]))
		{
			//if the 4 slots are not full
			if (metalsHolders.size() < 4 && elementsStrings[saverForIndexOfElement] != "")
			{
				//puts the element in the holder and in the checker and delete it from its previous place
				metalsHolders.push_back(elementsTextures[saverForIndexOfElement]);
				checkerForMetals.push_back(elementsStrings[saverForIndexOfElement]);
				elementsTextures[saverForIndexOfElement] = Texture2D();
				elementsStrings[saverForIndexOfElement] = "";
			}
			chooseMetalOrNonmetal = false;
		}

		//if you choose nonmetal if statemant
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousepoint, choice[1]))
		{
			//if the 4 slots are not full
			if (nonmetalsHolders.size() < 4 && elementsStrings[saverForIndexOfElement] != "")
			{

				//puts the element in the holder and delete it from its previous place
				nonmetalsHolders.push_back(elementsTextures[saverForIndexOfElement]);
				elementsTextures[saverForIndexOfElement] = Texture2D();
				elementsStrings[saverForIndexOfElement] = "";
			}
			//leave the if
			chooseMetalOrNonmetal = false;
		}
	}
	else
	{
		//go to choice of metal or not and save index for it
		for (int i = 0; i < 4; i++)
		{
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousepoint, elementsInTheBoxRec2[i]))
			{
				saverForIndexOfElement = i;
				chooseMetalOrNonmetal = true;
			}

			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousepoint, elementsInTheBoxRec[i]))
			{
				saverForIndexOfElement = i + 4;
				chooseMetalOrNonmetal = true;
			}
		}
	}

	DrawRectangleRec(backButton, BLANK);
	DrawTexture(backbuttonTexture, WIDTH / 2.25, HEIGHT / 18, WHITE);
}

//checks if they are actually metals and nonmetals
bool SplitElements::checkElements()
{

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			// Compare the file paths using the == operator
			if (checkerForMetals[i] == metalElementsStrings[j])
			{
				++counter;
				break;
			}
		}
	}

	//if you did right you earn money if not then RUN the teacher starts to chase you
	return (counter == 4);

}