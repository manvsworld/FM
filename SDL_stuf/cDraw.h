#ifndef CDRAW_H_INCLUDED
#define CDRAW_H_INCLUDED

#include "customSDL.h"
#include "cGraf.h"
#include <iostream>

class Draw {
public:
    Draw() {cast.setup(renderer);graf.setup(renderer,window); graf_pp.setup(window,renderer);}
    void setup(SDL_Renderer * renderer, SDL_Window * window);
    void start_draw_thread();
    void sclr(SDL_Color clr) { this->clr = clr;  graf_pp.set_draw_color(clr);}
protected:
    SDL_Window * window;
    SDL_Renderer * renderer;
    SDL_Color clr;
    View graf;
    customSDL cast;
    Graf_PP graf_pp;
};

void Draw::setup(SDL_Renderer * renderer, SDL_Window * window)
{
    this->window = window;
    this->renderer = renderer;
    //cast.setup(renderer,window);
}


void Draw::start_draw_thread()
{
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer,0,0,0,0);

    graf_pp.lista(10,10,10,10,50,50);

    SDL_RenderPresent(renderer);
}



#endif // CDRAW_H_INCLUDED
