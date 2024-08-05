#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <stdio.h>

int bgMusic() {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        fprintf(stderr, "SDL_Init Error: %s\n", SDL_GetError());
        return 1;
    }

    // Initialize SDL_mixer
    if (Mix_Init(MIX_INIT_MP3) == 0) {
        fprintf(stderr, "Mix_Init Error: %s\n", Mix_GetError());
        SDL_Quit();
        return 1;
    }

    if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 2048) != 0) {
        fprintf(stderr, "Mix_OpenAudio Error: %s\n", Mix_GetError());
        Mix_Quit();
        SDL_Quit();
        return 1;
    }

    // Load music
    Mix_Music* music = Mix_LoadMUS("sound/background/background.mp3");
    if (music != NULL) {
        Mix_PlayMusic(music, 0);
        printf("wait music start...\n");

        // Wait until the music starts playing
        while (Mix_PlayingMusic() == 0) {
            SDL_Delay(1000);
        }
        printf("music started\n");

        // Wait until the music stops playing
        while (Mix_PlayingMusic()) {
            SDL_Delay(1000);
        }
        printf("music play end\n");

        // Free the music
        Mix_FreeMusic(music);
    } else {
        fprintf(stderr, "Music load failed: %s\n", Mix_GetError());
    }

    // Clean up
    Mix_Quit();
    SDL_Quit();

    return 0;
}
