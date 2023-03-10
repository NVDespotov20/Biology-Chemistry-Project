#include"App.hpp"
#include <iostream>
using namespace std;


App::App() {

    mousePoint = GetMousePosition(); 
    InitWindow(0, 0, "Human muscles");
    mousePoint = {0,0};
    WIDTH = GetScreenWidth();
    HEIGHT = GetScreenHeight();
    SetTargetFPS(60);

    nextButton = LoadTexture("../src/images/next.png");
    previousButton = LoadTexture("../src/images/previous.png");

    nextButton.width = WIDTH / 38.4f;
    nextButton.height = HEIGHT /14.4;

    previousButton.width = WIDTH / 38.4f;
    previousButton.height = HEIGHT / 14.4;

    nextButtonRec = {WIDTH/1.5f, HEIGHT/ 2, (float)nextButton.width ,(float)nextButton.height};
    previousButtonRec = { WIDTH/3.8f, HEIGHT / 2, (float)nextButton.width ,(float)nextButton.height };

    humanBody = LoadTexture("../src/images/Human_body.png");
    humanBody.width = WIDTH/2;
    humanBody.height = HEIGHT/2;
    
 
   
    sideOfHumanRec = { WIDTH / 3, HEIGHT, (float)humanBody.width / 3, (float)humanBody.height};
   sideOfHumanVec = { WIDTH / 2.5f, HEIGHT / 4};
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

        
        DrawTexture(nextButton, (float)WIDTH/1.5, (float)HEIGHT / 2, WHITE);
        DrawTexture(previousButton, (float)WIDTH / 3.8f, (float)HEIGHT / 2, WHITE);

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousePoint, nextButtonRec))
        {
            sideOfHumanRec.x = sideOfHumanRec.x + WIDTH/ 1.5f;
        }
        
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousePoint, previousButtonRec))
        {
            sideOfHumanRec.x = sideOfHumanRec.x - WIDTH/ 1.5f;
        }

        EndDrawing();
    }
}
