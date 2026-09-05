#include "common.h"
#include "init.h"
#include "input.h"

App app;

int main(void)
{
    init_SDL();

    atexit(cleanup);

    while (app.running) {

        
        doInput();

    };

    return 0;
}