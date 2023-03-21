#include "pchGame.hpp"
#include "Teacher.hpp"

Teacher::Teacher()
{
	counterFlip = 0;
	counterFrame = 0;
	speed = 100;
	position.x = 500;
	position.y = 800;
	isSeen = 0;
}

void Teacher::LoadSprites()
{
	left = LoadTexture("../../assets/images/heroSprite/left.png");
	right = LoadTexture("../../assets/images/heroSprite/right.png");

	SpasNPC = right;
	SpasNPCView = { (float)SpasNPC.width / 4, 0, (float)SpasNPC.width / 4, (float)SpasNPC.height };
}

void Teacher::Draw()
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

void Teacher::Update(Vector2 posHero, Rectangle heroRec)
{

	if (CheckCollisionPointCircle(posHero, position, 1100) && !isSeen) {
		isSeen = 1;
	}

	if (isSeen)
	{
		(position.x > posHero.x) ? SpasNPC = left : SpasNPC = right;

		if (CheckCollisionPointCircle(position, posHero, 50))
		{
			std::cout << "exit the game" << std::endl;
		}
		else {
			isSeen = 1;
		}
		if (GetFrameTime() < 1)
		{
			float rotation = atan2(posHero.y - position.y, posHero.x - position.x);
			position.x += cos(rotation) * speed * GetFrameTime();
			position.y += sin(rotation) * speed * GetFrameTime();
		}
	}
	else
	{
		isSeen = 0;
		if (position.x > 800) {
			if (counterFlip > 60) {
				SpasNPC = left;
				speed = -100;
			}
			else {
				speed *= 0;
			}
			counterFlip++;
		}
		else if (position.x < 450) {
			if (counterFlip > 60) {
				SpasNPC = right;
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
