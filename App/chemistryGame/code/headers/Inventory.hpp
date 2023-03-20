#pragma once

class InventorySystem
{ 
public:
	//constructor initialization
	InventorySystem();
	//destructor intialization
	~InventorySystem();

	//initialization of textures
	Texture2D inventory;
	Texture2D item;

	//initialization of rectangles
	Rectangle inventoryRect;

	//seed that we make different every time
	unsigned seed;

	//random engine from random library
	std::mt19937 gen;

	//making the range of the number that will be generated
	std::uniform_int_distribution<int> range;
	std::uniform_int_distribution<int> range2;

	//vectors that hold the random positions of the items
	std::vector<float> v1;
	std::vector<float> v2;

	//vectors for the position of the items
	std::vector<Vector2> itemsInInventoryPos;
	std::vector<Vector2> normalItemsPos;

	//only the position IN the inventory
	Vector2 positionOfItemsInInventory;

	void drawInventory();
	void drawnormalItems();
	bool isPickedUp(Vector2 heroPos);
private:
	int WIDTH;
	int HEIGHT;
};