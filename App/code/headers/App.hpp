#pragma once
#include "Button.hpp"

class App
{
public:
    ~App();
    void drawHumanAndButtons();
    void setSizes();
    void showVideosAndInfo(int indexOfMuscle);

    static std::shared_ptr<App> getInstantiation();

private:
    App();

    static std::shared_ptr<App> instantiate_;

    void load();
    void unload();

    int indexOfButtons;
    int fontSize = 20;

    float WIDTH;
    float HEIGHT;

    Texture2D humanBody;
    Texture2D nextButton;
    Texture2D previousButton;

    Button backButton;
    Button muscles[8];

    Rectangle nextButtonRec;
    Rectangle previousButtonRec;
    Rectangle sideOfHumanRec;

    Vector2 mousePoint;
    Vector2 sideOfHumanVec;
    Vector2 lineOfButtons[2];

};