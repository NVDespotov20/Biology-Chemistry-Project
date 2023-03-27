#include "pchGame.hpp"
#include "SplitElements.hpp"

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

	//strings of all elements
	elementsTexturesStrings = {
	"../assets/images/chemistry/Zinc(Zn).png",
	"../assets/images/chemistry/Copper(Cu).png",
	"../assets/images/chemistry/Silver(Ag).png",
	"../assets/images/chemistry/Gold(Au).png",
	"../assets/images/chemistry/Soldium(Na).png",
	"../assets/images/chemistry/Sulfur(S).png",
	"../assets/images/chemistry/Phosphorus(P).png",
	"../assets/images/chemistry/Carbon(C).png",
	"../assets/images/chemistry/Chlorine(Cl2).png"
	};

	//random seed for the numbers
	seed = std::chrono::steady_clock::now().time_since_epoch().count();

	//generator of new random number with the seed
	gen.seed(seed);

	//push split metals and nonmetals
	for (int i = 0; i < 5; i++)
	{
		metalElementsStrings.push_back(elementsTexturesStrings[i]);
	}

	for (int i = 5; i < 9; i++)
	{
		nonmetalElementsStrings.push_back(elementsTexturesStrings[i]);
	}

	//shuffle them to get ranodm only 4 of them
	std::shuffle(metalElementsStrings.begin(), metalElementsStrings.end(), gen);
	std::shuffle(nonmetalElementsStrings.begin(), nonmetalElementsStrings.end(), gen);

	//tracks mouse
	mousepoint = GetMousePosition();

	//loadtexture for bg
	backgroundOfTable = LoadTexture("../assets/images/chemistry/ArrangeTableBackground.png");

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

	//set sizes for each box
	for (int i = 0; i < 4; i++)
	{
		elementsInTheBoxRec[i] = { WIDTH / 3.80f + i * 250 - WIDTH / 25 - WIDTH / 550, HEIGHT / 4.f + (HEIGHT / 4), WIDTH/12.f, HEIGHT/7.f};
		elementsInTheBoxRec2[i] = { WIDTH / 3.80f + i * 250 - WIDTH / 25 - WIDTH / 550, HEIGHT / 4.5f + (HEIGHT / 40), WIDTH / 12.f, HEIGHT / 7.f };

		elementsInTheHolders[i] = { WIDTH / 15.f,HEIGHT / 6.f + i * 175,WIDTH / 12.2f,HEIGHT / 7.f };
		elementsInTheHolders2[i] = { WIDTH - WIDTH / 6.5f,HEIGHT / 6.f + i * 175,WIDTH / 12.f,HEIGHT / 7.f };
	}

	//set size for choosing metal or nonmetal
	for (int i = 0; i < 2; i++)
	{
		choice[i] = { WIDTH / 15.f + i * 900,HEIGHT / 6.f,WIDTH / 2 - WIDTH / 9.46f,HEIGHT / 1.367f };
	}

	//set size for each texture
	for (int i = 0; i < elementsTextures.size(); i++)
	{
		elementsTextures[i].width = WIDTH / 10;
		elementsTextures[i].height = HEIGHT / 7;
	}

	//set place and size for back button
	backButton = {WIDTH/2.f-WIDTH/20,HEIGHT-HEIGHT/10.f,WIDTH/10.f,HEIGHT/20.f};
	
}

//destructor
SplitElements::~SplitElements()
{
	unload();
}

//unloads everything
void SplitElements::unload()
{
	UnloadTexture(backgroundOfTable);
	for (int i = 0; i < elementsStrings.size(); i++)
	{
		UnloadTexture(elementsTextures[i]);
	}
	//UnloadTexture();
}

void SplitElements::drawAndMoveElementsAndHolders()
{
	mousepoint = GetMousePosition();

	DrawTexture(backgroundOfTable, 0, 0, WHITE);

	DrawText("Metals", WIDTH / 12.9, HEIGHT / 10, 35, BLACK);
	DrawText("Nonmetals", WIDTH - WIDTH / 6.4, HEIGHT / 10, 35, BLACK);

	DrawRectangleRec(backButton, GREEN);

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
			DrawTexture(elementsTextures[i], elementsInTheBoxRec[i-4].x - WIDTH/100, elementsInTheBoxRec[i-4].y, WHITE);
		}
	}

	//draw the textures after the users chosse metal or nonmetal
	for (int i = 0; i < metalsHolders.size(); i++)
	{
		DrawTexture(metalsHolders[i], elementsInTheHolders[i].x-WIDTH / 115, elementsInTheHolders[i].y-HEIGHT/150, WHITE);
	}

	for (int i = 0; i < nonmetalsHolders.size(); i++)
	{
		DrawTexture(nonmetalsHolders[i], elementsInTheHolders2[i].x - WIDTH / 135, elementsInTheHolders2[i].y, WHITE);
	}

	if (chooseMetalOrNonmetal)
	{
		DrawText("Metal or Nonmetal", WIDTH / 3.85, HEIGHT / 11, 100, PURPLE);

		for (int i = 0; i < 2; i++)
		{
			DrawRectangleRec(choice[i], PINK);
		}

		DrawText("Metal", WIDTH / 5.15, HEIGHT / 2.15, 110, PURPLE);
		DrawText("Nonmetal", WIDTH / 1.64, HEIGHT / 2.15, 110, PURPLE);

		//if you choose metal if statemant
		if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT) && CheckCollisionPointRec(mousepoint, choice[0]))
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
		if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT) && CheckCollisionPointRec(mousepoint, choice[1]))
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
	//chercker when we submit the task
	if (checkerForMetals.size() == 4)
		checkElements();
}

//checks if they are actually metals and nonmetals
void SplitElements::checkElements()
{
	int counter = 0;

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
	if (counter == 4)
		std::cout << "Congrats\n";
	else
		std::cout << "Too bad\n";
}