#pragma once

class InventorySystem
{ 
public:
	InventorySystem();
	~InventorySystem();

	Texture2D inventory;
	Texture2D item;

	Rectangle inventoryRect;

	unsigned seed;

	//random engine from random library
	std::mt19937 gen;

	//making the range of the number that will be generated
	std::uniform_int_distribution<int> range;
	std::uniform_int_distribution<int> range2;

	std::vector<float> v1;
	std::vector<float> v2;

	//Vector2 itemPos;
	std::vector<Vector2> itemsInInventoryPos;
	std::vector<Vector2> normalItemsPos;

	void drawInventory();
	void drawnormalItems();
	void drawItemsInInventory();
	bool isPickedUp(Vector2 heroPos);
private:
	int WIDTH;
	int HEIGHT;
};