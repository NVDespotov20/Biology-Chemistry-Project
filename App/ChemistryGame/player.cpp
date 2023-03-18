#include"Player.hpp"

void Player::LoadSprites(int fps)
{
	d = LoadTexture("../assets/images/heroSprite/down.png");
	u = LoadTexture("../assets/images/heroSprite/up.png");
	l = LoadTexture("../assets/images/heroSprite/left.png");
	r = LoadTexture("../assets/images/heroSprite/right.png");

	//idle source
	idleD = LoadTexture("../assets/images/heroSprite/downIdle.png");
	idleU = LoadTexture("../assets/images/heroSprite/upIdle.png");
	idleL = LoadTexture("../assets/images/heroSprite/leftIdle.png");
	idleR = LoadTexture("../assets/images/heroSprite/rightIdle.png");

	playerSprites.push_back(l);
	playerSprites.push_back(r);
	playerSprites.push_back(u);
	playerSprites.push_back(d);

	idleSprites.push_back(idleL);
	idleSprites.push_back(idleR);
	idleSprites.push_back(idleU);
	idleSprites.push_back(idleD);

	lim = (float)idleD.width / 2;
	view = { lim, 0, (float)idleD.width / 2, (float)idleD.height };

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
	MoveBg = 1;
	animationSpeed = 6;
	HeroDir = LEFT;
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
	UnloadTexture(d);
	UnloadTexture(l);
	UnloadTexture(r);
	UnloadTexture(u);

	UnloadTexture(idleD);
	UnloadTexture(idleL);
	UnloadTexture(idleR);
	UnloadTexture(idleU);
}