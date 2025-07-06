

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
        this->gridWidth = gridWidth;
        this->gridHeight = gridHeight;
    }

    void RenderCell(int row, int col, bool alive) override
    {
        // Implementation using Raylib functions
        DrawRectangle(col * cellSize, row * cellSize, cellSize, cellSize, alive ? GREEN : DARKGRAY);
    }

    void Setup(std::string title) override
    {
        InitWindow(gridWidth * cellSize, gridHeight * cellSize, title.c_str());
        SetTargetFPS(5);
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