#ifndef STRUCTURE_H_INCLUDED
#define STRUCTURE_H_INCLUDED
#include "SDL.h"

typedef struct{
  int x;
  int y;
}pos;

struct object{
  int tab[10][2];
  SDL_Rect src_rect;
  pos coord;
};

typedef struct{
  char r;
  char g;
  char b;
}rgb;

typedef struct object object;

struct object_list{
  object data;
  struct object_list * next;
};

typedef struct object_list object_list;

/* "constructors" */

object_list * object_list_cons(object p, object_list* L);

/* free function */

//void object_list_free(object_list * L);

#endif
