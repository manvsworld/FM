#ifndef CGRAF_H_INCLUDED
#define CGRAF_H_INCLUDED

#include <iostream>
#include <random>
#include <ctime>
#include <thread>
#include <vector>
#include <mutex>
#include <stdio.h>
using namespace std;
#include "SDL.h"
#include "customSDL.h"
//#include "gGlobal.h"
//#include "gText.h"
//#include "cButtons.h"
#include <iostream>
#include <random>
#include <ctime>
#include <thread>
#include <vector>
#include <mutex>
using namespace std;
#include "SDL.h"
//#include "gGlobal.h"
class View {
public:
    View() {}
    void setup(SDL_Renderer * renderer, SDL_Window * window) { this->window = window; this->renderer = renderer; }
    void Line(cords p1, cords p2,SDL_Color c);
    void baseSquare(cords p1, cords p4, SDL_Color c);
    void fillSquare(cords p1, cords p4, SDL_Color c);
    void baseShit(cords p1, cords p4);
protected:
    SDL_Window * window;
    SDL_Renderer * renderer;

};

//base func
void View::Line(cords p1, cords p2,SDL_Color c)
{
                SDL_SetRenderDrawColor( renderer, c.r, c.g, c.b, 0 );
                SDL_RenderDrawLine( renderer, p1.x, p1.y, p2.x, p2.y );
                SDL_SetRenderDrawColor(renderer,0,0,0,0);
}
/*
void View::baseShit(cords p1, cords p4, SDL_Color c)
{

                cords p2;
                p2.x = p4.x;
                p2.y = p1.y;

                cords p3;
                p3.x = p1.x;
                p3.y = p4.y;

                Line(p1,p2,c);
                Line(p2,p3,c);
                Line(p3,p4,c);
                Line(p4,p1,c);

}
*/
void View::baseSquare(cords p1, cords p4, SDL_Color clr)
{
                cords p2;
                p2.x = p4.x;
                p2.y = p1.y;

                cords p3;
                p3.x = p1.x;
                p3.y = p4.y;

                Line(p1,p2,clr);
                Line(p2,p4,clr);
                Line(p4,p3,clr);
                Line(p3,p1,clr);
}

void View::fillSquare(cords p1, cords p4, SDL_Color clr)
{
                    SDL_Rect fillRect;
                    fillRect.x = p1.x;
                    fillRect.y = p1.y;
                    fillRect.w = p4.x - p1.x;
                    fillRect.h = p4.y - p1.y;
                    SDL_SetRenderDrawColor( renderer, clr.r, clr.g, clr.b, 255 );
                    SDL_RenderFillRect( renderer, &fillRect );

}

#endif // CGRAF_H_INCLUDED
