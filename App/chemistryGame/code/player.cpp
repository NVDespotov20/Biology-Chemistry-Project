#include "pchGame.hpp"
#include "Player.hpp"

void Player::joinInRoom()
{
	CheckDir();
	Movement();

	//draw player
	DrawTexturePro(playerSprite, view, move, Vector2{ WIDTH / 192, HEIGHT / 108 }, 0, WHITE);

}
void Player::LoadSprites(int fps)
{

	playerSprites = {
		 LoadTexture("../assets/images/heroSprite/walkLeft.png"),
		 LoadTexture("../assets/images/heroSprite/walkRight.png"),
		 LoadTexture("../assets/images/heroSprite/WalkUp.png"),
		 LoadTexture("../assets/images/heroSprite/WalkDown.png"),
	};

	idleSprites = {
		LoadTexture("../assets/images/heroSprite/IdleLeft.png"),
		LoadTexture("../assets/images/heroSprite/IdleRight.png"),
		LoadTexture("../assets/images/heroSprite/IdleUp.png"),
		LoadTexture("../assets/images/heroSprite/IdleFront.png")
	};

	for (auto& sprites : playerSprites)
	{
		sprites.width = WIDTH / 4.923f;
		sprites.height = HEIGHT / 7.552f;
	}

	for (auto& sprites : idleSprites)
	{
		sprites.width = WIDTH / 9.846f;
		sprites.height = HEIGHT / 7.552f;
	}

	lim = (float)idleSprites[0].width / 2;
	view = { lim, 0, (float)idleSprites[0].width / 2, (float)idleSprites[0].height };

	this->fps = fps;
}

//player load
Player::Player()
{

	WIDTH = GetScreenWidth();
	HEIGHT = GetScreenHeight();
	playerCords.x = GetScreenWidth() / 2;
	playerCords.y = GetScreenHeight() / 2;
	HorizotnalOrVertical[0] = 0;
	HorizotnalOrVertical[1] = 0;
	speed = { WIDTH / 19.2f,  HEIGHT / 10.8f};
	animationSpeed = 6;
	HeroDir = LEFT;
}

Player::~Player()
{
	UnLoadTextures();
}

//switch sprite when button is clicked
void Player::CheckDir()
{

	if ((IsKeyDown(KEY_UP) or IsKeyDown(KEY_W)) && !(playerCords.y <= HEIGHT / 10))
	{
		playerCords.y -= speed.y * GetFrameTime();
		HeroDir = UP;

		HorizotnalOrVertical[1] = 1;
	}
	else if ((IsKeyDown(KEY_DOWN) or IsKeyDown(KEY_S)) && !(playerCords.y >= GetScreenHeight() - (playerSprite.height + HEIGHT / 7.f)))
	{
		playerCords.y += speed.y * GetFrameTime();

		HeroDir = DOWN;
		HorizotnalOrVertical[1] = 1;

	}
	else {
		HorizotnalOrVertical[1] = 0;
	}

	if ((IsKeyDown(KEY_LEFT) or IsKeyDown(KEY_A)) && !(playerCords.x <= WIDTH / 10))
	{
		playerCords.x -= speed.x * GetFrameTime();
		HeroDir = LEFT;
		HorizotnalOrVertical[0] = 1;

	}
	else if ((IsKeyDown(KEY_RIGHT) or IsKeyDown(KEY_D)) && !(playerCords.x >= GetScreenWidth() - WIDTH / 7))
	{
		playerCords.x += speed.x * GetFrameTime();
		HeroDir = RIGHT;
		HorizotnalOrVertical[0] = 1;

	}
	else {
		HorizotnalOrVertical[0] = 0;
	}

}

void Player::Movement()
{
	if (HorizotnalOrVertical[0] || HorizotnalOrVertical[1])
	{
		animationSpeed = 6;
		playerSprite = playerSprites.at(int(HeroDir));
	}
	else if (!HorizotnalOrVertical[0] && !HorizotnalOrVertical[1])
	{
		animationSpeed = 4;
		playerSprite = idleSprites.at(int(HeroDir));
	}

	if (HorizotnalOrVertical[0] && HorizotnalOrVertical[1])
		speed = { WIDTH / 21.3f, HEIGHT / 12.f };
	else
		speed = { WIDTH / 12.8f, HEIGHT / 7.2f};


	//frames
	if (counter >= fps / animationSpeed)
	{
		view.x += lim;
		counter = 0;
	}
	if (abs(view.x) > playerSprite.width)
	{
		view.x = lim;
	}
	counter++;

	move = Rectangle{ playerCords.x, playerCords.y, lim, (float)playerSprite.height };
}
void Player::UnLoadTextures()
{
	for (auto& texture : playerSprites) {
		UnloadTexture(texture);
	}
	for (auto& texture : idleSprites) {
		UnloadTexture(texture);
	}
}