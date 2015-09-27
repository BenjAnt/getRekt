#include <stdio.h>
#include <stdlib.h>
#include "structure.h"
#ifndef STRUCTURE_H_INCLUDED
#define STRUCTURE_H_INCLUDED
#include "SDL.h"

typedef struct{
  int x;
  int y;
}pos;

  
//typedef struct piece * piece_ptr;

struct object{
  int tab[2][10];
  SDL_Rect src_rect;
  pos coord;
};

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


object_list * object_list_cons(object p, object_list * L){
  int i, j;
  object_list * new = NULL;
  new = (object_list*)malloc(sizeof(object_list));
 for (i = 0; i < 5; i++){
    for(j=0; j < 5; j++){
      new->data = p;
    }
  }
  new->next = (struct object_list *)L;
  return new;
}


