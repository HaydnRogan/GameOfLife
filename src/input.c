#include "input.h"
#include "grid.h"

extern App app;
extern Grid *currentGrid, *nextGrid;

static int selectedMode;
static int mouseDown;

void doInput(void)
{
    SDL_Event event;

    SDL_GetMouseState(&app.mouse.x, &app.mouse.y);
    if (app.mouse.x < 0) {
        app.mouse.x = 0;
    } else if (app.mouse.x > SCREEN_WIDTH) {
        app.mouse.x = SCREEN_WIDTH - 1;
    }
    if (app.mouse.y < 0) {
        app.mouse.y = 0;
    } else if (app.mouse.y > SCREEN_HEIGHT) {
        app.mouse.y = SCREEN_HEIGHT - 1;
    }

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                exit(0);
                break;

            case SDL_MOUSEBUTTONDOWN:
                mouseDown = 1;
                selectedMode = !(*currentGrid)[app.mouse.x / CELL_SIZE]
                                              [app.mouse.y / CELL_SIZE];
                break;

            case SDL_MOUSEBUTTONUP:
                mouseDown = 0;
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
                break;
                
            default:
                break;
        }
    }

    if (mouseDown) {
        (*currentGrid)[app.mouse.x / CELL_SIZE][app.mouse.y / CELL_SIZE] =
            selectedMode;
    }
}