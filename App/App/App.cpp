#include"App.hpp"
#include <iostream>
using namespace std;

App::App() {

    InitWindow(800, 450, "Human muscles");

    SetTargetFPS(60);

    previousButton = LoadTexture("../src/images/previous.png");
    nextButton = LoadTexture("../src/images/next.png");

    previousButton.width = 50;
    previousButton.height = 75;

    nextButton.width = 50;
    nextButton.height = 75;

    nextButtonRec = {735, 200, float(nextButton.width) ,float(nextButton.height)};
    previousButtonRec = { 10, 200, float(previousButton.width) ,float(previousButton.height)};

    humanBody = LoadTexture("../src/images/Human_body.png");

    sideOfHumanFloat = 170;

    sideOfHumanRec = { 0, 0, sideOfHumanFloat-10, 250 };
    sideOfHumanVec = {300, 100};
}
App::~App() {
    delete this;
    CloseWindow();
}
void App::loop()
{
    while (!WindowShouldClose())
    {
        mousePoint = GetMousePosition();

        ClearBackground(LIGHTGRAY);

        DrawTextureRec(humanBody, sideOfHumanRec, sideOfHumanVec, WHITE);

        DrawTexture(previousButton,10,200,WHITE);
        DrawTexture(nextButton, 735, 200, WHITE);


        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousePoint, nextButtonRec))
        {
            sideOfHumanRec.x = sideOfHumanRec.x + 160;
        }
        
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousePoint, previousButtonRec))
        {
            sideOfHumanRec.x = sideOfHumanRec.x - 160;
        }

        EndDrawing();
    }
}
