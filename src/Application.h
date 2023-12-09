#ifndef APPLICATION_H
#define APPLICATION_H

#include <stdio.h>
#include "SDL.h"

typedef struct Application {
    SDL_Window* window;
    SDL_Renderer* renderer;
} Application;

Application* createApplication();
void destroyApplication(Application* app);

#endif /* APPLICATION_H */