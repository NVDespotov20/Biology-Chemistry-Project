#include "pchGame.hpp"
#include "Menu.hpp"
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


inline void Menu::load()
{
    menuBackground = LoadTexture("../assets/images/UI elements/bg.png");
}

inline void Menu::unload()
{
    UnloadTexture(menuBackground);
}

inline bool Menu::isClicked(const Vector2& mPos, const Rectangle& rec)
{
    return (CheckCollisionPointRec(mPos, rec) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT));
}

void Menu::drawMainMenu()
{
    DrawTexture(menuBackground, 0, 0, WHITE);

    mousePoint = GetMousePosition();

    if (isClicked(mousePoint, buttonsRecs[0].getBoundingBox()))
    {
        auto manager = Navigator::getInstantiation();
        manager->dir = Navigator::Navigate::GAME;
    }
    if (isClicked(mousePoint, buttonsRecs[3].getBoundingBox()))
    {
        auto manager = Navigator::getInstantiation();
        manager->dir = Navigator::Navigate::QUIT;
    }

    for (auto& button : buttonsRecs)
        button.draw(0.5f, 15, RED, BLACK);
}