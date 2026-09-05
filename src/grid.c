#include "grid.h"


void initGrid(Grid grid) {
    for (int i = 0; i < NCOLS; i++) {
        for (int j = 0; j < NROWS; j++) {
            grid[i][j] = 0;
        }
    }
}

void swapGrid(Grid *(*currentGrid), Grid *(*nextGrid))
{
    Grid *tmp = *currentGrid;
    *currentGrid = *nextGrid;
    *nextGrid = tmp;
}