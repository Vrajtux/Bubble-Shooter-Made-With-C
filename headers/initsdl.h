#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>

void initSDL(void) {

  int rendererflags, windowflags;
  rendererflags = SDL_RENDERER_ACCELERATED;  // flags for hardware acceleration
  windowflags =  0x00000020, 0x00000040, 0x00000080;  // 0x00000020, SDL_WINDOW_RESIZABLE | 0x00000040, SDL_WINDOW_MINIMIZED | 0x00000080, SDL_WINDOW_MAXIMIZED
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  printf("%d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min);  // logs time 
  printf("Log: Starting SDL\n");
  if(SDL_Init(SDL_INIT_VIDEO) < 0){   // SDL_Init funtion initilizes video and audio system | passing SDL_INIT_VIDEO specifically initializes video subsystem 
    printf("Log: Coudn't initialize SDL: %s\n", SDL_GetError());
    exit(1);
  }
  else {
      printf("Log: Successfully initialized SDL\n");
  }

  App.window = SDL_CreateWindow("Gnome Days", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, windowflags); // here we use SDL_CreateWindow to create a window | First passing the window title, then we tell the function to position the window as the os wants, then we define screen width and height from defs.h and then pass the window flags 
  if (!App.window){
    printf("Log: Failed to open window %s\n" , SDL_GetError());
    exit(1);

  }
  else {
    printf("Log: Succesfully opened a window\n");
  }

  App.renderer = SDL_CreateRenderer(App.window, -1, rendererflags);

  if(!App.renderer){
      printf("Log: Failed to create renderer%s\n", SDL_GetError());
      exit(1);

  //SDL_Surface* icon = IMG_Load("icon.png");
  //SDL_SetWindowIcon(App.window, icon);

  }
  
}

void loadIcon(){
   SDL_Surface* icon = IMG_Load("img/icon/icon.png");
   SDL_SetWindowIcon(App.window, icon);
}
