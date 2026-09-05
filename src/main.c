#include "common.h"
#include "init.h"
#include "input.h"
#include "draw.h"
#include "grid.h"

App app;
Grid gridA, gridB;
Grid *nextGrid, *currentGrid;



int main(void)
{
    currentGrid = &gridA;
    nextGrid = &gridB;


    init_SDL();
    initGrid(gridA);
    initGrid(gridB);

    atexit(cleanup);

    while (1) {

        clearSurface();
        
        doInput();
        
        if (app.running) {
            doStep(&currentGrid, &nextGrid);
        }
        
        drawGrid(currentGrid);
        drawGridLines();

        updateSurface();
    
        SDL_Delay((int) TARGET_FPS);
    };

    return 0;
}