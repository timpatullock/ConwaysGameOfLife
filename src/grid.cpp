

#include "grid.h"
#include "Rendering/Renderer.h"
Grid::Grid(int cols, int rws, Renderer *renderLayer) : columns(cols), rows(rws), grid(rows, std::vector<bool>(columns, false)), renderLayer(renderLayer)
{
    // Initialize the grid with randomized cells
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // Seed for random number generation
    for (int y = 0; y < rows; ++y)
    {
        for (int x = 0; x < columns; ++x)
        {
            grid[y][x] = rand() % 100 > 90; // Randomly initialize cells as alive or dead
        }
    }
}

bool Grid::IsCellAlive(int x, int y) const
{
    if (x < 0 || x >= columns || y < 0 || y >= rows)
    {
        return false; // Out of bounds
    }
    return grid[y][x];
}

bool Grid::SetCellAlive(int x, int y, bool alive)
{
    if (x < 0 || x >= columns || y < 0 || y >= rows)
    {

        return false; // Out of bounds
    }
    grid[y][x] = alive;
    return true;
}

void Grid::Update()
{
    for (int y = 0; y < rows; ++y)
    {
        for (int x = 0; x < columns; ++x)
        {
            int aliveNeighbors = 0;
            bool isAlive = IsCellAlive(x, y);

            // Count alive neighbors
            for (int dy = -1; dy <= 1; ++dy)
            {
                for (int dx = -1; dx <= 1; ++dx)
                {
                    if (dx == 0 && dy == 0)
                        continue; // Skip the cell itself
                    if (IsCellAlive(x + dx, y + dy))
                    {
                        aliveNeighbors++;
                    }
                }
            }

            if (isAlive)
            {
                // If cell has less than two neightbors, it dies
                // If cell has more than three neighbors, it dies
                if (aliveNeighbors < 2 || aliveNeighbors > 3)
                {
                    SetCellAlive(x, y, false); // Cell dies
                }
                // If cell has two or three neighbors, it lives
            }
            else
            {
                // If cell is dead and has 3 living neighbors, it becomes alive
                if (aliveNeighbors == 3)
                {
                    SetCellAlive(x, y, true); // Cell becomes alive
                }
            }
        }
    }
}

void Grid::Draw() const
{
    for (int y = 0; y < rows; ++y)
    {
        for (int x = 0; x < columns; ++x)
        {
            if (grid[y][x])
            {
                renderLayer->RenderCell(x, y, true);
                // DrawRectangle(x * 10, y * 10, 10, 10, GREEN); // Draw alive cell
            }
            else
            {
                renderLayer->RenderCell(x, y, false);
            }
        }
    }
}