#include "pchGame.hpp"
#include "Menu.hpp"
Menu::Menu()
{
    WIDTH = GetScreenWidth();
    HEIGHT = GetScreenHeight();
    mousePoint = { 0,0 };

    fontSize = HEIGHT / 27;

    buttonsRecs = {
        Button("Start", WIDTH / 2.4f, HEIGHT / 1.862f, WIDTH / 6, HEIGHT / 10, fontSize),
        Button("Rules", WIDTH / 2.4f, HEIGHT / 1.44f, WIDTH / 6, HEIGHT / 10, fontSize),
        Button("Exit",  WIDTH / 2.4f, HEIGHT / 1.155f, WIDTH / 6, HEIGHT / 10, fontSize),
    };
    load();
    menuBackground.width = GetScreenWidth();
    menuBackground.height = GetScreenHeight();
    for (int i = 0; i < 3; i++)
    {
        buttonsTextures[i].width = WIDTH / 5.907f;
        buttonsTextures[i].height = HEIGHT / 4.32f;
    }
}

Menu::~Menu()
{
    unload();
}


inline void Menu::load()
{
    menuBackground = LoadTexture("../assets/images/chemistry/Objects/MainBackground.png");

    buttonsTextures[0] = LoadTexture("../assets/images/chemistry/Buttons/StartButton.png");
    buttonsTextures[1] = LoadTexture("../assets/images/chemistry/Buttons/RulesButton.png");
    buttonsTextures[2] = LoadTexture("../assets/images/chemistry/Buttons/ExitButton.png");
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
    if (isClicked(mousePoint, buttonsRecs[2].getBoundingBox()))
    {
        auto manager = Navigator::getInstantiation();
        manager->dir = Navigator::Navigate::QUIT;
    }

    for (auto& button : buttonsRecs)
        button.draw(0.5f, 15, BLANK, BLANK);

    for (int i=0;i<3;i++)
        DrawTexture(buttonsTextures[i], WIDTH / 2.4f, HEIGHT / 2.16f + i * HEIGHT / 6, WHITE);
}