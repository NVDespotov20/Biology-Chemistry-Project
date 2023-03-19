#pragma once
#include "Inventory.hpp"
class Player : public InventorySystem
{
private:
	Texture2D u;
	Texture2D d;
	Texture2D r;
	Texture2D l;

	Texture2D idleU;
	Texture2D idleD;
	Texture2D idleR;
	Texture2D idleL;

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
	bool MoveBg;
	Vector2 playerCords;
	Rectangle move;
	Texture2D playerSprite;
	Rectangle view;

	Player();
	void LoadSprites(int fps);
	void Movement();
	void CheckDir();
	void CheckWalls();
	void UnLoadTextures();
};