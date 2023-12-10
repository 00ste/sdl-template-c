#ifndef BUTTON_H
#define BUTTON_H

#include <stdlib.h>
#include <stdio.h>

#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_image.h"

#include "Component.h"


typedef enum ButtonState {
    INACTIVE = 0;
    HOVER = 1;
    ACTIVE = 2;
    DISABLED = 3;
} ButtonState;

typedef struct TextButton {
    char* text;
    ButtonState state;
} TextButton;

typedef struct ImgButton {
    char* imgPassive;
    char* imgHover;
    char* imgActive;
    ButtonState state;
} ImgButton;


// Creates a new TextButton object with the given text
Component* createTextButton(const char* text) {
    Component* button = createComponent();
    button->type = TEXT_BUTTON;
    TextButton* data = (TextButton*)malloc(sizeof(TextButton));
    data->state = INACTIVE;
    data->text = text;
    button->compInfo = data;
    return button;
}

#endif