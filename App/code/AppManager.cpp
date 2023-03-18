#include<pch.hpp>  
#include <AppManager.hpp>

AppManager* AppManager::instantiate_ = nullptr;

AppManager::AppManager()
{
    // Initialize window and settings
    InitWindow(0, 0, "Human muscles");
    ToggleFullscreen();
    SetTargetFPS(60);
}

AppManager::~AppManager()
{
    CloseWindow();
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
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(LIGHTGRAY);
        manageApp();
        EndDrawing();
    }
}

void AppManager::manageApp()
{
    //create pch instance
    std::shared_ptr<pch> manager = pch::getInstantiation();
    switch (manager->dir)
    {
        case pch::Direction::MENU:
        {

            std::shared_ptr<Menu> menu = Menu::getInstantiation();
            menu->drawMainMenu();
            break;
        }
        case pch::Direction::APP:
        {

            std::shared_ptr<App> app = App::getInstantiation();
            app->drawHumanAndButtons();
            break;
        }
        case pch::Direction::OPTIONS:
        {
            std::shared_ptr<Options> opt = Options::getInstantiation();
            opt->drawOptions();
            break;
        }
        case pch::Direction::QUIT:
        {
            delete this;
            break;
        }
    }
}