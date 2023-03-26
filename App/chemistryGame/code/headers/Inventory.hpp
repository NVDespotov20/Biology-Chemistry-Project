#pragma once

class InventorySystem
{ 
public:
	//constructor initialization
	//destructor intialization
	~InventorySystem();

	//initialization of textures
	Texture2D inventory;

	//initialization of rectangles
	Rectangle inventoryRect;

	

	//vectors for the position of the items
	std::vector<Vector2> itemsInInventoryPos;

	//only the position IN the inventory
	Vector2 positionOfItemsInInventory;

	
	
	void drawInventory(Texture2D& item);
	void use();
	bool isPickedUp(Rectangle heroPos, Texture2D& item, std::vector<Vector2>& normalItemsPos);

	static std::shared_ptr<InventorySystem> getInstantiation();


private:
	InventorySystem();
	static std::shared_ptr<InventorySystem> instantiate_;
	int WIDTH;
	int HEIGHT;
};