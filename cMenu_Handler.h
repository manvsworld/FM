#ifndef CMENU_HANDLER_H_INCLUDED
#define CMENU_HANDLER_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
#include "SDL.h"
#include "cMenu.h"
#include "gGlobal.h"
//#include "Logs/cLog.h"

class Model;

class Menu_Handler {
public:
    Menu_Handler() {}
    void setup(SDL_Renderer * renderer, SDL_Window * window, Model * modela);
    void add_menu( int name ) { Menu news;  menus.push_back(news); menus[menus.size()-1].setup(name,wnd,rnd,modela,this); }
    void add_button( int x, int y, int w, int h, int dest, int place ) { menus[seek_menu(place)].add_button(x,y,w,h,dest); }

    int seek_menu(int name);
    void run_menu(int id, bool stat)  { menus[id].switcha(stat); }
	void check_runs();

	void connect_output(void (*ppp)(Model * modela),int place) { output outs = {place, ppp};  menus[seek_menu(place)].connect_output(outs); }
protected:
    vector<Menu> menus;
    SDL_Window * wnd;
    SDL_Renderer * rnd;
    Model * modela;

};



#endif // CMENU_HANDLER_H_INCLUDED
