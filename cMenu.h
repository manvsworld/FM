#ifndef CMENU_H_INCLUDED
#define CMENU_H_INCLUDED
#include <iostream>
#include <stdio.h>
#include <string>
#include <map>
#include <vector>
#include <thread>
#include <mutex>
#include <string>
using namespace std;
/*cMenu.h*/
#include "gGlobal.h"
#include "SDL.h"
#include "input/cButton.h"

//#include "cModel.h"
/*
void Button::status(bool clicked, menu_switch * menu_caller)
{
    b_status.dest.active=clicked;
	//if( seek_menu_in_m_list(  ) )//wtf3
    Switcher(&menu_caller, &b_status);
}
*/
#include "Logs/cLog.h"
#include "SDL_ttf.h"
#include "SDL_image.h"
class Click {
public:
    Click() {}
    void born(int * mx, int * my)
    {
    SDL_GetMouseState(mx,my);
    this->mx = *mx; this->my = *my;
    log.open("Logs\\log_clicks.txt");
    string logss = "| mx = " + std::to_string(this->mx) + " | my = " + std::to_string(this->my) + " |" + "\n";
    log.write( logss.c_str() );

    }
protected:
    int mx,my;
    Logys log;
};



class Menu {
public:
     //////////////////////////////////////////////////////
    //            ПРИ ИНИЦИИЛИЗАЦИИ МЕНЮ
	//УКАЗАТЬ АДРЕСА УКАЗАТЕЛЕЙ НА АДРЕСА МЕЙН РЕНДЕРА И НУЖНОГО ОКНА
    Menu();
    void setup(int ncodename, SDL_Window * window, SDL_Renderer * renderer, Model * modela, Menu_Handler * hand);
    void add_button(int x,int y,int w,int h,int dest);
    //
    //////////////////////////////////////////////////////
    //            ПРОВЕРКА СТАТУСОВ ВСЕХ КНОПОК ПРИНАДЛЕЖАЩИХ МЕНЮ
    void check_buttons();
    //
    //////////////////////////////////////////////////////
    //вернуть указатель на функции инпута и аутпута
    //дабы через него вызывать ее в нужных местах
    //void get_p_input(void * pointer);
    //void get_p_output(void * pointer);
    //////////////////////////////////////////////////////
    //            ОСНОВНЫЕ ПОТОКИ
    void inputs();
    void outputs();
    //            И ИНСТРУМЕНТЫ УПРАВЛЕНИЯ
    void connect_output(output out);
	void connect_input(input in);

    void run( );
    //menu_switch get_p_status() { return &m_status; }

    int get_name() { return m_status.dest; }
	bool is_on() { return m_status.active; }

    void switcha(bool active) { m_status.active = active; }

protected:
    SDL_Event e;
    int mx,my;
    cl_status m_status; //статичный вариант
    vector<Button> butt;//внутри динамичный переключатель статичного варианта

    output outs;
	input ins;
    SDL_Window * swindow;
    SDL_Renderer * srenderer;

    Menu_Handler * hand;
	Model * modela;
	//  STUFF
	//static auto * graf;  //инструмент отрисовки
};

#endif // CMENU_H_INCLUDED
