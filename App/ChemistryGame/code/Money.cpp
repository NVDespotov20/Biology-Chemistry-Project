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
    WIDTH = GetScreenWidth();
    HEIGHT = GetScreenHeight();
    money = 0;
}

Money::~Money()
{

}

void Money::addMoney()
{
    money += 1;
}

void Money::drawMoney()
{
    DrawText(std::to_string(money).c_str(), WIDTH / 11.162f, HEIGHT / 42.353f, WIDTH / 34.909f, GOLD);

}