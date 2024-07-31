#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

void prepareScene(void){
  SDL_SetRenderDrawColor(App.renderer, 0, 128, 0, 0); // draws background colour
  SDL_RenderClear(App.renderer);
}

void presentScene(void){
  SDL_RenderPresent(App.renderer);
}

// To render a image :

/*
  ----------------
  |  Load bitmap |
  |  to surface  |
  |--------------|
	 |
	\/
   --------------
   |copy surface|
   |to texture  |
   |------------|
         |
	 \/
   -------------|
   |Copy texture|
   |to renderer |
   |------------|
*/

/* void loadMedia(){ */
/*   SDL_Renderer *Renderer; */
/*   SDL_Surface *testimg = SDL_LoadBMP("img.bmp"); */
/*   SDL_Texture *texture = SDL_CreateTextureFromSurface(Renderer, testimg); */
/*   SDL_RenderCopy(Renderer, texture, NULL, NULL); */
/*   SDL_RenderPresent(Renderer); */
/*   //SDL_Rect dstrect = { 5, 5, 320, 240 }; */
/*   //SDL_RenderCopy(Renderer, texture, NULL, &dstrect); */
/* } */
