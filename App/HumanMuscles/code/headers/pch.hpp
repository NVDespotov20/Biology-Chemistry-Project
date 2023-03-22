#pragma once
#include<iostream>
#include<raylib.h>
#include<vector>

class pch
{
public:
    enum class Direction
    {
        MENU,
        APP,
        OPTIONS,
        QUIT
    } dir = Direction::MENU;

    static std::shared_ptr<pch> getInstantiation();

private:
    static std::shared_ptr<pch> instantiate_;

};