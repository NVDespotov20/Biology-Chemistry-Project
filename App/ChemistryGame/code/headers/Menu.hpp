#pragma once
#include "Button.hpp"
#include "Navigator.hpp"
class Menu
{
public:
    float WIDTH;
    float HEIGHT;

    Menu();
    ~Menu();
    void drawMainMenu();
private:

    void unload();
    void load();
    bool isClicked(const Vector2& mPos, const Rectangle& rec);

    int fontSize;

    Texture2D menuBackground;

    Vector2 mousePoint;

    std::vector<Button> buttonsRecs;
};
