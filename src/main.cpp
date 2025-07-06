#include "grid.h"
#include "Rendering/RaylibRenderer.h"
// #include "Rendering/TerminalRenderer.h"

int main()
{
    int rows = 10;
    int cols = 10;
    constexpr int cellSize = 10;

    Renderer *renderer = new RaylibRenderer(cellSize, cols, rows);
    // Renderer *renderer = new TerminalRenderer(cellSize, cols, rows);
    renderer->Setup("Conway's Game of Life");

    // Theoretically we could setup the grid to not be aware of the renderer, but for this example it felt fine to pass it a polymorphic renderer.
    Grid *grid = new Grid(cols, rows, renderer);

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

    return 0;
}