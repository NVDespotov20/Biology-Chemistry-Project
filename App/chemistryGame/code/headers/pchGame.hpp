//include every library we use
#pragma once
#include<iostream>
#include<vector>
#include<raylib.h>
#include <random>
#include <chrono>
#include <string>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <memory>
class Direction
{
public:
    int i = 0, j = 2;

    static std::shared_ptr<Direction> getInstantiation();


private:
    static std::shared_ptr<Direction> instantiate_;

};


