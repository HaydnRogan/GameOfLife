#include "draw.h"

extern App app;

void drawCell(int x, int y)
{

    SDL_Rect cell = {x, y, CELL_SIZE, CELL_SIZE};

    SDL_FillRect(app.surface, &cell, COLOUR_WHITE);
}

void clearSurface(void)
{
    SDL_FillRect(app.surface, &((SDL_Rect){0, 0, SCREEN_WIDTH, SCREEN_HEIGHT}),
                 COLOUR_BLACK);
}

void drawGrid(void)
{

    // Drawing Columns
    for (int x = 0; x < SCREEN_WIDTH; x += CELL_SIZE) {
        SDL_Rect line = {x, 0, 1, SCREEN_HEIGHT};
        SDL_FillRect(app.surface, &line, COLOUR_GREY);
    }

    // Drawing Rows
    for (int y = 0; y < SCREEN_HEIGHT; y += CELL_SIZE) {
        SDL_Rect line = {0, y, SCREEN_WIDTH, 1};
        SDL_FillRect(app.surface, &line, COLOUR_GREY);
    }
}

void updateSurface(void)
{
    SDL_UpdateWindowSurface(app.window);
}