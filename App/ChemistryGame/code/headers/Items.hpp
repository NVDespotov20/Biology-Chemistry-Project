#pragma once
class Items
{
public:
	Items();
	~Items();
	static std::shared_ptr<Items> getInstantiation();
	void drawNormalItems();
	void load();
	std::vector<Vector2> normalItemsPos;

	Texture2D item;

private:
	static std::shared_ptr<Items> instantiate_;
	float WIDTH;
	float HEIGHT;
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


	//setting random values to the the items position

};

