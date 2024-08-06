#include <stdio.h>
#include <SDL2/SDL.h>

void doInput(){           // this function simply reads input: here we handle only one that is the window should close when the close button is clicked
  SDL_Event event;
  
  while (SDL_PollEvent(&event)){
    
    switch(event.type){
      
    case SDL_QUIT:  // here SDL_QUIT tell the window to close when the close button is clicked
      exit(0);
      break; 
      
    case SDL_KEYDOWN:                // SDL_KEYDOWN checks for when a key is pressed down
      keyarrowDown(&event.key);
      break;

    default:
      break;

    }
  }
}

int keyarrowDown(SDL_KeyboardEvent *key){   // the KeyboardEvent checks for keys pressed
  if (key->keysym.sym == SDLK_w){           // the keycode is stored in keysym
    Player.y--;
  }

  if (key->keysym.sym == SDLK_a){
   Player.x--;
 }

  if (key->keysym.sym == SDLK_s){
   Player.y++;
 }

  if (key->keysym.sym == SDLK_d){
   Player.x++;
 }
}
    /* x = right  */
    /* -x = left */
    /* y = down */
    /* -y = up */
