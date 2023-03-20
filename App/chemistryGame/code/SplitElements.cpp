#include "pchGame.hpp"
#include "SplitElements.hpp"

SplitElements::SplitElements()
{
	WIDTH = GetScreenWidth();
	HEIGHT = GetScreenHeight();
	
	elementsInTheBox[0] = "M";
	elementsInTheBox[1] = "M";
	elementsInTheBox[2] = "M";
	elementsInTheBox[3] = "M";
	elementsInTheBox[4] = "N";
	elementsInTheBox[5] = "N";
	elementsInTheBox[6] = "N";
	elementsInTheBox[7] = "N";

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
}

SplitElements::~SplitElements()
{

}

void SplitElements::drawElementsAndHolders()
{
	DrawRectangleRec(box, GREEN);
	DrawRectangleRec(holders[0], RED);
	DrawRectangleRec(holders[1], RED);
	for (int i = 0; i < 8; i++)
	{
		DrawText(elementsInTheBox[i].c_str(), WIDTH/4+WIDTH/20 + i*WIDTH/10, HEIGHT/3.5, 50, BLACK);
	}
}