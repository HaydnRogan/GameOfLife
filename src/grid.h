#pragma once
#include "common.h"

void initGrid(Grid grid);
void swapGrid(Grid **currentGrid, Grid **nextGrid);
int getNeighbours(Grid *grid, int i, int j);
// void doStep(Grid *currentGrid, Grid *prevGrid);