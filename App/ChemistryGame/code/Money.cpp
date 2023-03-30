#include "pchGame.hpp"
#include "Money.hpp"


//implement singleton
std::shared_ptr<Money> Money::instantiate_ = nullptr;


std::shared_ptr<Money> Money::getInstantiation()
{
	if (instantiate_ == nullptr)
	{
		instantiate_ = std::shared_ptr<Money>(new Money);
	}
	return instantiate_;
}
Money::Money()
{
	money = 0;
	allMoney = 0;
	allMoneyCopy = 500;
}

Money::~Money()
{

}

void Money::addMoney()
{
	allMoney += 500;
}

void Money::drawMoney()
{
	printMoney = std::to_string(allMoney);
	DrawText(printMoney.c_str(), 85, 50, 50, GOLD);
}
