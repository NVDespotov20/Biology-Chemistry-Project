#include "pchGame.hpp"
#include "Teacher.hpp"

Teacher::Teacher()
{
	counterFrameIdle = 0;
	counterFrameChasing = 0;
	speed = 100;
	position = { 500, 600 };
	isSeen = 0;
}

Teacher::~Teacher()
{
	UnloadTexture(left);
	UnloadTexture(right);
}
//implement singleton
std::shared_ptr<Teacher> Teacher::instantiate_ = nullptr;

std::shared_ptr<Teacher> Teacher::getInstantiation()
{
	if (instantiate_ == nullptr) {
		instantiate_ = std::shared_ptr<Teacher>(new Teacher);
	}
	return instantiate_;
}
void Teacher::setActive(bool state)
{
	isSeen = state;
}
void Teacher::LoadSprites()
{
	left = LoadTexture("../assets/images/heroSprite/left.png");
	right = LoadTexture("../assets/images/heroSprite/right.png");
	idle = LoadTexture("../assets/images/heroSprite/downIdle.png");

	teacherTextureIdle = idle;
	teacherTextureChasing = right;

	SpasNPCViewChasing = { (float)teacherTextureChasing.width / 4, 0, (float)teacherTextureChasing.width / 4, (float)teacherTextureChasing.height };
	SpasNPCViewIdle = { (float)teacherTextureIdle.width / 2, 0, (float)teacherTextureIdle.width / 2, (float)teacherTextureIdle.height };
}

void Teacher::draw()
{
	//chasing animation
	if (counterFrameChasing >= 20)
	{
		SpasNPCViewChasing.x += teacherTextureChasing.width / 4;
		counterFrameChasing = 0;
	}
	if (abs(SpasNPCViewChasing.x) > teacherTextureChasing.width)
	{
		SpasNPCViewChasing.x = teacherTextureChasing.width / 4;
	}
	counterFrameChasing++;

	//idle
	if (counterFrameIdle >= 20)
	{
		SpasNPCViewIdle.x += teacherTextureIdle.width / 2;
		counterFrameIdle = 0;
	}
	if (abs(SpasNPCViewIdle.x) > teacherTextureIdle.width)
	{
		SpasNPCViewIdle.x = teacherTextureIdle.width / 2;
	}
	counterFrameIdle++;

	if (isSeen)
		DrawTextureRec(teacherTextureChasing, SpasNPCViewChasing, Vector2{ position.x, position.y }, WHITE);
	else
		DrawTextureRec(teacherTextureIdle, SpasNPCViewIdle, Vector2{ position.x, position.y }, WHITE);

}
void Teacher::changePosition(Vector2 newPos)
{
	position = newPos;
}
void Teacher::update(Vector2 posHero, Rectangle heroRec)
{
	//check if a player is near teacher
	//(CheckCollisionPointCircle(posHero, position, 300)) ? isSeen = 1 : isSeen = 0;

	if (isSeen)
	{
		(position.x > posHero.x) ? teacherTextureChasing = left : teacherTextureChasing = right;

		if (CheckCollisionPointCircle(position, posHero, 50))
		{
			// Insert among us kill animation here
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
		teacherTextureIdle = idle;
	}
}
