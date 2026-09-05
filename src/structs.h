#pragma once
#include "common.h"

typedef struct {
    SDL_Window *window;
    SDL_Renderer *renderer;
    int running;
} App;