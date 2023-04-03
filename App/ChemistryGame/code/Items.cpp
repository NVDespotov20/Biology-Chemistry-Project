#include "pchGame.hpp"
#include "Items.hpp"

//implement singleton
std::shared_ptr<Items> Items::instantiate_ = nullptr;

std::shared_ptr<Items> Items::getInstantiation()
{
	if (instantiate_ == nullptr) {
		instantiate_ = std::shared_ptr<Items>(new Items);
	}
	return instantiate_;
}
void Items::load()
{

	item = LoadTexture("../assets/images/chemistry/item.png");
	//setting sizes of variables
	item.width = 50;
	item.height = 50;
}
Items::Items()
{
	//things for items
	WIDTH = GetScreenWidth();
	HEIGHT = GetScreenHeight();



	//random seed using chrono library
	seed = std::chrono::steady_clock::now().time_since_epoch().count();

	//resize vector
	v1.resize(4);
	v2.resize(4);

	//generate new seed
	gen.seed(seed);


	//set the range for the x and y where the normal items can appear
	range = std::uniform_int_distribution<int>(1, WIDTH - WIDTH / 17);
	range2 = std::uniform_int_distribution<int>(1, HEIGHT - HEIGHT / 15);

	for (int i = 0; i < v1.size(); i++)
	{
		//filling the vector with random values
		v1[i] = range(gen);
		v2[i] = range2(gen);
	}
	normalItemsPos = {
		{v1[0], v2[0]},
		{v1[1], v2[1]},
		{v1[2], v2[2]},
		{v1[3], v2[3]}
	};
}
void Items::drawNormalItems()
{
	//draw the items but on 50% opacity
	for (auto& position : normalItemsPos)
	{
		DrawTextureV(item, position, Fade(WHITE, 0.5f));
	}
}
Items::~Items()
{
	UnloadTexture(item);

}

