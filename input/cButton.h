#ifndef CBUTTON_H_INCLUDED
#define CBUTTON_H_INCLUDED
#include <iostream>
#include <stdio.h>
#include <vector>
#include <thread>
#include <sstream>
#include <string>
using namespace std;

#include "../gGlobal.h"
//#include "../cMenu_Handler.h"
#include "icButton.h"
class Menu;
class Model;
class Menu_Handler;

class Button {
public:
    Button() {}
    void crt(int dest, int x, int y, int w, int h, Model * modela) { this->x = x; this->y = y; this->w = w; this->h = h; this->place = place; status.dest = dest; this->modela = modela; }
    void set_status(cl_status status) { this->status = status; }
    button_cumback check_clck( int mx, int my );
    void set_place_adres( Menu * p_place ) { this->p_place = p_place; }
protected:
    int x,y;
    int w,h;
    cl_status status;
    int place;
    Menu * p_place;
    Model * modela;
};


#endif // CBUTTON_H_INCLUDED
