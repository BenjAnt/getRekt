#include <stdio.h>
#include <stdlib.h>
#include "SDL.h"
//#include "getRekt.h"
#include "structure.h"
#include "pipe.h"

void initTab(object * p)
{
  int i, j;
  for (i = 0; i < 10; ++i){
    for (j = 0; j < 2; ++j){
      p->tab[i][j] = 0;
    }
  }
}

object_list * readPipe(object_list * L)
{
   FILE * ptr_file;
  ptr_file = fopen ("source.txt", "r");
  if(!ptr_file){
    printf("Error opening file");
    EXIT_FAILURE;
    }

   int i, j;
  object tmp;
  char c,d;
  i = 0;
  j = 0;
  c = 'a';
  initTab(&tmp);
  
  do{
    d = c;
    c = fgetc(ptr_file);
    if(c == '#'){
      tmp.tab[i][j] = 1;
      j++;
    }

    else if(c =='+'){
      tmp.tab[i][j] = 2;
      j++;
    }

    else if(c == '\n' && d == '\n')
    {
      L = object_list_cons(tmp, L);
      initTab(&tmp);
      i=0;
      j=0;
    }

    else if(c == '\n'){
      i++;
      j = 0;
    }

    else if (c == EOF){
      break;
    }
    else{
      printf("erreur a la lecture du fichier source\ncaractere non conforme\n");
      EXIT_FAILURE;
      }
  }while(c != EOF);
  fclose(ptr_file);
  return L;
}


void afficherPiece(object * o) 
{ 
  int i, j;   
 for(i=0; i<10; i++){ 
	for(j=0; j<2; j++){ 
	  printf("%d ",o->tab[i][j]); 
	  } 
 	printf("\n"); 
       } 
 }
