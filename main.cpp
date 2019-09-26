#include <iostream>
#include <stdio.h>
#include <string>
#include <map>
#include <vector>
#include <thread>
#include <mutex>
#include <string>
using namespace std;
#include "SDL.h"
#include "gGlobal.h"
#include "mObserver.h"
#include "SDL_stuf/cGraf.h"
#include "SDL_stuf/customSDL.h"
int main(int argc, char** argv)
{

    SDL_Renderer * renderer = nullptr;
    SDL_Window * window = nullptr;

    // õìõæõõêõãşæõú áÿåöí sdl
   if (SDL_Init(SDL_INIT_EVERYTHING) == -1){
       std::cout << SDL_GetError() << std::endl;

   }
          // ÿíãäşìõå íéìş
   window = SDL_CreateWindow("gg_1", SDL_WINDOWPOS_CENTERED,/*ÆÅÌĞÏÕÏÑÅĞ ÍÉÌÍ*/
       SDL_WINDOWPOS_CENTERED, SCREEN_W, SCREEN_H, SDL_WINDOW_SHOWN);
   if (window == nullptr){
       std::cout << SDL_GetError() << std::endl;

   }
   // ÿíãäşìõå ïåìäåïş
   renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED
       | SDL_RENDERER_PRESENTVSYNC);
   if (renderer == nullptr){
       std::cout << SDL_GetError() << std::endl;

   }
   View grf;grf.setup(renderer,window);
   customSDL cast;
   cast.setup(renderer);
    while(true) {

    cast.CrtTexture(100,100,"STT.bmp");
    cast.DrawText("POKA GOVNO\n VOT TAK VOT \n RABOTAEM",50,50,100,100,Red,36);
    }
    cout << SDL_GetError() << endl;
}
