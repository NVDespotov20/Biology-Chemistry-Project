#pragma once
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

    float WIDTH;
    float HEIGHT;

    Texture2D humanBody;
    Texture2D nextButton;
    Texture2D previousButton;

    Rectangle backButtonRec;
    Rectangle nextButtonRec;
    Rectangle previousButtonRec;
    Rectangle sideOfHumanRec;
    Rectangle buttonsRec[8];

    Vector2 mousePoint;
    Vector2 sideOfHumanVec;
    Vector2 lineOfButtons[2];
};