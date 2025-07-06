
#include "Renderer.h"
#include <iostream>

class TerminalRenderer : public Renderer
{
public:
    TerminalRenderer(int cellSize, int gridWidth, int gridHeight) : Renderer(cellSize, gridWidth, gridHeight) {}

    void Update() override
    {
        system("CLS");
    }

    void EndUpdate() override
    {
    }

    void RenderCell(int x, int y, bool alive) override
    {
        // Print a character for the cell
        std::cout << (alive ? 'O' : ' ');
        if (x == gridWidth - 1)
        {
            std::cout << std::endl; // New line at the end of each row
        }
    };

    void Setup(std::string title) override
    {
        std::cout << "Terminal Renderer initialized with title: " << title << std::endl;
    }

    bool ShouldEndSimulation() override
    {
        return false;
    }

    void Shutdown() override
    {
    }
};