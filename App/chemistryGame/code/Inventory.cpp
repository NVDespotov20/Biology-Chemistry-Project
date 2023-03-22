#include "pchGame.hpp"
#include "Inventory.hpp"

InventorySystem::InventorySystem()
{
	//variables that we use to make everything responsive
	WIDTH = GetScreenWidth();
	HEIGHT = GetScreenHeight();

	//loading textures
	inventory = LoadTexture("../../assets/images/UI elements/inventory.png");
	item = LoadTexture("../../assets/images/UI elements/item.png");

	//setting sizes of variables
	item.width = 50;
	item.height = 50;

	inventoryRect = { 0,0, (float)inventory.width, (float)inventory.height };

	//random seed using chrono library
	seed = std::chrono::steady_clock::now().time_since_epoch().count();

	//resize vector
	v1.resize(4);
	v2.resize(4);

	//generate new seed
	gen.seed(seed);

	//the position where the first item is placed in the inventory
	positionOfItemsInInventory = { float(WIDTH / 5), float(HEIGHT - HEIGHT / 1.75) };

	//set the range for the x and y where the normal items can appear
	range = std::uniform_int_distribution<int>(1, WIDTH - WIDTH / 17);
	range2 = std::uniform_int_distribution<int>(1, HEIGHT - HEIGHT / 15);

	for (int i = 0; i < v1.size(); i++)
	{
		//filling the vector with random values
		v1[i] = range(gen);
		v2[i] = range2(gen);
	}

	//setting random values to the the items position
	normalItemsPos = {
		{v1[0], v2[0]},
		{v1[1], v2[1]},
		{v1[2], v2[2]},
		{v1[3], v2[3]}
	};
}

//destructor - unloads textures
InventorySystem::~InventorySystem()
{
	UnloadTexture(inventory);
	UnloadTexture(item);
}

bool InventorySystem::isPickedUp(Rectangle heroPosition)
{
	for (int i = 0; i < normalItemsPos.size(); i++)
	{
		//checks if you are close to the items
		if (CheckCollisionCircleRec(normalItemsPos[i], WIDTH / 15, heroPosition))
		{
			//draw items that you are close and you can pick up without any opacity 
			DrawTextureV(item, normalItemsPos[i], Fade(WHITE, 1));
			if (IsKeyPressed(KEY_Q))
			{
				//transfer items into inventory 
				itemsInInventoryPos.push_back(positionOfItemsInInventory);
				//make the next item position to move 150 on right 
				positionOfItemsInInventory.x = positionOfItemsInInventory.x + WIDTH / 15;
				//remove items from the ground
				normalItemsPos.erase(normalItemsPos.begin() + i);
			}
		}
	}
	return 0;
}

void InventorySystem::drawInventory()
{
	//draw inventory background
	DrawTextureRec(inventory, inventoryRect, { 200, 100 }, WHITE);

	//draw items in inventory
	for (int i = 0; i < itemsInInventoryPos.size(); i++)
	{
		DrawTextureV(item, itemsInInventoryPos[i], WHITE);
	}
}

void InventorySystem::drawnormalItems()
{
	//draw the items but on 50% opacity
	for (auto& position : normalItemsPos)
	{
		DrawTextureV(item, position, Fade(WHITE, 0.5f));
	}
}