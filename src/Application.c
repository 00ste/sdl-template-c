#include "Application.h"

Application* createApplication() {
    Application* app = (Application*)malloc(sizeof(Application));
    if (!app) {
        perror("Could not allocate memory for Application!\n");
        return NULL;
    }
    app->window = NULL;
    app->renderer = NULL;
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL: %s", SDL_GetError());
        return NULL;
    }

    if (SDL_CreateWindowAndRenderer(320, 240, SDL_WINDOW_SHOWN, &app->window, &app->renderer)) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window and renderer: %s", SDL_GetError());
        return NULL;
    }

    return app;
}
void destroyApplication(Application* app) {
    SDL_DestroyRenderer(app->renderer);
    SDL_DestroyWindow(app->window);

    SDL_Quit();

    free(app);
    app = NULL;
}