#pragma once
#include <iostream>
#include <raylib.h>
#include <vector>
#include <string>

class pch
{
public:
    enum class Direction
    {
        APP,
        QUIT
    } dir = Direction::APP;

    static std::shared_ptr<pch> getInstantiation();
private:
    static std::shared_ptr<pch> instantiate_;

};