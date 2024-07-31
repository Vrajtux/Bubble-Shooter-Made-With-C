#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <time.h>
#include "headers/defs.h" // header for defined values like screen resolutions, size
#include "headers/structs.h" // will hold refrence to our renderer: place to store settings/context for pixels
#include "headers/input.h"
#include "headers/draw.h"
#include "headers/initsdl.h"

int main(){
  initSDL();
  loadIcon();         
  while(1){
    prepareScene();
    doInput();
    presentScene();
    SDL_Delay(15);
  }
  return 0;
}
