#include <vector>
#include <iostream>
#include <raylib.h>
#include <random>
#include <memory>
#include <ctime>

class Renderer;
class Grid
{
private:
    int columns = 0;
    int rows = 0;

    // Could theoretically use a 1D vector or array, but for clarity and ease of access, a 2D vector is used.
    std::vector<std::vector<bool>> grid;

    std::unique_ptr<Renderer> renderLayer;

public:
    Grid(int cols, int rws, Renderer *renderLayer);

protected:
    bool IsCellAlive(int x, int y) const;

    bool SetCellAlive(int x, int y, bool alive);
    inline int GetColumns() const { return columns; }
    inline int GetRows() const { return rows; }

public:
    void Update();

    void Draw() const;

    ~Grid()
    {
        renderLayer = nullptr;
    };
};