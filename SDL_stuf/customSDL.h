#ifndef CUSTOMSDL_H_INCLUDED
#define CUSTOMSDL_H_INCLUDED




/*core.h*/
#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <string>
#include <sstream>
using namespace std;
#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_image.h"
//#include "gGlobal.h"
#include "cGraf.h"
//SDL_Renderer * renderer; g_get_rend(renderer);
//SDL_Window * window; g_get_window(window);
//TEXTURE LOADING AND DRAW


//struct cords {int x,y;};
//TEXT LOADING AND DRAW
TTF_Font* Italic = TTF_OpenFont("BoldItalic.ttf", 24); //sans
TTF_Font* Ruslan = TTF_OpenFont("coolrus.otf", 24);
SDL_Color White = {255, 255, 255};// white
SDL_Color Black = {0, 0, 0};        //black
SDL_Color Dark = {67, 68, 69};    // dark grey
SDL_Color Dark2 = {34, 34, 34};    // dark grey
SDL_Color Grey = {187, 191, 194}; // light grey
SDL_Color Red = {255, 0, 0};      // red
SDL_Color Green = {0, 255, 0};    // green
SDL_Color Blue = {0, 0, 255};     // blue
SDL_Color Yellow = {255,255,0}; //yellow
SDL_Color Cool = { 0,100,100 }; //cool



class customSDL {
public:
    customSDL() {}
    void setup(SDL_Renderer * rende) { this->rende = rende; }
    SDL_Texture* LoadImage(std::string file);
    void ApplySurface(int x, int y, SDL_Texture *tex);
    void CrtTexture(int x, int y,std::string file);
    void DrawRect(int y1, int y2, int x1, int x2, int clr1, int clr2, int clr3, int clr4);
    void DrawRect(int x, int y, int clr1, int clr2, int clr3);
    void new_DrawRect(int x,int y,int w, int h, int r, int g, int b);
    void DrawRect(int y1, int y2, int x1, int x2);

    void DrawText(std::string text,int x, int y, int w, int h, SDL_Color color, int big);
    void DrawPeremen(string name, int perem, int x, int y, int w, int h,SDL_Color color, int big);
protected:
    SDL_Renderer *rende;
    //static SDL_Window * window;
};

SDL_Texture* customSDL::LoadImage(std::string file)
{
   SDL_Surface *loadedImage = nullptr;
   SDL_Texture *texture = nullptr;
    loadedImage = SDL_LoadBMP(file.c_str());


   if (loadedImage != nullptr){
       texture = SDL_CreateTextureFromSurface(rende, loadedImage);
       SDL_FreeSurface(loadedImage);
   }
   else
       std::cout << SDL_GetError() << std::endl;
   return texture;
}

void customSDL::ApplySurface(int x, int y, SDL_Texture *tex)
{
   SDL_Rect pos;
   pos.x = x;
   pos.y = y;
   SDL_QueryTexture(tex, NULL, NULL, &pos.w, &pos.h);
   SDL_RenderCopy(rende, tex, NULL, &pos);
}

void customSDL::CrtTexture(int x, int y, std::string file)
{
    SDL_Texture *tex = LoadImage( file.c_str() );
    ApplySurface(x,y,tex);
    SDL_DestroyTexture( tex );
}


void customSDL::DrawRect(int y1, int y2, int x1, int x2, int clr1, int clr2, int clr3, int clr4)
{
    SDL_Rect fillRect = { y1, x1, y2, x2 };
    SDL_SetRenderDrawColor( rende, clr1, clr2, clr3, clr4 );
    SDL_RenderFillRect( rende, &fillRect );
}


void customSDL::DrawRect(int x, int y, int clr1, int clr2, int clr3)
{
    SDL_Rect fillRect = { y, x, (y+250), (x+150) };
    SDL_SetRenderDrawColor( rende, clr1, clr2, clr3, 0x00 );
    SDL_RenderFillRect( rende, &fillRect );
}

void customSDL::new_DrawRect(int x,int y,int w, int h, int r, int g, int b)
{
    SDL_Rect fillRect;
    fillRect.x = x;
    fillRect.y = y;
    fillRect.w = w;
    fillRect.h = h;
    SDL_SetRenderDrawColor( rende, r, g, b, 255 );
    SDL_RenderFillRect( rende, &fillRect );
}

void customSDL::DrawRect(int y1, int y2, int x1, int x2)
{
    SDL_Rect fillRect = { y1, x1, y2, x2 };
    SDL_SetRenderDrawColor( rende, 0x00, 0x00, 0x00, 0x00 );
    SDL_RenderFillRect( rende, &fillRect );
}


void customSDL::DrawText(std::string text, int x, int y, int w, int h, SDL_Color color, int big)
{
    setlocale(LC_ALL, "Russian");
    TTF_Font* Sans = NULL;
    Sans = TTF_OpenFont("BoldItalic.ttf", big);
    SDL_Surface* surfaceMessage = NULL;
    surfaceMessage = TTF_RenderText_Solid(Sans, text.c_str(), color);
    SDL_Texture* Message = NULL;
    Message = SDL_CreateTextureFromSurface(rende, surfaceMessage);

    SDL_Rect Message_rect;
    Message_rect.x = x;
    Message_rect.y = y;
    Message_rect.w = w;
    Message_rect.h = h;
    SDL_QueryTexture(Message, NULL, NULL, &Message_rect.w, &Message_rect.h);
    //UPDATE/GAMELOOP AREA, I DIDN'T REALLY PASTE THE WHOLE PART
    SDL_RenderCopy(rende, Message, NULL, &Message_rect);
}

void customSDL::DrawPeremen(string name, int perem, int x, int y, int w, int h,SDL_Color color, int big)
{
    stringstream to;
    to << perem;
    string res = name.c_str() + to.str();
    DrawText(res,  x,y, w,h,color,big);
}





/*                                    stringstream ss;
                                    ss << a;
                                string str = ss.str();
                                DrawText(str, White, 200, 200, 200, 100);*/

#endif // CUSTOMSDL_H_INCLUDED
