#include <stdlib.h>
#include <stdio.h>
#include "SDL.h"
#include "getRekt.h"
#include "structure.h"
#include "pipe.h"


int main(void)
{
  object_list * L = NULL;
  L = readPipe(L);
  init(L);
  //handle_events(L);
  //SDL_Quit;
  return 0;
}
