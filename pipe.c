#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SDL.h"
#include "getRekt.h"
#include "structure.h"
#include "pipe.h"
#define PIPEHEIGHT 48
#define PIPEWIDTH 80
#define DISTANCE_BETWEEN_PIPE 100
#define FIRST_PIPE_X 500

void initTab(object * p)
{
  int i;
  for (i = 0; i < 10; ++i){
    p->tab[i] = 0;
  }
}


object_list * readPipe(object_list * L)
{
  FILE * ptr_file;
  int i, compteurPipe,coordFirstPipe,distanceWithFirstPipe,j;
  object tmp;
  int c;

  i = 0;
  distanceWithFirstPipe = 0;
  compteurPipe = 0;
  initTab(&tmp);

  ptr_file = fopen ("source.txt", "r");
  if(!ptr_file){
    perror("Error opening file");
    }

  else{
    do{
      c = fgetc(ptr_file);
      if(c == '#'){
	tmp.tab[i] = 1;
	i++;
      }      
      else if(c == '+'){
	tmp.tab[i] = 2;
	i++;
      }      
      else if (c == '\n'){}

      else if (c == '-'){    //si on rencontre un "-" c'est la fin de la lecture d'un pipe, on le stocke dans la liste et on reinitialise le tableau
	i=0;
	tmp.posX = FIRST_PIPE_X + distanceWithFirstPipe;
	L = object_list_cons(tmp, L);
	initTab(&tmp);
	distanceWithFirstPipe += PIPEWIDTH + DISTANCE_BETWEEN_PIPE; 
	compteurPipe+=1;
	printf("nombre de pipes: %d\n",compteurPipe);
      }
      else if(c == -1){
      }
      
      else{
	printf("caractère lu: %d\n", c);
	perror("erreur a la lecture du fichier source\n");
      }
    }while(c != EOF);
    fclose(ptr_file);
  }
  L = inverse_list(L);
  return L;
}

int printPipe(object o, SDL_Rect supermanCoord){ 
  int i = 0;
  int collision = 0;
  SDL_Surface * pipe = NULL;
  SDL_Rect pipeCoord;
  pipeCoord.x = o.posX;
  pipeCoord.y = 0;
  pipeCoord.w = PIPEWIDTH;
  pipeCoord.h = PIPEHEIGHT; 
  pipe = SDL_LoadBMP("pipe.bmp");

  for(i = 0; i < 10; i++){
    if(o.tab[i] == 1){
      if(pipeCoord.x > 0){
	SDL_BlitSurface(pipe, NULL, screen, &pipeCoord);
	
	if(checkCollide(pipeCoord, supermanCoord) == 1){
	  return 1;
	}

	pipeCoord.y += PIPEHEIGHT;
      }
    }
    else if(o.tab[i] == 2){
      pipeCoord.y += PIPEHEIGHT;
    }
  }
  SDL_FreeSurface(pipe);
  return 0;
}

int printAllPipe(object_list * L, SDL_Rect supermanCoord){
  SDL_Rect pipeCoord;
  while(L){
    if(printPipe(L->data, supermanCoord) == 1)
      return 1;
    L = (object_list *)L->next;
    }
  return 0;
}

void moveAllPipe(object_list * L){
  while(L){
    L->data.posX -= 1;
    L = (object_list *)L->next;
  }
}

