#include <stdlib.h>
#include <stdio.h>
#include "SDL.h"
#include "structure.h"
//#include "getRekt.h"
#include "pipe.h"

void pause(void);

void pause(void)
{
    int continuer = 1;
    SDL_Event event;
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
	  {
            case SDL_QUIT:
                continuer = 0;
        }
    }
}

int main(void)
{
 SDL_Surface *ecran = NULL, *background = NULL,*superman =NULL;
  SDL_Rect backgroundCoord,supermanCoord;
  int i,j;
  int continuer =1;
SDL_Event event;
  object_list * L = NULL;
  object o;
  L = readPipe(L);
  o = L->data;
  afficherPiece(&o);
  //drawPipe(L);

  backgroundCoord.x = 0;
  backgroundCoord.y = 0;

  SDL_Init(SDL_INIT_VIDEO); // Initialisation de la SDL
  

  ecran = SDL_SetVideoMode(960, 478, 32, SDL_HWSURFACE);

  SDL_WM_SetCaption("GET REKT", NULL);   
  
  background = SDL_LoadBMP("background.bmp");
  if(!background) printf("gg");
  SDL_BlitSurface(background, NULL, ecran, &backgroundCoord);
  SDL_Flip(ecran);
  
  superman=SDL_LoadBMP("superman.bmp");
SDL_SetColorKey(superman, SDL_SRCCOLORKEY, SDL_MapRGB(superman->format,0 ,255 ,0));
  supermanCoord.x = ecran->w / 2 - superman->w / 2;
  supermanCoord.y = ecran->h / 2 - superman->h / 2;

  while (continuer)

    {

        SDL_WaitEvent(&event);

        switch(event.type)

        {

            case SDL_QUIT:

                continuer = 0;

                break;

            case SDL_KEYDOWN:

                switch(event.key.keysym.sym)

                {
		  
		case SDLK_SPACE: // barre espace

                        supermanCoord.y -= 20;

                        break;
		  
             
		  
                }
  
                
	}
        
 

     

  SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
        /* On place Zozor à sa nouvelle position */

        SDL_BlitSurface(superman, NULL, ecran, &supermanCoord);

        /* On met à jour l'affichage */

        SDL_Flip(ecran);

	}
    


  pause(); // Mise en pause du programme
  

  //main_loop(L);
  SDL_FreeSurface(background);
  SDL_FreeSurface(superman);
  SDL_Quit(); // Arrêt de la SDL
  return 0;
    
}
