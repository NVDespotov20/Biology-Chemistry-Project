#include "pchGame.hpp"
#include "Money.hpp"

Money::Money()
{
	money = 2000;
	allMoney = 2000;
	allMoneyCopy = allMoney;
}

void Money::drawMoney()
{
	printMoney = std::to_string(allMoneyCopy);
	DrawText(printMoney.c_str(), 85, 50, 50, GOLD);
}
void Money::addMoney()
{

	//addd
}