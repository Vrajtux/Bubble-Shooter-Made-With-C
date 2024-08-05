
#include <stdio.h>
#include <SDL2/SDL.h>

void doInput(){           // this function simply reads input: here we handle only one that is the window should close when the close button is clicked
  SDL_Event event;
  
  while (SDL_PollEvent(&event)){
    
    switch(event.type){
      
    case SDL_QUIT:  // here SDL_QUIT tell the window to close when the close button is clicked
      exit(0);
      break;

    /* case SDL_KEYUP: */
    /*   keyarrowUp(); */
    /*   printf("up key pressed"); */
    /*   break; */
      
    case SDL_KEYDOWN:
      keyarrowDown();
      printf("down key pressed\n");
      break;

    default:
      break;

    }
  }
}

int keyarrowDown(){
  Player.y++;
  return 0;
}                                                    /* x = right
							-x = left
							y = down
							-y = up
						     */

/* auto keyarrowUp(){ */
/*   Player.y--; */
/*   return 0; */
/* } */
