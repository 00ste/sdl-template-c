#include <stdio.h>
#include "SDL.h"

#include "Application.h"


int main(/*int argc, char *argv[]*/) {
    Application* app = createApplication();
    if (!app) {
        perror("Could not create Application!\n");
        return 1;
    }
    SDL_Event event;

    while (1) {
        SDL_PollEvent(&event);
        if (event.type == SDL_QUIT) {
            break;
        }
        SDL_SetRenderDrawColor(app->renderer, 0x00, 0x00, 0x00, 0x00);
        SDL_RenderClear(app->renderer);
        SDL_RenderPresent(app->renderer);
    }

    destroyApplication(app);

    return 0;
}
