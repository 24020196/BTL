#include <bits/stdc++.h>
#include<SDL.h>
#include "SDL_image.h"
#include "khoitao.h"
using namespace std;
void renmenu(SDL_Window* window,SDL_Renderer* renderer)
{
    SDL_Texture* bg = IMG_LoadTexture(renderer,"mainbg.png");
    SDL_RenderCopy(renderer,bg,NULL,NULL);
    SDL_RenderPresent(renderer);
    SDL_DestroyTexture(bg);
}
void menuevent(SDL_Window* window,SDL_Renderer* renderer)
{
    SDL_Event e;
    while(true)
    while(SDL_PollEvent(&e)){
        switch(e.type){
            case SDL_QUIT:{

                break;
            }
            case SDL_MOUSEBUTTONDOWN:{

                int x,y;
                Uint32 buttons = SDL_GetMouseState(&x, &y);
                if(x>=500&&x<=1000)
                if(y>=390&&y<=630)
                {
                    fstream f("temp.txt");
                    if(y>=390&&y<=450) f<<1;
                    if(y>=450&&y<=510) f<<2;
                    if(y>=510&&y<=570) f<<3;
                    if(y>=570&&y<=630) f<<4;
                    f.close();
                    return ;
                }
                break;
            }
            case SDL_MOUSEMOTION:{
                SDL_RenderClear(renderer);
                SDL_Rect rect;
                int x,y;
                rect.x=515;
                rect.h=30;
                rect.w=100;
                SDL_Texture* bg = IMG_LoadTexture(renderer,"mainbg.png");
                SDL_RenderCopy(renderer,bg,NULL,NULL);
                SDL_DestroyTexture(bg);
                Uint32 buttons = SDL_GetMouseState(&x, &y);
                if(x>=500&&x<=1000)
                if(y>=390&&y<=630)
                {
                    if(y>=390&&y<=450) rect.y=403;
                    if(y>=450&&y<=510) rect.y=463;
                    if(y>=510&&y<=570) rect.y=523;
                    if(y>=570&&y<=630) rect.y=583;
                    bg = IMG_LoadTexture(renderer,"sword.png");
                    SDL_RenderCopy(renderer,bg,NULL,&rect);
                    SDL_DestroyTexture(bg);

                }
                SDL_RenderPresent(renderer);


                break;
            }

        }
        switch(e.key.keysym.sym)
        {

            case SDLK_ESCAPE:

               quitSDL(window,renderer);

                break;

        }
    }

}
