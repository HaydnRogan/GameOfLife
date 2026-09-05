#pragma once
#include "common.h"

typedef struct {
    int x, y;
} Mouse;

typedef struct {
    SDL_Window *window;
    SDL_Surface *surface;
    int running;
    Mouse mouse;
} App;

