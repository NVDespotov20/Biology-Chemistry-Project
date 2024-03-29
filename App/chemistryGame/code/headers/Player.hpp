#pragma once
#include "DoorsManager.hpp"

class Player : public DoorsManager
{
private:

	
	float WIDTH, HEIGHT;

	std::vector<Rectangle> verticalLimits;
	std::vector<Rectangle> horizontalLimits;

	//set textures for the moving player
	Texture2D up;
	Texture2D down;
	Texture2D right;
	Texture2D left;

	//set idle animationfor the player
	Texture2D idleU;
	Texture2D idleD;
	Texture2D idleR;
	Texture2D idleL;

	//initialization of vectors
	std::vector<Texture2D> playerSprites;
	std::vector<Texture2D> idleSprites;

	int counter = 0;
	float lim;
	bool HorizotnalOrVertical[2];
	Vector2 speed;
	int animationSpeed;
	int fps;
	enum Dir {
		LEFT,
		RIGHT,
		UP,
		DOWN
	}HeroDir;
public:
	Vector2 playerCords;
	Rectangle move;
	Texture2D playerSprite;
	Rectangle view;
	Player();
	~Player();
	void LoadSprites(int fps);
	void Movement();
	void CheckDir();
	void joinInRoom();
	void UnLoadTextures();
};