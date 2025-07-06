#include "grid.h"
#include <memory>
#include "Rendering/RaylibRenderer.h"
// #include "Rendering/TerminalRenderer.h"

int main()
{
    int rows = 90;
    int cols = 90;
    constexpr int cellSize = 10;

    std::unique_ptr<Renderer> renderer = std::make_unique<RaylibRenderer>(cellSize, cols, rows);
    // Renderer *terminalRenderer = new TerminalRenderer(cellSize, cols, rows);
    renderer->Setup("Conway's Game of Life");

    // Theoretically we could setup the grid to not be aware of the renderer, but for this example it felt fine to pass it a polymorphic renderer.
    std::unique_ptr<Grid> grid = std::make_unique<Grid>(cols, rows, renderer.get());

    while (renderer->ShouldEndSimulation() == false)
    {
        renderer->Update();
        // Update the game
        grid->Update();

        grid->Draw();
        renderer->EndUpdate();
    }

    renderer->Shutdown();

    return 0;
}