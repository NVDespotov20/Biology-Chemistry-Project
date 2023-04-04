#pragma once
#include "pchGame.hpp"
class Navigator
{
public:
    int i = 0, j = 2;
    enum class Navigate
    {
        GAME,
        MENU,
        QUIT
    } dir = Navigate::MENU;

    static std::shared_ptr<Navigator> getInstantiation();


private:
    static std::shared_ptr<Navigator> instantiate_;

};

