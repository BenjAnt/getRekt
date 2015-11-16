#ifndef PIECES_H_INCLUDED
#define PIECES_H_INCLUDED
#include "structure.h"
#include "SDL.h"

object_list * readPipe(object_list * L);
void initTab(object * o);
int printPipe(object o, SDL_Rect supermanCoord);
int printAllPipe(object_list * L, SDL_Rect supermanCoord);
void moveAllPipe(object_list * L);
int checkCollide(SDL_Rect box1, SDL_Rect box2) ;
void gameOver(void);
SDL_Rect initBackground(SDL_Rect backgroundCoord);
SDL_Rect initSuperman(SDL_Rect SupermanCoord);
#endif
