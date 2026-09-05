#include "common.h"
#include "init.h"
#include "input.h"
#include "draw.h"

App app;

int main(void)
{
    init_SDL();

    atexit(cleanup);

    while (app.running) {

        clearSurface();
        drawGrid();

        doInput();
        drawCell(app.mouse.x, app.mouse.y);
        updateSurface();
    
        SDL_Delay((int) TARGET_FPS);
    };

    return 0;
}