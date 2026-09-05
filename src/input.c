#include "input.h"

extern App app;
extern Grid grid;
void doInput(void)
{
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                app.running = 0;
                break;

            case SDL_MOUSEBUTTONDOWN:
                grid[event.motion.x/CELL_SIZE][event.motion.y/CELL_SIZE] = !(grid[event.motion.x/CELL_SIZE][event.motion.y/CELL_SIZE]);
            break;

            default:
                break;
        }
    }

    
}