#include "input.h"
#include "grid.h"

extern App app;
extern Grid *currentGrid, *nextGrid;

void doInput(void)
{
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        SDL_GetMouseState(&app.mouse.x, &app.mouse.y);
        switch (event.type) {
            case SDL_QUIT:
                exit(0);
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
                                doStep(&currentGrid, &nextGrid);
                            break;

                        case SDL_SCANCODE_BACKSLASH:
                            app.running = !(app.running);
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