
#include <SDL2/SDL.h>
#include <stdio.h>

struct {
  SDL_Renderer *renderer;
  SDL_Window *window;
} App;

struct {     // this struct stores values for our player 
  int x;
  int y;
  SDL_Texture *texture;;
} Player;
