#include "pch.hpp"
#include "AppManager.hpp"

int main()
{
    AppManager* manager = AppManager::getInstantiation();
    manager->drawMainLoop();
    delete manager;
}