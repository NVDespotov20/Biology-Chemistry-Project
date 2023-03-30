#include "pchGame.hpp"
#include "Money.hpp"

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
