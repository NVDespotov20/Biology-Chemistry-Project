#include "pch.hpp"
#include "Inventory.hpp"

InventorySystem::InventorySystem()
{
	inventory = LoadTexture("../assets/images/UI elements/inventory.png");
	item = LoadTexture("../assets/images/UI elements/item.png");
	inventoryRect = {0,0, (float)inventory.width, (float)inventory.height};
	itemRec = {0,0, (float)item.width, (float)item.height};
	itemPos = {500, 500};
}

InventorySystem::~InventorySystem()
{
	UnloadTexture(inventory);
}

bool InventorySystem::isPickedUp(Vector2 heroPosition)
{
	if (IsKeyPressed(KEY_Q) && CheckCollisionPointRec(heroPosition, itemRec))
	{
		//mlukni e manqche
	}
	return true;
}
void InventorySystem::drawInventory()
{
	DrawTextureRec(inventory, inventoryRect, { 500, 500 }, WHITE);
}