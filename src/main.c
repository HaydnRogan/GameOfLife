#include "common.h"
#include "init.h"
#include "input.h"
#include "draw.h"
#include "grid.h"

App app;
Grid gridA, gridB;
Grid *prevGrid, *currentGrid;



int main(void)
{
    currentGrid = &gridA;
    prevGrid = &gridB;


    init_SDL();
    initGrid(gridA);
    initGrid(gridB);

    atexit(cleanup);

    while (app.running) {

        clearSurface();
        drawGrid(currentGrid);
        drawGridLines();


        doInput();

        updateSurface();
    
        SDL_Delay((int) TARGET_FPS);
    };

    return 0;
}