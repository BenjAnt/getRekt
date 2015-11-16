#include <stdio.h>
#include <stdlib.h>
#include "structure.h"
#include "SDL.h"



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

object_list * inverse_list(object_list *lst){
  object_list *tmp1;
  object_list *tmp2;

  if(lst != NULL){
    tmp1 = lst->next;
    lst->next = NULL;
    
    while(tmp1 != NULL){
      tmp2 = tmp1->next;
      tmp1->next = lst;
      lst = tmp1;
      tmp1 = tmp2;
    }
  }
  return lst;
}


