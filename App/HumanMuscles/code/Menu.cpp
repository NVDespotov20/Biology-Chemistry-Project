#include<pch.hpp>
#include <Menu.hpp>
std::shared_ptr<Menu> Menu::instantiate_ = nullptr;

Menu::Menu()
{
    WIDTH = GetScreenWidth();
    HEIGHT = GetScreenHeight();
    mousePoint = { 0,0 };

    fontSize = HEIGHT / 27;

    buttonsRecs = {
        Button("Start", WIDTH / 2 - WIDTH / 12,  HEIGHT / 6.25f  , WIDTH / 6, HEIGHT / 10, fontSize),
        Button("????",  WIDTH / 2 - WIDTH / 12,  HEIGHT / 3.f    , WIDTH / 6, HEIGHT / 10, fontSize),
        Button("????",  WIDTH / 2 - WIDTH / 12,  HEIGHT / 2.f    , WIDTH / 6, HEIGHT / 10, fontSize),
        Button("Exit",  WIDTH / 2 - WIDTH / 12,  HEIGHT / 1.50f  , WIDTH / 6, HEIGHT / 10, fontSize),
    };
    load();
}

Menu::~Menu()
{
    unload();
}


std::shared_ptr<Menu> Menu::getInstantiation()
{
    if (instantiate_ == nullptr)
    {
        instantiate_ = std::shared_ptr<Menu>(new Menu);
    }

    return instantiate_;
}

inline void Menu::load()
{

}

inline void Menu::unload()
{

}

inline bool Menu::isClicked(const Vector2& mPos, const Rectangle& rec)
{
    return (CheckCollisionPointRec(mPos, rec) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT));
}

void Menu::drawMainMenu()
{
    mousePoint = GetMousePosition();

    //// Fix unable to alt-tab
    //if (!IsWindowFocused())
    //    MinimizeWindow();

    for (auto& button : buttonsRecs)
    {
        if (isClicked(mousePoint, button.getBoundingBox()))
        {
            auto manager = pch::getInstantiation();
            manager->dir = pch::Direction::APP;
        }
        button.draw(0.5f, 15, RED, BLACK);
    }
}