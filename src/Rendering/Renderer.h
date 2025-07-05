
#pragma once

class Renderer
{
protected:
    int gridHeight = 0;
    int gridWidth = 0;

public:
    virtual void RenderCell(int x, int y, bool alive) {};
    virtual ~Renderer() = default;
    Renderer(int cellSize, int gridWidth, int gridHeight)
    {
        this->gridWidth = gridWidth;
        this->gridHeight = gridHeight;
    };

    virtual void Setup(int screenWidth, int screenHeight, std::string title) {}

    virtual void Shutdown()
    {
    }

    virtual bool ShouldEndSimulation() { return false; }

    virtual void Update() {}

    virtual void EndUpdate() {}
};