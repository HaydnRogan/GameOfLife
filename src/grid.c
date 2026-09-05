#include "grid.h"

void initGrid(Grid grid)
{
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

static Pos getIndex(int i, int j)
{
    Pos p;
    if ((i) < 0) {
        p.i = NCOLS - 1;
    } else if (i > (NCOLS - 1)) {
        p.i = 0;
    } else {
        p.i = i;
    }

    if ((j) < 0) {
        p.j = NROWS - 1;
    } else if (j > (NROWS - 1)) {
        p.j = 0;
    } else {
        p.j = j;
    }

    return p;
}

int getNeighbours(Grid *grid, int i, int j)
{
    Pos nw = getIndex(i - 1, j - 1);
    Pos n = getIndex(i, j - 1);
    Pos ne = getIndex(i + 1, j - 1);
    Pos e = getIndex(i + 1, j);
    Pos se = getIndex(i + 1, j + 1);
    Pos s = getIndex(i, j + 1);
    Pos sw = getIndex(i - 1, j + 1);
    Pos w = getIndex(i - 1, j);

    return ((*grid)[nw.i][nw.j] + (*grid)[n.i][n.j] + (*grid)[ne.i][ne.j] +
            (*grid)[w.i][w.j] + (*grid)[e.i][e.j] + (*grid)[sw.i][sw.j] +
            (*grid)[s.i][s.j] + (*grid)[se.i][se.j]);
}

void doStep(Grid **currentGrid, Grid **nextGrid)
{

    // clear the next buffer
    initGrid(**nextGrid);

    // for each cell in the current grid get the number of neighbours
    int N;
    for (int i = 0; i < NCOLS; i++) {
        for (int j = 0; j < NROWS; j++) {

            N = getNeighbours(*currentGrid, i, j);

            // live cell rules
            if ((**currentGrid)[i][j]) {
                // Any live cell with fewer than two live neighbours dies, as if
                // by underpopulation.
                if (N < 2) {
                    (**nextGrid)[i][j] = 0;
                }

                // Any live cell with two or three live neighbours lives on to
                // the next generation.
                else if (N == 2 || N == 3) {
                    (**nextGrid)[i][j] = 1;
                }

                // Any live cell with more than three live neighbours dies, as
                // if by overpopulation.
                else if (N > 3) {
                    (**nextGrid)[i][j] = 0;
                }

            }
            // dead cell rules
            else {
                // Any dead cell with exactly three live neighbours becomes a
                // live cell, as if by reproduction.
                if (N == 3) {
                    (**nextGrid)[i][j] = 1;
                }
            }
        }
    }
    // swap the buffers
    swapGrid(currentGrid, nextGrid);
}
