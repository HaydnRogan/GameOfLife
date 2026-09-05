#include "input.h"
#include "grid.h"

extern App app;
extern Grid *currentGrid, *prevGrid;

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
                (*currentGrid)[event.motion.x/CELL_SIZE][event.motion.y/CELL_SIZE] = !((*currentGrid)[event.motion.x/CELL_SIZE][event.motion.y/CELL_SIZE]);
            break;

            case SDL_KEYDOWN:
                if (!event.key.repeat && event.key.keysym.scancode == SDL_SCANCODE_SPACE) {
                    swapGrid(&currentGrid, &prevGrid);
                }

            default:
                break;
        }
    }

    
}