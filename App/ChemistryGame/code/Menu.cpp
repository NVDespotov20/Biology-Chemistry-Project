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
        Button("Options",  WIDTH / 2 - WIDTH / 12,  HEIGHT / 3.f    , WIDTH / 6, HEIGHT / 10, fontSize),
        Button("Rules",  WIDTH / 2 - WIDTH / 12,  HEIGHT / 2.f    , WIDTH / 6, HEIGHT / 10, fontSize),
        Button("Exit",  WIDTH / 2 - WIDTH / 12,  HEIGHT / 1.50f  , WIDTH / 6, HEIGHT / 10, fontSize),
    };
    load();

    for (int i = 0; i < 4; i++)
    {
        buttonsTextures[i].width = 325;
        buttonsTextures[i].height = 250;
    }
}

Menu::~Menu()
{
    unload();
}


inline void Menu::load()
{
    menuBackground = LoadTexture("../assets/images/Rooms/RoomThree.png");

    buttonsTextures[0] = LoadTexture("../assets/images/chemistry/Buttons/StartButton.png");
    buttonsTextures[1] = LoadTexture("../assets/images/chemistry/Buttons/OptionsButton.png");
    buttonsTextures[2] = LoadTexture("../assets/images/chemistry/Buttons/RulesButton.png");
    buttonsTextures[3] = LoadTexture("../assets/images/chemistry/Buttons/ExitButton.png");
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
        button.draw(0.5f, 15, BLANK, BLANK);

    for (int i=0;i<4;i++)
        DrawTexture(buttonsTextures[i], 800, 100 + i *180,WHITE);
}