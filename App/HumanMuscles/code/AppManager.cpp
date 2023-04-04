#include "pch.hpp"
#include "AppManager.hpp"

AppManager* AppManager::instantiate_ = nullptr;

AppManager::AppManager()
{
    // Initialize window and settings
    //InitWindow(0, 0, "Human muscles");
    //SetTargetFPS(60);
    //ToggleFullscreen();
}

AppManager::~AppManager()
{
    //CloseWindow();
}

AppManager* AppManager::getInstantiation()
{
    if (instantiate_ == nullptr) {
        instantiate_ = new AppManager();
    }
    return instantiate_;
}

void AppManager::drawMainLoop()
{
    bool continueLoop = true;
    while (!WindowShouldClose() && continueLoop)
    {
        
        BeginDrawing();
        ClearBackground(LIGHTGRAY);
        continueLoop = manageApp();
        EndDrawing();
    }
}

bool AppManager::manageApp()
{
    //create pch instance
    std::shared_ptr<pch> manager = pch::getInstantiation();
    switch (manager->dir)
    {
        case pch::Direction::APP:
        {
            std::shared_ptr<App> app = App::getInstantiation();
            app->drawUI();
            return true;
        }
        case pch::Direction::QUIT:
        {
            return false;
        }
    }
}