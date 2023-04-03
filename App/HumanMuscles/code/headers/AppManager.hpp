#pragma once
#include "App.hpp"

class AppManager
{
public:
    ~AppManager();
    void manageApp();
    void drawMainLoop();
    static AppManager* getInstantiation();
private:
    static AppManager* instantiate_;

    AppManager();
};