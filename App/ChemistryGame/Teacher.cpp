#include"Teacher.hpp"

Teacher::Teacher()
{
	counterFlip = 0;
	counterFrame = 0;
	speed = 100;
	position.x = 1000;
	position.y = 1000;
	isSeen = 0;
}

void Teacher::LoadSprites()
{
	l = LoadTexture("../assets/images/heroSprite/left.png");
	r = LoadTexture("../assets/images/heroSprite/right.png");
	l = LoadTexture("../assets/images/rivalSprite/left.png");
	r = LoadTexture("../assets/images/rivalSprite/right.png");

	SpasNPC = r;
	SpasNPCView = { (float)SpasNPC.width / 4, 0, (float)SpasNPC.width / 4, (float)SpasNPC.height };
	positionRec = { 500, 900, (float)SpasNPC.width / 4, (float)SpasNPC.height };

}

void Teacher::Draw(int xBg, int yBg, bool check)
{
	if (counterFrame >= 20)
	{
		SpasNPCView.x += SpasNPC.width / 4;
		counterFrame = 0;
	}
	if (abs(SpasNPCView.x) > SpasNPC.width)
	{
		SpasNPCView.x = SpasNPC.width / 4;
	}
	counterFrame++;

	if (isSeen)
	{
		DrawTextureRec(SpasNPC, SpasNPCView, Vector2{ position.x, position.y }, WHITE);
	}
}

void Teacher::Update(Vector2 posHero, int xBg, int yBg, Rectangle heroRec)
{
	if (speed < 0 && !isSeen)
	{
		position = { position.x + xBg, position.y + yBg };

		if (CheckCollisionCircleRec(posHero, 100, positionRec) && !isSeen) 
		{
			isSeen = 1;
		}

		if (isSeen)
		{
			if (position.x > posHero.x) {
				SpasNPC = l;
				(position.x > posHero.x) ? SpasNPC = l : SpasNPC = r;

				if (CheckCollisionRecs(positionRec, heroRec))
				{
					std::cout << "exit the game" << std::endl;
				}
				else {
					SpasNPC = r;
					isSeen = 1;
				}
				isSeen = 1;
			}
			else
			{
				isSeen = 0;
				if (position.x > 2000)
				{
					if (position.x > 800)
					{
						if (counterFlip > 60)
						{
							SpasNPC = l;
							speed = -100;
						}
						else
						{
							speed *= 0;
						}
						counterFlip++;
					}
					else if (position.x < 450)
					{
						if (counterFlip > 60) {
							SpasNPC = r;
							speed = 100;
						}
						else {
							speed *= 0;
						}
						counterFlip++;
					}
					position.x += speed * GetFrameTime();
				}
			}
		}
	}
}
