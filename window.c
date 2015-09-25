#include <stdlib.h>

#include <stdio.h>

#include <SDL/SDL.h>

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
 

int main(int argc, char *argv[])
{
  SDL_Surface *ecran = NULL, *background = NULL;
  SDL_Rect backgroundCoord;
  
  backgroundCoord.x = 0;
  backgroundCoord.y = 0;

  SDL_Init(SDL_INIT_VIDEO); // Initialisation de la SDL
  

  ecran = SDL_SetVideoMode(960, 478, 32, SDL_HWSURFACE);

  SDL_WM_SetCaption("GET REKT", NULL);   
  
  background = SDL_LoadBMP("background.bmp");
  SDL_BlitSurface(background, NULL, ecran, &backgroundCoord);
  SDL_Flip(ecran);
  pause(); // Mise en pause du programme
  
  SDL_FreeSurface(background);
  
  SDL_Quit(); // Arrêt de la SDL
  
  
  
  return EXIT_SUCCESS; // Fermeture du programme
  
}
