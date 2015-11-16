#ifndef GETREKT_H_INCLUDED
#define GETREKT_H_INCLUDED
#define SCREEN_WIDTH 960
#define SCREEN_HEIGHT 478
#include "structure.h"
#include "pipe.h"

int gameover;
SDL_Surface* screen;

void init(void);
void main_loop(void);
void handle_events(object_list * L);
#endif
