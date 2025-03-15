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
        SDL_Init(SDL_INIT_AUDIO);
        SDL_AudioSpec wavSpec;
        Uint32 wavLength;
        Uint8 *wavBuffer;
        SDL_LoadWAV("music.wav", &wavSpec, &wavBuffer, &wavLength);
        SDL_AudioDeviceID deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);
        SDL_QueueAudio(deviceId, wavBuffer, wavLength);
        SDL_PauseAudioDevice(deviceId, 0);

        renmenu(window,renderer);
        int dokho;
        ifstream file("temp.txt");
        file>>dokho;
        file.close();
        loopgame(window,renderer,dokho);

        SDL_PauseAudioDevice(deviceId,1);
        SDL_CloseAudioDevice(deviceId);
        SDL_FreeWAV(wavBuffer);
    }

    return 0;
}
