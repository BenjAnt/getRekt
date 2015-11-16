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
  init();
  handle_events(L);
  return 0;
}
