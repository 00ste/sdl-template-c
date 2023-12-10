#ifndef COMPONENT_H
#define COMPONENT_H

#include "SDL.h"

#include "List.h"

typedef enum CompType {
    NO_COMP = 0;
    TEXT_BUTTON = 1;
} CompType;

// A Component is an abstract GUI element, which can be rendered on the screen and occupies a certain
// position.
// Components are nodes of a tree which has as its root the main window.
// Examples of components are Buttons, TextAreas, Images, Containers, etc...
typedef struct Component {
    SDL_Texture* texture;           // the texture of the component that will be rendered on the screen
    SDL_Rect rect;                  // the position and size of the component relative to its parent component
    struct ListNode* firstChild;    // the first child component
    struct ListNode* lastChild;     // the last child component
    CompType type;                  // the type of the component
    void* compInfo;                 // additional info related to the component, varying on the type
} Component;


// Initialises an empty component with the given rect parameters and no additional information.
// This function should be used as a helper function for more specific functions.
Component* createComponent(int x, int y, int w, int h) {
    Component* comp = (Component*)malloc(sizeof(Component));
    if (!comp) return NULL;
    comp->texture = NULL;
    comp->rect.x = x;
    comp->rect.y = y;
    comp->rect.w = w;
    comp->rect.h = h;
    comp->firstChild = NULL;
    comp->lastChild = NULL;
    comp->type = NO_COMP;
    comp->compInfo = NULL;
    return comp;
}
// Adds the given component as a first child of a given root component
void compAddFirstChild(Component* comp, Component* root) {
    if (!comp || !root) return;
    listInsertBefore(root->firstChild, comp);
}
// Adds the given component as a last child of a given root component
void compAddLastChild(Component* comp, Component* root) {
    if (!comp || !root) return;
    listInsertAfter(root->lastChild, comp);
}



#endif