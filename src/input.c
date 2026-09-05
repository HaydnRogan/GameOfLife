#include "input.h"
#include "grid.h"

extern App app;
extern Grid *currentGrid, *prevGrid;

void doInput(void)
{
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        SDL_GetMouseState(&app.mouse.x, &app.mouse.y);
        switch (event.type) {
            case SDL_QUIT:
                app.running = 0;
                break;

            case SDL_MOUSEBUTTONDOWN:
                (*currentGrid)[app.mouse.x / CELL_SIZE]
                              [app.mouse.y / CELL_SIZE] =
                                  !((*currentGrid)[app.mouse.x / CELL_SIZE]
                                                  [app.mouse.y / CELL_SIZE]);
                break;

            case SDL_KEYDOWN:
                if (!event.key.repeat) {
                    switch (event.key.keysym.scancode) {

                        case SDL_SCANCODE_SPACE:
                            swapGrid(&currentGrid, &prevGrid);
                            break;

                        case SDL_SCANCODE_BACKSLASH:
                            printf("N = %d\n", getNeighbours(currentGrid, app.mouse.x / CELL_SIZE,
                                          app.mouse.y / CELL_SIZE));
                           
                            
                                
                            break;

                        default:
                            break;
                    }
                }

            default:
                break;
        }
    }
}