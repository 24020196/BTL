#include <bits/stdc++.h>
#include<SDL.h>
using namespace std;


const int SCREEN_WIDTH = 1500;
const int SCREEN_HEIGHT = 750;
const string WINDOW_TITLE = "An Implementation of Code.org Painter";

void logSDLError(std::ostream& os,const std::string &msg, bool fatal)
{
    os << msg << " Error: " << SDL_GetError() << std::endl;
    if (fatal) {
        SDL_Quit();
        exit(1);
    }
}

void initSDL(SDL_Window* &window, SDL_Renderer* &renderer)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    logSDLError(std::cout, "SDL_Init", true);
    window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if (window == nullptr) logSDLError(std::cout, "CreateWindow", true);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |SDL_RENDERER_PRESENTVSYNC);

    if (renderer == nullptr) logSDLError(std::cout, "CreateRenderer", true);
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
}

void quitSDL(SDL_Window* window, SDL_Renderer* renderer)
{
SDL_DestroyRenderer(renderer);
SDL_DestroyWindow(window);
SDL_Quit();
}

void EventManager(SDL_Window* window,SDL_Renderer* renderer){
    while(true){
    SDL_Event e;
    while(SDL_PollEvent(&e)){
        switch(e.type){
            case SDL_QUIT:

                break;
            case SDL_MOUSEBUTTONDOWN:

                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                int x,y;
                Uint32 buttons = SDL_GetMouseState(&x, &y);
                SDL_RenderDrawPoint(renderer,x, y);
                SDL_RenderPresent(renderer);

                break;

        }
        switch(e.key.keysym.sym)
        {

            case SDLK_ESCAPE:
                quitSDL(window,renderer);
                exit(0);
                break;
        }
    }
    }
}

int main(int argc, char* argv[])
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    initSDL(window, renderer);
    EventManager(window,renderer);
    //quitSDL(window,renderer);
    return 0;
}
