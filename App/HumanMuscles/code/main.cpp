#include"headers/pch.hpp"
#include"headers/AppManager.hpp"
int main()
{
    AppManager* manager = AppManager::getInstantiation();
    manager->drawMainLoop();
    delete manager;
}