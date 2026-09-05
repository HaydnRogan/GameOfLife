#include "init.h"

extern App app;

void init_SDL(void)
{
    SDL_Init(SDL_INIT_VIDEO);

    app.window = SDL_CreateWindow("Game of Life", SDL_WINDOWPOS_UNDEFINED,
                                  SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                                  SCREEN_HEIGHT, 0);
    app.renderer = SDL_CreateRenderer(app.window, -1, SDL_RENDERER_ACCELERATED);
    app.running = 1;
}

void cleanup(void)
{
    SDL_DestroyRenderer(app.renderer);
    SDL_DestroyWindow(app.window);
    SDL_Quit();
}
