#include <raylib.h>
#include "grid.h"

int main()
{
    const Color darkGreen = {20, 160, 133, 255};

    constexpr int screenWidth = 1024;
    constexpr int screenHeight = 768;

    InitWindow(screenWidth, screenHeight, "Conway's Game of Life");
    SetTargetFPS(60);
    // Create a grid with cells of size 10x10
    Grid *grid = new Grid(1024 / 10, 768 / 10);
    while (!WindowShouldClose())
    {

        // Update the game
        grid->Update();
        BeginDrawing();
        ClearBackground(darkGreen);
        grid->Draw();
        EndDrawing();
    }

    CloseWindow();
}