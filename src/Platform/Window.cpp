#include "Window.h"
#include <SDL2/SDL.h>

static SDL_Window* window = nullptr;
static SDL_Renderer* renderer = nullptr;

namespace Platform {
    bool createWindow(const char* title, int width, int height) {
        if (SDL_Init(SDL_INIT_VIDEO) != 0) {
            return false;
        }

        window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);

        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

        return window && renderer;
    }

    void runWindowLoop() {
        bool running = true;
        SDL_Event event;
        while(running) {
            while(SDL_PollEvent(&event)) {
                if (event.type == SDL_QUIT) {
                    running = false;
                }
            }
            SDL_SetRenderDrawColor(renderer, 173, 216, 230, 255);
            SDL_RenderClear(renderer);
            SDL_RenderPresent(renderer);
        }
    }

    void destroyWindow() {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
}