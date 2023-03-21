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

	box = {WIDTH/2 - WIDTH /4.f, HEIGHT/2.f-HEIGHT/3.f  ,WIDTH / 2.f, HEIGHT / 1.75f };

	naElement = LoadTexture("../../assets/images/UI elements/Na.png");

	naElement.width = WIDTH / 15;
	naElement.height = HEIGHT / 10;

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
	DrawRectangleRec(box, GREEN);
	DrawRectangleRec(holders[0], RED);
	DrawRectangleRec(holders[1], RED);

	for (int i = 0; i < 4; i++)
	{
		DrawRectangleRec(elementsInTheBoxRec2[i], RED);
		DrawRectangleRec(elementsInTheBoxRec[i], RED);
		for (int j = 0; j < 2; j++)
		{
			DrawTexture(naElement, WIDTH / 3.69 + i * 250, HEIGHT / 3.665 + j * (HEIGHT / 4), WHITE);
		}

	}
}