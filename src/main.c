#include "common.h"
#include "init.h"
#include "input.h"
#include "draw.h"
#include "grid.h"

App app;
Grid grid;

int main(void)
{
    init_SDL();
    initGrid();

    atexit(cleanup);

    while (app.running) {

        clearSurface();
        drawGrid(grid);
        drawGridLines();


        doInput();

        updateSurface();
    
        SDL_Delay((int) TARGET_FPS);
    };

    return 0;
}