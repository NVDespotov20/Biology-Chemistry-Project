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

	holders[0] = { WIDTH / 17.5f,WIDTH / 10.f,WIDTH / 6.75f,WIDTH / 2.f - WIDTH / 5 };
	holders[1] = { WIDTH/1.25f,WIDTH / 10.f,WIDTH / 6.75f,WIDTH / 2.f - WIDTH / 5 };

	naElement = LoadTexture("../../assets/images/chemistry/Soldium(Na).png");
	sElement = LoadTexture("../../assets/images/chemistry/Sulfur(S).png");
	agElement = LoadTexture("../../assets/images/chemistry/Silver(Ag).png");
	pElement = LoadTexture("../../assets/images/chemistry/Phosphorus(P).png");
	cElement = LoadTexture("../../assets/images/chemistry/Carbon(C).png");
	auElement = LoadTexture("../../assets/images/chemistry/Gold(Au).png");
	clElement = LoadTexture("../../assets/images/chemistry/Chlorine(Cl2).png");
	cuElement = LoadTexture("../../assets/images/chemistry/Copper(Cu).png");
	znElement = LoadTexture("../../assets/images/chemistry/Zinc(Zn).png");	/*
	naElement = LoadTexture("../../assets/images/chemistry/Na.png");
	naElement = LoadTexture("../../assets/images/chemistry/Na.png");*/

	metalElementsTextures.push_back(naElement);
	metalElementsTextures.push_back(agElement);
	metalElementsTextures.push_back(cuElement);
	metalElementsTextures.push_back(auElement);
	metalElementsTextures.push_back(znElement);

	nonmetalElementsTextures.push_back(clElement);
	nonmetalElementsTextures.push_back(sElement);
	nonmetalElementsTextures.push_back(cElement);
	nonmetalElementsTextures.push_back(pElement);

	backgroundOfTable = LoadTexture("../../assets/images/chemistry/ArrangeTableBackground.png");

	backgroundOfTable.width = GetScreenWidth();
	backgroundOfTable.height = GetScreenHeight();

	seed = std::chrono::steady_clock::now().time_since_epoch().count();

	gen.seed(seed);

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
	}
}

SplitElements::~SplitElements()
{

}

void SplitElements::drawElementsAndHolders()
{
	DrawTexture(backgroundOfTable, 0, 0, WHITE);

	DrawRectangleRec(holders[0], RED);
	DrawRectangleRec(holders[1], RED);

	for (int i = 0; i <4; i++)
	{
		DrawRectangleRec(elementsInTheBoxRec2[i], BLANK);
		DrawRectangleRec(elementsInTheBoxRec[i], BLANK);

		DrawTexture(elementsTextures[i], WIDTH / 3.92 + i * 250, HEIGHT / 4, WHITE);
		DrawTexture(elementsTextures[i+4], WIDTH / 3.92 + i * 250, HEIGHT / 4 + (HEIGHT / 4), WHITE);
	}
}