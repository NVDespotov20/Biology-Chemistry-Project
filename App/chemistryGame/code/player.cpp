#include "pchGame.hpp"
#include "Player.hpp"

void Player::join()
{
	CheckDir();
	Movement();

	//draw player
	DrawTexturePro(playerSprite, view, move, Vector2{ 10, 10 }, 0, WHITE);

}
void Player::LoadSprites(int fps)
{
	//player textures
	/*down = LoadTexture("../assets/images/heroSprite/WalkDown.png");
	up = LoadTexture("../assets/images/heroSprite/WalkUp.png");
	left = LoadTexture("../assets/images/heroSprite/walkLeft.png");
	right = LoadTexture("../assets/images/heroSprite/walkRight.png");*/

	//idle textures
	/*idleD = LoadTexture("../assets/images/heroSprite/IdleFront.png");
	idleU = LoadTexture("../assets/images/heroSprite/IdleUp.png");
	idleL = LoadTexture("../assets/images/heroSprite/IdleLeft.png");
	idleR = LoadTexture("../assets/images/heroSprite/IdleRight.png");*/

	playerSprites = {
		 LoadTexture("../assets/images/heroSprite/walkLeft.png"),
		 LoadTexture("../assets/images/heroSprite/walkRight.png"),
		 LoadTexture("../assets/images/heroSprite/WalkUp.png"),
		 LoadTexture("../assets/images/heroSprite/WalkDown.png"),
	};

	for (auto& sprites : playerSprites)
	{
		sprites.width = 390;
		sprites.height = 143;
	}

	idleSprites = {
		LoadTexture("../assets/images/heroSprite/IdleLeft.png"),
		LoadTexture("../assets/images/heroSprite/IdleRight.png"),
		LoadTexture("../assets/images/heroSprite/IdleUp.png"),
		LoadTexture("../assets/images/heroSprite/IdleFront.png")
	};

	for (auto& sprites : idleSprites)
	{
		sprites.width = 195;
		sprites.height = 143;
	}

	lim = (float)idleSprites[0].width / 2;
	view = { lim, 0, (float)idleSprites[0].width / 2, (float)idleSprites[0].height };

	this->fps = fps;
}

//player load
Player::Player()
{
	playerCords.x = GetScreenWidth() / 2;
	playerCords.y = GetScreenHeight() / 2;
	HorizotnalOrVertical[0] = 0;
	HorizotnalOrVertical[1] = 0;
	speed.x = 100;
	speed.y = 100;
	animationSpeed = 6;
	HeroDir = LEFT;
}

Player::~Player()
{
	UnLoadTextures();
}
////find if the player is colliding item
//bool findDistance(Player& player, int posX, int posY)
//{
//
//	if (abs(player.playerCords.x - (posX + player.XBg)) <= player.enemyDistance && abs(player.playerCords.y - (posY + player.YBg)) <= player.enemyDistance)
//	{
//		return 1;
//	}
//	else {
//		return 0;
//	}
//}

//switch sprite when button is clicked
void Player::CheckDir()
{

	CheckWalls();
	if ((IsKeyDown(KEY_UP) or IsKeyDown(KEY_W)) && !(playerCords.y <= 20))
	{
		playerCords.y -= speed.y * GetFrameTime();
		HeroDir = UP;

		HorizotnalOrVertical[1] = 1;
	}
	else if ((IsKeyDown(KEY_DOWN) or IsKeyDown(KEY_S)) && !(playerCords.y >= GetScreenHeight() - playerSprite.height))
	{
		playerCords.y += speed.y * GetFrameTime();

		HeroDir = DOWN;
		HorizotnalOrVertical[1] = 1;

	}
	else {

		HorizotnalOrVertical[1] = 0;
	}

	if ((IsKeyDown(KEY_LEFT) or IsKeyDown(KEY_A)) && !(playerCords.x <= 0))
	{
		playerCords.x -= speed.x * GetFrameTime();
		HeroDir = LEFT;
		HorizotnalOrVertical[0] = 1;

	}
	else if ((IsKeyDown(KEY_RIGHT) or IsKeyDown(KEY_D)) && !(playerCords.x >= GetScreenWidth() - 100))
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

	if (HorizotnalOrVertical[0] && HorizotnalOrVertical[1]) {

		speed.x = 90;
		speed.y = 90;
	}
	else
	{
		speed.x = 150;

		speed.y = 150;
	}


	//flames
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
void Player::CheckWalls()
{
	/*for (int i = 0; i < walls.size(); i++) {
		if (CheckCollisionRecs(move, walls.at(i))) {
			if(i == 2)
			{
				if ((HorizotnalOrVertical[0] || HorizotnalOrVertical[1]) || (HorizotnalOrVertical[0] && HorizotnalOrVertical[1])){
					speed.x = 0;
					speed.y = 200;
				}
				else {
					speed.x = 200;
					speed.y = 0;
				}
			}
			else {
				if (HorizotnalOrVertical[0] || HorizotnalOrVertical[1]){
					speed.x = 200;
					speed.y = 0;
				}
				else {
					speed.x = 0;
					speed.y = 200;
				}
			}
		}
	}*/
}
void Player::UnLoadTextures()
{
	UnloadTexture(down);
	UnloadTexture(left);
	UnloadTexture(right);
	UnloadTexture(up);

	UnloadTexture(idleD);
	UnloadTexture(idleL);
	UnloadTexture(idleR);
	UnloadTexture(idleU);
}