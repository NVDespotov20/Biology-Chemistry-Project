#pragma once
class InventorySystem
{ 
public:
	InventorySystem();
	~InventorySystem();

	Texture2D inventory;
	Texture2D item;

	Rectangle inventoryRect;
	Rectangle itemRec;

	Vector2 itemPos;

	void drawInventory();
	void drawItems();
private:
	bool isPickedUp(Vector2 heroPos);
};