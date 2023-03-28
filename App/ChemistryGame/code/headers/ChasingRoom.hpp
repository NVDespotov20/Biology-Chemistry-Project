#pragma once
#include "Player.hpp"
#include "Teacher.hpp"
#include "Inventory.hpp"
#include "SplitElements.hpp"
#include "Navigator.hpp"
class ChasingRoom
{
	int WIDTH;
	int HEIGHT;
	std::shared_ptr<Teacher>teacher;
	std::shared_ptr<InventorySystem>inventory;
	std::shared_ptr<SplitElements>splitElements;
	std::string stringDirHolder;
	std::shared_ptr<Player>player;
	std::shared_ptr<Navigator>dir;


	//seed that we make different every time
	Texture2D item;
	unsigned seed;

	//random engine from random library
	std::mt19937 gen;

	//making the range of the number that will be generated
	std::uniform_int_distribution<int> range;
	std::uniform_int_distribution<int> range2;

	//vectors that hold the random positions of the items
	std::vector<float> v1;
	std::vector<float> v2;


	//setting random values to the the items position
	std::vector<Vector2> normalItemsPos;
	void drawNormalItems();
	int doors;	
	bool loadMiniGame;
	Vector2 positionOfMiniGamePlace;
public:
	ChasingRoom();
	ChasingRoom(int doors);
	~ChasingRoom();
	void drawChasingRoom();
	void checkDoors();
};

