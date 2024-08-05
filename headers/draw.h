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
  |  Load image  |
  |  to surface  |
  |--------------|
	||
	\/
   --------------
   |copy surface|
   |to texture  |
   |------------|
         ||
	 \/
   -------------|
   |Copy texture|
   |to renderer |
   |------------|

      the funtion IMG_Load or IMG_LoadTexture will do that process for us*/

//SDL_Texture *loadTexture(char *filename)
SDL_Texture *loadMedia(char *filename)
{
  SDL_Texture *texture;
  texture = IMG_LoadTexture(App.renderer, filename);  // the function IMG_LoadTexture will load an image and return it as a texture | this fucntion takes two parameters the renderer and the filename
  return texture;
}

void blit(SDL_Texture *texture, int x, int y)     // this function simply puts the texture on the screen at specified co-ordinates
{
    SDL_Rect dest;
    
    dest.x = x;
    dest.y = y;
    SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);
    
    SDL_RenderCopy(App.renderer, texture, NULL, &dest);   // the actual drawing of the texture/img on the screen | the four parameter are renderer, our texture/img, i dont what that shit is, and  then our co-ordinates
    
}

