#include "pch.hpp"
#include "AppManager.hpp"
#include "files.hpp"
int main()
{
    AppManager* manager = AppManager::getInstantiation();
    manager->drawMainLoop();
    delete manager;
}