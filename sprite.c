#include "sprite.h"
#include "main.h"
#include "structure.h"
SDL_Surface *background = NULL;
SDL_Surface *superman =NULL;
SDL_Rect backgroundCoord;
SDL_Rect supermanCoord ;
int continuer = 1;
SDL_Event event;
int gameover = 0 ;

void draw_sprite(object sprite){
  superman=SDL_LoadBMP("superman.bmp");
  supermanCoord.x=10;
  supermanCoord.y=100;
  SDL_SetColorKey(superman, SDL_SRCCOLORKEY, SDL_MapRGB(superman->format,0 ,255 ,0));
  SDL_BlitSurface(superman, NULL, ecran, &supermanCoord);
  
}

void draw_background(object sprite){ 
  backgroundCoord.x = 0;
  backgroundCoord.y = 0;
  background = SDL_LoadBMP("background.bmp");
  SDL_BlitSurface(background, NULL, ecran, &backgroundCoord);
  SDL_Flip(ecran); 
}
void bouger_sprite() {
  while (continuer){
    //SDL_WaitEvent(&event);
SDL_PollEvent(&event);
    switch(event.type){
      case SDL_QUIT:
	continuer = 0;
	break;
      case SDL_KEYDOWN:
	printf("Touche %d enfoncée (caractère produit: %c)\n",
	       event.key.keysym.sym, 
	       event.key.keysym.unicode);
	switch(event.key.keysym.sym) {		  
	case SDLK_SPACE: // barre espace	  
	  supermanCoord.y -= 5;
        
	  //printf("aa");
	  break;}
    case SDL_KEYUP:
      supermanCoord.y += 1;
      while(supermanCoord.y>400 || supermanCoord.y < 0){
	continuer =0;
	break;}
      
      break;
   
    }

    SDL_BlitSurface(background, NULL, ecran, &backgroundCoord);
SDL_BlitSurface(superman, NULL, ecran, &supermanCoord);

SDL_Flip(ecran);
  
   
  }
  
  
}


