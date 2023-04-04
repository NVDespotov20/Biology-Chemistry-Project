#include "pchGame.hpp"
#include "Inventory.hpp"

InventorySystem::InventorySystem()
{
	//variables that we use to make everything responsive
	WIDTH = GetScreenWidth();
	HEIGHT = GetScreenHeight();

	//the position where the first item is placed in the inventory
	positionOfItemsInInventory = { WIDTH / 3.f, HEIGHT / 2.333f };
	
}
std::shared_ptr<InventorySystem> InventorySystem::instantiate_ = nullptr;

std::shared_ptr<InventorySystem> InventorySystem::getInstantiation()
{
	if (instantiate_ == nullptr) {
		instantiate_ = std::shared_ptr<InventorySystem>(new InventorySystem);
	}
	return instantiate_;
}
//destructor - unloads textures
InventorySystem::~InventorySystem()
{
	UnloadTexture(inventory);
	
}
bool InventorySystem::isPickedUp(Rectangle heroPosition,Texture2D&item, std::vector<Vector2> &normalItemsPos)
{
	for (int i = 0; i < normalItemsPos.size(); i++)
	{
		//checks if you are close to the items
		if (!CheckCollisionCircleRec(normalItemsPos[i], WIDTH / 25, heroPosition))
			continue;
		//draw items that you are close and you can pick up without any opacity 
		DrawTextureV(item, normalItemsPos[i], Fade(WHITE, 1));
		if (!IsKeyPressed(KEY_Q))
			continue;

		//transfer items into inventory 
		itemsInInventoryPos.push_back(positionOfItemsInInventory);
		//make the next item position to move 150 on right 
		positionOfItemsInInventory.x = positionOfItemsInInventory.x + WIDTH / 15;
		//remove items from the ground
		normalItemsPos.erase(normalItemsPos.begin() + i);
	}
	return 0;
}

void InventorySystem::load()
{
	//loading textures
	inventory = LoadTexture("../assets/images/UI elements/inventory.png");
	inventoryRect = { 0,0, (float)inventory.width, (float)inventory.height };
}

void InventorySystem::drawInventory(Texture2D&item)
{
	//draw inventory background
	DrawTextureRec(inventory, inventoryRect, { WIDTH / 3.5f, HEIGHT / 5.f}, Fade(WHITE, 0.8f));

	//draw items in inventory
	for (int i = 0; i < itemsInInventoryPos.size(); i++)
	{
		DrawTextureV(item, itemsInInventoryPos[i], WHITE);
	}
}
