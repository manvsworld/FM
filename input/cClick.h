#ifndef CCLICK_H_INCLUDED
#define CCLICK_H_INCLUDED
#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <string>
#include <sstream>
using namespace std;
#include "../Logs/cLog.h"
#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_image.h"
class Click {
public:
    Click() {}
    void born(int * mx, int * my);
protected:
    int mx,my;
    Logys log;
};

void Click::born(int * mx, int * my)
{
    SDL_GetMouseState(mx,my);
    this->mx = *mx; this->my = *my;
    log.open("Logs\\log_clicks.txt");
    string logss = "| mx = " + std::to_string(this->mx) + " | my = " + std::to_string(this->my) + " |" + "\n";
    log.write( logss.c_str() );

}

#endif // CCLICK_H_INCLUDED
