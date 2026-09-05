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
    printf("Input (%d, %d)\n", i, j);
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

    printf("Ouput (%d, %d)\n", p.i, p.j);
    return p;
}

int getNeighbours(Grid *grid, int i, int j)
{
    printf("CELL (%d, %d)\n", i, j);
    printf("nw \n");
    Pos nw = getIndex(i - 1, j - 1);
    printf("n:\n");
    Pos n = getIndex(i, j - 1);
    printf("ne:\n");
    Pos ne = getIndex(i + 1, j - 1);
    printf("e:\n");
    Pos e = getIndex(i + 1, j);
    printf("se:\n");
    Pos se = getIndex(i + 1, j + 1);
    printf("s:\n");
    Pos s = getIndex(i, j + 1);
    printf("sw:\n");
    Pos sw = getIndex(i - 1, j + 1);
    printf("w:\n");
    Pos w = getIndex(i - 1, j);

    printf("%d %d %d\n%d   %d\n%d %d %d\n\n",(*grid)[nw.i][nw.j], (*grid)[n.i][n.j], (*grid)[ne.i][ne.j], (*grid)[w.i][w.j], (*grid)[e.i][e.j], (*grid)[sw.i][sw.j], (*grid)[s.i][s.j], (*grid)[se.i][se.j]);
    return ((*grid)[nw.i][nw.j]+ (*grid)[n.i][n.j]+ (*grid)[ne.i][ne.j]+ (*grid)[w.i][w.j]+ (*grid)[e.i][e.j]+ (*grid)[sw.i][sw.j]+ (*grid)[s.i][s.j]+ (*grid)[se.i][se.j]);

}
// void doStep(Grid *currentGrid, Grid *prevGrid)
// {

// }