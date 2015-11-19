#ifndef STRUCTURE_H_INCLUDED
#define STRUCTURE_H_INCLUDED
#include "SDL.h"

typedef struct{
  int x;
  int y;
}pos;

struct object{
  int tab[10];
  int posX;
  //pos coord;
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
object_list *freeList(object_list *L);



object_list * inverse_list(object_list *lst);

//void object_list_free(object_list * L);

#endif
