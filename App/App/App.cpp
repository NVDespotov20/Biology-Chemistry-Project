#include"App.hpp"
App::App() {

    InitWindow(800, 450, "raylib [core] example - basic window");

    SetTargetFPS(60);
}
App::~App() {
    delete this;
    CloseWindow();
}
void App::loop()
{
    while (!WindowShouldClose())
    {


        ClearBackground(RAYWHITE);

        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
    }
}
