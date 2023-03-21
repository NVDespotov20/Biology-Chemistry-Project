#include<pch.hpp>  
#include <AppManager.hpp>

AppManager* AppManager::instantiate_ = nullptr;

AppManager::AppManager()
{
    // Initialize window and settings
    InitWindow(0, 0, "Human muscles");
    SetTargetFPS(60);
    ToggleFullscreen();
    shouldQuit = 1;
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
    
    while (!WindowShouldClose() && shouldQuit)
    {
        
        BeginDrawing();
        ClearBackground(LIGHTGRAY);
        shouldQuit = manageApp();
        std::cout << manageApp() << std::endl;
        EndDrawing();
    }
}

bool AppManager::manageApp()
{
    //create pch instance
    std::shared_ptr<pch> manager = pch::getInstantiation();
    switch (manager->dir)
    {
        case pch::Direction::MENU:
        {

            menu = Menu::getInstantiation();
            menu->drawMainMenu();
            return true;
            break;
        }
        case pch::Direction::APP:
        {

            std::shared_ptr<App> app = App::getInstantiation();
            app->drawHumanAndButtons();
            return true;
            break;
        }
        case pch::Direction::OPTIONS:
        {
            opt = Options::getInstantiation();
            opt->drawOptions();
            return true;
            break;
        }
        case pch::Direction::QUIT:
        {
            return false;
            break;
        }
    }
}