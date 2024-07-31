#include <stdio.h>
#include <SDL2/SDL.h>

void doInput(){           // this function simply reads input: here we handle only one that is the window should close when the close button is clicked
  SDL_Event event;

  while (SDL_PollEvent(&event)){

    switch(event.type){

    case SDL_QUIT:  // here SDL_QUIT tell the window to close when the close button is clicked
      exit(0);
      break;

    default:
      break;

    }
  }
}
