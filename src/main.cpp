#include "grid.h"
#include "Rendering/RaylibRenderer.h"
// #include "Rendering/TerminalRenderer.h"

int main()
{

    constexpr int screenWidth = 1900;
    constexpr int screenHeight = 1000;
    constexpr int cellSize = 10;
    constexpr int gridWidth = screenWidth / cellSize;
    constexpr int gridHeight = screenHeight / cellSize;

    Renderer *renderer = new RaylibRenderer(cellSize, gridWidth, gridHeight);
    // Renderer *renderer = new TerminalRenderer(cellSize, gridWidth, gridHeight);
    renderer->Setup(screenWidth, screenHeight, "Conway's Game of Life");

    // Theoretically we could setup the grid to not be aware of the renderer, but for this example it felt fine to pass it a polymorphic renderer.
    Grid *grid = new Grid(gridWidth, gridHeight, renderer);

    while (renderer->ShouldEndSimulation() == false)
    {
        renderer->Update();
        // Update the game
        grid->Update();

        grid->Draw();
        renderer->EndUpdate();
    }

    delete grid;
    grid = nullptr;

    renderer->Shutdown();

    delete renderer;
    renderer = nullptr;
}