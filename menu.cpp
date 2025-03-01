#include <bits/stdc++.h>
#include<SDL.h>
#include "SDL_image.h"
#include "khoitao.h"
using namespace std;
SDL_Texture *png_mainbg ,*png_sword ;

void menuevent(SDL_Window* window,SDL_Renderer* renderer)
{
    SDL_Event e;
    while(true)
    {
        SDL_Delay(33);
        while(SDL_PollEvent(&e))
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
                    ofstream f("temp.txt");
                    if(y>=390&&y<=450) f<<2;
                    if(y>=450&&y<=510) f<<3;
                    if(y>=510&&y<=570) f<<4;
                    if(y>=570&&y<=630)quitSDL(window,renderer);
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
                SDL_RenderCopy(renderer,png_mainbg,NULL,NULL);
                Uint32 buttons = SDL_GetMouseState(&x, &y);
                if(x>=500&&x<=1000)
                if(y>=390&&y<=630)
                {
                    if(y>=390&&y<=450) rect.y=403;
                    if(y>=450&&y<=510) rect.y=463;
                    if(y>=510&&y<=570) rect.y=523;
                    if(y>=570&&y<=630) rect.y=583;
                    SDL_RenderCopy(renderer,png_sword,NULL,&rect);

                }
                SDL_RenderPresent(renderer);


                break;
            }

        }


    }
}

void renmenu(SDL_Window* window,SDL_Renderer* renderer)
{
    png_mainbg = IMG_LoadTexture(renderer,"mainbg.png");
    png_sword = IMG_LoadTexture(renderer,"sword.png");

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer,png_mainbg,NULL,NULL);
    SDL_RenderPresent(renderer);

    menuevent(window,renderer);

    SDL_DestroyTexture(png_mainbg);
    SDL_DestroyTexture(png_sword);

}
