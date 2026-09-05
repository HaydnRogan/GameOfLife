#include "input.h"

extern App app;
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

            default:
                break;
        }
    }

    SDL_GetMouseState(&app.mouse.x, &app.mouse.y);
}