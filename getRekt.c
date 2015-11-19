#include "SDL.h"
#include "structure.h"
#include "getRekt.h"
#include "pipe.h"
#define SUPERMANHEIGHT 85
#define SUPERMANWIDTH 56


void init(void){
  object_list * L = NULL;
  L = readPipe(L);

  SDL_Surface *startScreen = NULL;
  SDL_Rect startScreenCoord; 
  SDL_Event event;

  /* initialize SDL */
  SDL_Init(SDL_INIT_VIDEO);
  SDL_WM_SetCaption("get Rekt", "SDL Animation");

  /* create window */
  screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);


  startScreen = SDL_LoadBMP("startScreen.bmp");
  startScreenCoord.x = 0;
  startScreenCoord.y = 0;
  SDL_BlitSurface(startScreen, NULL, screen, &startScreenCoord);
  SDL_Flip(screen);
  while(SDL_WaitEvent(&event)){
    switch(event.type){
    case SDL_QUIT: 
      //SDL_Quit(); 
      break;
      
    case SDL_KEYDOWN:
      switch(event.key.keysym.sym){
      case SDLK_SPACE: 
	handle_events(L);
	break;
      }
    }
  }
  SDL_FreeSurface(startScreen);
}

void handle_events(object_list * L){
  SDL_Event event;
  SDL_Surface *superman = NULL;
  SDL_Rect supermanCoord, backgroundCoord, pipeCoord;
  SDL_Surface *background = NULL;
  int continuer = 1;
  int collisionSupermanEdge = 0;
  int collisionSupermanPipe = 0;
  int collision = 0;
  background = SDL_LoadBMP("background.bmp");
  backgroundCoord = initBackground(backgroundCoord);

  superman = SDL_LoadBMP("superman.bmp");
  SDL_SetColorKey(superman, SDL_SRCCOLORKEY, SDL_MapRGB(superman->format,0 ,255 ,0));
  supermanCoord = initSuperman(supermanCoord);
  
  while(continuer){
    SDL_PollEvent(&event);
      switch(event.type){
      case SDL_QUIT: 
	continuer = 0; 
	break;
	
      case SDL_KEYDOWN:
	switch(event.key.keysym.sym){
	case SDLK_SPACE: 
	  supermanCoord.y -= 3;
	  break;
	default: break;
	}
      } 
    supermanCoord.y += 1;
    
    collisionSupermanPipe = printAllPipe(L, supermanCoord);  //superman tape un tuyau
    collisionSupermanEdge = !checkCollide(supermanCoord, backgroundCoord); //superman sort de l'écran
    collision = collisionSupermanPipe || collisionSupermanEdge; //OU logique entre les 2 collisions possibles
    
    if(collision == 0){ //pas de collision
      moveAllPipe(L);
      SDL_BlitSurface(background, NULL, screen, &backgroundCoord);
      SDL_BlitSurface(superman, NULL, screen, &supermanCoord);
      printAllPipe(L, supermanCoord);    
    }    
    else{
      freeList(L);
      init();
    }
    SDL_Flip(screen);
  }

  SDL_FreeSurface(background);
  SDL_FreeSurface(superman);
}


int checkCollide(SDL_Rect box1, SDL_Rect box2){
  if((box2.x >= box1.x + box1.w) // trop à droite
     || (box2.x + box2.w <= box1.x) // trop à gauche
     || (box2.y >= box1.y + box1.h) // trop en bas
     || (box2.y + box2.h <= box1.y)) // trop en haut
    return 0;
  else{                     //collision
    return 1;
  }
}

SDL_Rect initBackground(SDL_Rect backgroundCoord){
  backgroundCoord.x = 0;
  backgroundCoord.y = 0;
  backgroundCoord.w = SCREEN_WIDTH;
  backgroundCoord.h = SCREEN_HEIGHT;
  return backgroundCoord;
}

SDL_Rect initSuperman(SDL_Rect supermanCoord){
  supermanCoord.x = 100;
  supermanCoord.y = 100;
  supermanCoord.h = SUPERMANHEIGHT;
  supermanCoord.w = SUPERMANWIDTH;
  return supermanCoord;
}
