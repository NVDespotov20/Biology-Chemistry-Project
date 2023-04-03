#pragma once
#include "Button.hpp"
#include "FileReader.hpp"

class App
{
public:
    ~App();
    void drawUI();
    void setSizes();
    void setButtons();
    void showInfo(int indexOfMuscle);

    static std::shared_ptr<App> getInstantiation();

private:
    App();

    static std::shared_ptr<App> instantiate_;

    void load();
    void unload();
    void checkInput();

    int indexOfButtons;
    int fontSize = 20;
    int sizeOfmuscleButtons;

    float WIDTH, offsetX ;
    float HEIGHT, offsetY;

    Texture2D background;

    Texture2D nextButton;
    Texture2D previousButton;

    Texture2D humanBody;
    Texture2D *selectedMuscle;
    Texture2D muscleTextures[12];

    std::string muscleNames[12];

    Button muscles[12];
    Button backButton;

    Rectangle nextButtonRec;
    Rectangle previousButtonRec;
    Rectangle sideOfHumanRec;

    Vector2 mousePoint;
    Vector2 sideOfHumanVec;
    Vector2 lineOfButtons[2];

    FileReader fReader;
    std::string muscleInfo;
};