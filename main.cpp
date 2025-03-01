#include <bits/stdc++.h>
#include<SDL.h>
#include "SDL_image.h"
#include "khoitao.h"
#include "menu.h"
#include "game.h"

using namespace std;




int main(int argc, char* argv[])
{
    SDL_Window  *window;
    SDL_Renderer *renderer;
    initSDL(window, renderer);

    while(true){
        renmenu(window,renderer);
        menuevent(window,renderer);
        int dokho;
        ifstream file("temp.txt");
        file>>dokho;
        file.close();
        loopgame(window,renderer,dokho);
    }
    return 0;
}
