#pragma once

#include<Menu.hpp>
#include<Options.hpp>
#include<App.hpp>
class AppManager
{
public:
    ~AppManager();
    bool manageApp();
    void drawMainLoop();
    static AppManager* getInstantiation();
private:
    bool shouldQuit;
    std::shared_ptr<Options> opt;
    std::shared_ptr<Menu> menu;
    static AppManager* instantiate_;

    AppManager();
};