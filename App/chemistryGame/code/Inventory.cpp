#include "pchGame.hpp"
#include "Inventory.hpp"

InventorySystem::InventorySystem()
{
	WIDTH = GetScreenWidth();
	HEIGHT = GetScreenHeight();
	inventory = LoadTexture("../../assets/images/UI elements/inventory.png");
	item = LoadTexture("../../assets/images/UI elements/item.png");
	item.width = 50;
	item.height = 50;
	inventoryRect = { 0,0, (float)inventory.width, (float)inventory.height };

	//random seed using chrono library
	seed = std::chrono::steady_clock::now().time_since_epoch().count();

	v1.resize(4);
	v2.resize(4);

	gen.seed(seed);

	range = std::uniform_int_distribution<int>(1, WIDTH - WIDTH / 17);
	range2 = std::uniform_int_distribution<int>(1, HEIGHT - HEIGHT / 15);

	for (int i = 0; i < v1.size(); i++)
	{
		//filling the vector and printing the random numbers
		v1[i] = range(gen);
		v2[i] = range2(gen);
		std::cout << v1[i] << std::endl;
	}

	normalItemsPos = {
		{v1[0], v2[0]},
		{v1[1], v2[1]},
		{v1[2], v2[2]},
		{v1[3], v2[3]}
	};
}

InventorySystem::~InventorySystem()
{
	UnloadTexture(inventory);
	UnloadTexture(item);
}

bool InventorySystem::isPickedUp(Vector2 heroPosition)
{
	for (int i = 0; i < normalItemsPos.size(); i++)
	{
		if (CheckCollisionPointCircle(heroPosition, normalItemsPos[i], 150))
		{
			DrawTextureV(item, normalItemsPos[i], Fade(WHITE, 1));
			if (IsKeyPressed(KEY_Q))
			{
				itemsInInventoryPos.push_back(normalItemsPos[i]);
				normalItemsPos.erase(normalItemsPos.begin() + i);
			}
		}
	}
	return true;
}
void InventorySystem::drawInventory()
{
	DrawTextureRec(inventory, inventoryRect, { 200, 100 }, WHITE);
}
void InventorySystem::drawnormalItems()
{
	for (auto& position : normalItemsPos)
	{

		DrawTextureV(item, position, Fade(WHITE, 0.5f));
	}
}
void InventorySystem::drawItemsInInventory()
{
	for (auto& position : itemsInInventoryPos)
	{
		DrawTextureV(item, position, WHITE);
	}

}