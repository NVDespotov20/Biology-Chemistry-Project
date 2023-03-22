#include "pchGame.hpp"
#include "SplitElements.hpp"

SplitElements::SplitElements()
{
	WIDTH = GetScreenWidth();
	HEIGHT = GetScreenHeight();

	positionOfMetalsHolder[0] = HEIGHT - HEIGHT / 1.25;
	positionOfMetalsHolder[1] = HEIGHT - HEIGHT / 1.5;
	positionOfMetalsHolder[2] = HEIGHT - HEIGHT / 2;
	positionOfMetalsHolder[3] = HEIGHT - HEIGHT / 2.25;

	positionOfNonMetalsHolder[0] = HEIGHT - HEIGHT / 1.25;
	positionOfNonMetalsHolder[1] = HEIGHT - HEIGHT / 1.5;
	positionOfNonMetalsHolder[2] = HEIGHT - HEIGHT / 2;
	positionOfNonMetalsHolder[3] = HEIGHT - HEIGHT / 2.25;

	naElement = LoadTexture("../assets/images/chemistry/Soldium(Na).png");
	sElement = LoadTexture("../assets/images/chemistry/Sulfur(S).png");
	agElement = LoadTexture("../assets/images/chemistry/Silver(Ag).png");
	pElement = LoadTexture("../assets/images/chemistry/Phosphorus(P).png");
	cElement = LoadTexture("../assets/images/chemistry/Carbon(C).png");
	auElement = LoadTexture("../assets/images/chemistry/Gold(Au).png");
	clElement = LoadTexture("../assets/images/chemistry/Chlorine(Cl2).png");
	cuElement = LoadTexture("../assets/images/chemistry/Copper(Cu).png");
	znElement = LoadTexture("../assets/images/chemistry/Zinc(Zn).png");	/*
	naElement = LoadTexture("../assets/images/chemistry/Na.png");
	naElement = LoadTexture("../assets/images/chemistry/Na.png");*/

	metalElementsTextures.push_back(naElement);
	metalElementsTextures.push_back(agElement);
	metalElementsTextures.push_back(cuElement);
	metalElementsTextures.push_back(auElement);
	metalElementsTextures.push_back(znElement);

	nonmetalElementsTextures.push_back(clElement);
	nonmetalElementsTextures.push_back(sElement);
	nonmetalElementsTextures.push_back(cElement);
	nonmetalElementsTextures.push_back(pElement);

	mousepoint = GetMousePosition();

	backgroundOfTable = LoadTexture("../assets/images/chemistry/ArrangeTableBackground.png");

	backgroundOfTable.width = GetScreenWidth();
	backgroundOfTable.height = GetScreenHeight();

	seed = std::chrono::steady_clock::now().time_since_epoch().count();

	gen.seed(seed);

	chooseMetalOrNonmetal = false;

	for (int i = 0; i < metalElementsTextures.size(); i++)
	{
		metalElementsTextures[i].width = WIDTH / 10;
		metalElementsTextures[i].height = HEIGHT / 7;
	}
	
	for (int i = 0; i < nonmetalElementsTextures.size(); i++)
	{
		nonmetalElementsTextures[i].width = WIDTH / 10;
		nonmetalElementsTextures[i].height = HEIGHT / 7;
	}

	std::shuffle(metalElementsTextures.begin(), metalElementsTextures.end(), gen);
	std::shuffle(nonmetalElementsTextures.begin(), nonmetalElementsTextures.end(), gen);

	for (int i = 0; i < 8; i++)
	{
		if (i < 4)
		{
			elementsTextures.push_back(metalElementsTextures[i]);
		}
		else
		{
			elementsTextures.push_back(nonmetalElementsTextures[i-4]);
		}
	}

	std::shuffle(elementsTextures.begin(), elementsTextures.end(), gen);

	for (int i = 0; i < 4; i++)
	{
		elementsInTheBoxRec[i] = { WIDTH / 3.80f + i * 250, HEIGHT / 4.f + (HEIGHT / 4), WIDTH/12.f, HEIGHT/7.f};
		elementsInTheBoxRec2[i] = { WIDTH / 3.80f + i * 250, HEIGHT / 4.5f + (HEIGHT / 40), WIDTH / 12.f, HEIGHT / 7.f };

		elementsInTheHolders[i] = { WIDTH / 15.f,HEIGHT / 6.f + i * 200,WIDTH / 12.2f,HEIGHT / 7.f };
		elementsInTheHolders2[i] = { WIDTH - WIDTH / 6.5f,HEIGHT / 6.f + i * 200,WIDTH / 12.f,HEIGHT / 7.f };
	}

	for (int i = 0; i < 2; i++)
	{
		choice[i] = {WIDTH/15.f + i*900,HEIGHT/6.f,WIDTH/2-WIDTH/9.46f,HEIGHT/1.367f};
	}
}

SplitElements::~SplitElements()
{
	unload();
}

void SplitElements::unload()
{
	UnloadTexture(naElement);
	UnloadTexture(sElement);
	UnloadTexture(agElement);
	UnloadTexture(pElement);
	UnloadTexture(cElement);
	UnloadTexture(auElement);
	UnloadTexture(clElement);
	UnloadTexture(cuElement);
	UnloadTexture(znElement);
	UnloadTexture(backgroundOfTable);
	//UnloadTexture();
}

void SplitElements::drawAndMoveElementsAndHolders()
{
	mousepoint = GetMousePosition();

	DrawTexture(backgroundOfTable, 0, 0, WHITE);

	DrawText("Metals", WIDTH / 12.9, HEIGHT / 10, 35, BLACK);
	DrawText("Nonmetals", WIDTH - WIDTH / 6.4, HEIGHT / 10, 35, BLACK);

	for (int i = 0; i < 4; i++)
	{
		DrawRectangleRec(elementsInTheBoxRec2[i], RED);
		DrawRectangleRec(elementsInTheBoxRec[i], ORANGE);

		DrawRectangleRec(elementsInTheHolders[i], GREEN);
		DrawRectangleRec(elementsInTheHolders2[i], BLUE);
	}

	for (int i = 0; i < elementsTextures.size(); i++)
	{
		if (i < 4)
		{
			DrawTexture(elementsTextures[i], elementsInTheBoxRec2[i].x, elementsInTheBoxRec2[i].y, WHITE);
		}
		else
		{
			DrawTexture(elementsTextures[i], elementsInTheBoxRec[i-4].x, elementsInTheBoxRec[i-4].y, WHITE);
		}
	}

	for (int i = 0; i < metalsHolders.size(); i++)
	{
		DrawTexture(metalsHolders[i], elementsInTheHolders[i].x, elementsInTheHolders[i].y, WHITE);
	}

	for (int i = 0; i < nonmetalsHolders.size(); i++)
	{
		DrawTexture(nonmetalsHolders[i], elementsInTheHolders2[i].x, elementsInTheHolders2[i].y, WHITE);
	}

	for (int i = 0; i < 4; i++)
	{
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousepoint, elementsInTheBoxRec2[i]))
		{
			saverForIndexOfElement = i;
			chooseMetalOrNonmetal = true;
		}

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousepoint, elementsInTheBoxRec[i]))
		{
			saverForIndexOfElement = i+4;
			chooseMetalOrNonmetal = true;
		}
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

		if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT) && CheckCollisionPointRec(mousepoint, choice[0]))
		{
			if (metalsHolders.size() < 4)
			{
				metalsHolders.push_back(elementsTextures[saverForIndexOfElement]);
				elementsTextures.erase(elementsTextures.begin() + saverForIndexOfElement);
			}
			chooseMetalOrNonmetal = false;
		}

		if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT) && CheckCollisionPointRec(mousepoint, choice[1]))
		{
			if (nonmetalsHolders.size() < 4)
			{
				nonmetalsHolders.push_back(elementsTextures[saverForIndexOfElement]);
				elementsTextures.erase(elementsTextures.begin() + saverForIndexOfElement);
			}
			chooseMetalOrNonmetal = false;
		}
	}
}