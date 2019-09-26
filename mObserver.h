#ifndef MOBSERVER_H_INCLUDED
#define MOBSERVER_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
//model + menu_handler
#include "gDraw.h"
#include "gGlobal.h"
#include "cMenu_Handler.h"
class Observer {
public:
	Observer() {}
	void setup();
	void run();
protected:
	Model modela;
	Menu_Handler m_handler;
	SDL_Renderer * renderer;
	SDL_Window * window;

	bool quit;
};

void Observer::setup( )
{
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



    m_handler.setup(renderer,window, &modela);

    //  cars
    modela.add_car("X7L5SRMAZ62258432","Ren Sandero",844);
    modela.add_car("X7L4SRMAZ62552158","Ren Logan",063);
    modela.add_car("X7LHSRHGN62685231","Ren Duster",801);
    modela.add_car("X7LASRBA662383007","Ren Kaptur",629);
    modela.add_car("","Ren Duster",637);
    modela.add_car("Y3WFN9RS2HB007012","Cad XT5",360);
    modela.add_car("Y3WFN9RS1HB007264","Cad XT5",275);

    modela.add_car("1GYS47KJ4JR292867","Cad Escalade",96);
    modela.add_car("Y3WFN9RS1HB007261","Cad XT5",418);
    modela.add_car("Y3WS48KJ6GB005259","Cad Escalade",438);

    //  menus
    m_handler.add_menu(MAIN);
    m_handler.connect_output(d_main,MAIN);
    //m_handler.add_button()








    m_handler.run_menu(0,true);
}

void Observer::run()
{
    quit = false;
    while(!quit)
    {
        m_handler.check_runs();
    }
}

/*
	car[0].setup("X7L5SRMAZ62258432",844,"Ren Sandero");
	car[1].setup("X7L4SRMAZ62552158",063,"Ren Logan");
	car[2].setup("X7LHSRHGN62685231",801,"Ren Duster");
	car[3].setup("X7LASRBA662383007",629,"Ren Kaptur");
	car[4].setup("",637,"Ren Duster");
	car[5].setup("Y3WFN9RS2HB007012",360,"Cad XT5");
	car[6].setup("Y3WFN9RS1HB007264",275,"Cad XT5");
	car[7].setup("1GYS47KJ4JR292867",096,"Cad Escalade");
	car[8].setup("Y3WFN9RS1HB007261",418,"Cad XT5");
	car[9].setup("Y3WS48KJ6GB005259",438,"Cad Escalade");
*/

#endif // MOBSERVER_H_INCLUDED
