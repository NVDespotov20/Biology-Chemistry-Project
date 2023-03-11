#include"headers/App.hpp"
#include <iostream>
using namespace std;


App::App() 
{
    SetConfigFlags(FLAG_FULLSCREEN_MODE);
    InitWindow(0, 0, "Human muscles");
    mousePoint = {0,0};
    WIDTH = GetScreenWidth();
    HEIGHT = GetScreenHeight();
    SetTargetFPS(60);

    nextButton = LoadTexture("../assets/images/UI elements/next.png");
    previousButton = LoadTexture("../assets/images/UI elements/previous.png");

    nextButton.width = WIDTH / 38.4f;
    nextButton.height = HEIGHT /14.4;

    previousButton.width = WIDTH / 38.4f;
    previousButton.height = HEIGHT / 14.4;

    nextButtonRec = {WIDTH/1.5f, HEIGHT/ 2, (float)nextButton.width ,(float)nextButton.height};
    previousButtonRec = { WIDTH/3.8f, HEIGHT / 2, (float)nextButton.width ,(float)nextButton.height };

    humanBody = LoadTexture("../assets/images/muscles/Human_body.png");
    humanBody.width = WIDTH/2;
    humanBody.height = HEIGHT/2;
    
    lineOfButtons[0] = {WIDTH - WIDTH/4,0};
    lineOfButtons[1] = {WIDTH - WIDTH / 4,HEIGHT};
   
    sideOfHumanRec = { WIDTH / 3, HEIGHT, (float)humanBody.width / 3, (float)humanBody.height};
    sideOfHumanVec = { WIDTH / 2.5f, HEIGHT / 4};

    buttonsRec[0] = {WIDTH - WIDTH / 5,HEIGHT - float(HEIGHT / 1.1), WIDTH/6, HEIGHT/22 };
    buttonsRec[1] = { WIDTH - WIDTH / 5,HEIGHT - float(HEIGHT / 1.22),WIDTH/6, HEIGHT / 22 };
    buttonsRec[2] = { WIDTH - WIDTH / 5,HEIGHT - float(HEIGHT / 1.36), WIDTH/6, HEIGHT / 22 };
    buttonsRec[3] = { WIDTH - WIDTH / 5,HEIGHT - float(HEIGHT / 1.52),WIDTH/6, HEIGHT / 22 };
    buttonsRec[4] = { WIDTH - WIDTH / 5,HEIGHT - float(HEIGHT / 1.74),WIDTH/6, HEIGHT / 22 };
    buttonsRec[5] = { WIDTH - WIDTH / 5,HEIGHT - float(HEIGHT / 2.00009999),WIDTH/6, HEIGHT / 22 };
    buttonsRec[6] = { WIDTH - WIDTH / 5,HEIGHT - float(HEIGHT / 2.38),WIDTH/6, HEIGHT / 22 };
    buttonsRec[7] = { WIDTH - WIDTH / 5,HEIGHT - float(HEIGHT / 2.85),WIDTH/6, HEIGHT / 22 };

}
App::~App() 
{
    UnloadTexture(humanBody);
    UnloadTexture(nextButton);
    UnloadTexture(previousButton);
    CloseWindow();
    delete this;
}
void App::loop()
{
    while (!WindowShouldClose())
    {
        mousePoint = GetMousePosition();

        ClearBackground(LIGHTGRAY);

        DrawTextureRec(humanBody, sideOfHumanRec, sideOfHumanVec, WHITE);


        DrawTexture(nextButton, (float)WIDTH / 1.5, (float)HEIGHT / 2, WHITE);
        DrawTexture(previousButton, (float)WIDTH / 3.8f, (float)HEIGHT / 2, WHITE);


        //Fix unable to alt-tab
        if (!IsWindowFocused())
            MinimizeWindow();

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousePoint, nextButtonRec))
        {
            sideOfHumanRec.x = sideOfHumanRec.x + WIDTH / 1.5f;
        }

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousePoint, previousButtonRec))
        {
            sideOfHumanRec.x = sideOfHumanRec.x - WIDTH / 1.5f;
        }

        DrawLineEx(lineOfButtons[0], lineOfButtons[1], 5, BLACK);

        for (int i = 0; i < 8; i++)
        {
            DrawRectangleRounded(buttonsRec[i], 20, 10, BLUE);
        }

        DrawText("Biceps", WIDTH - WIDTH / 6.7, HEIGHT - HEIGHT / 1.1051, 40, BLACK);
        DrawText("Traps", WIDTH - WIDTH / 6.8, HEIGHT - HEIGHT / 1.228, 40, BLACK);
        DrawText("Legs", WIDTH - WIDTH / 6.9, HEIGHT - HEIGHT / 1.365151, 40, BLACK);
        DrawText("Triceps", WIDTH - WIDTH / 6.4, HEIGHT - HEIGHT / 1.52651, 40, BLACK);
        DrawText("Shoulders", WIDTH - WIDTH / 5.89, HEIGHT - HEIGHT / 1.74851651, 40, BLACK);
        DrawText("Back", WIDTH - WIDTH / 7.1, HEIGHT - HEIGHT / 2.01351, 40, BLACK);
        DrawText("Chest", WIDTH - WIDTH / 6.95, HEIGHT - HEIGHT / 2.3951, 40, BLACK);
        DrawText("Core", WIDTH - WIDTH / 7.1, HEIGHT - HEIGHT / 2.90551, 40, BLACK);

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousePoint, buttonsRec[0]))
        {
            indexOfButtons = 0;
            showVideosAndInfo(indexOfButtons);
        }

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousePoint, buttonsRec[1]))
        {
            indexOfButtons = 1;
            showVideosAndInfo(indexOfButtons);
        }

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousePoint, buttonsRec[2]))
        {
            indexOfButtons = 2;
            showVideosAndInfo(indexOfButtons);
        }

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousePoint, buttonsRec[3]))
        {
            indexOfButtons = 3;
            showVideosAndInfo(indexOfButtons);
        }

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousePoint, buttonsRec[4]))
        {
            indexOfButtons = 4;
            showVideosAndInfo(indexOfButtons);
        }

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousePoint, buttonsRec[5]))
        {
            indexOfButtons = 5;
            showVideosAndInfo(indexOfButtons);
        }

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousePoint, buttonsRec[6]))
        {
            indexOfButtons = 6;
            showVideosAndInfo(indexOfButtons);
        }

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousePoint, buttonsRec[7]))
        {
            indexOfButtons = 7;
            showVideosAndInfo(indexOfButtons);
        }


        EndDrawing();
    }

}

void App::showVideosAndInfo(int indexOfMuscle)
{
    if (indexOfMuscle == 0)
    {
        //play biceps video
    }

}