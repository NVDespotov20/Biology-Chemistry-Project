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
}

Money::~Money()
{

}

void Money::addMoney()
{
    money += 500;
}

void Money::drawMoney()
{
    DrawText(std::to_string(money).c_str(), 85, 50, 50, GOLD);
}