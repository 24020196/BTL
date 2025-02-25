#ifndef KHOITAO_H_INCLUDED
#define KHOITAO_H_INCLUDED

void logSDLError(std::ostream& os,const std::string &msg, bool fatal);
void initSDL(SDL_Window* &window, SDL_Renderer* &renderer);
void quitSDL(SDL_Window* window, SDL_Renderer* renderer);

#endif // KHOITAO_H_INCLUDED
