

#include "Renderer.h"
#include <raylib.h>

class RaylibRenderer : public Renderer
{
private:
    int cellSize;
    const Color darkGreen = {20, 160, 133, 255};

public:
    RaylibRenderer(int cellSize, int gridWidth, int gridHeight) : Renderer(cellSize, gridWidth, gridHeight)
    {
        this->cellSize = cellSize;
    }

    void RenderCell(int x, int y, bool alive) override
    {
        // Implementation using Raylib functions
        DrawRectangle(x * cellSize, y * cellSize, cellSize, cellSize, alive ? GREEN : DARKGRAY);
    }

    void Setup(int screenWidth, int screenHeight, std::string title) override
    {
        InitWindow(screenWidth, screenHeight, title.c_str());
        SetTargetFPS(60);
    }

    bool ShouldEndSimulation() override
    {
        return WindowShouldClose();
    }

    void Shutdown() override
    {
        CloseWindow();
    }

    void Update() override
    {
        BeginDrawing();
        ClearBackground(darkGreen);
    }

    void EndUpdate() override
    {
        EndDrawing();
    }

    ~RaylibRenderer() override = default;
};