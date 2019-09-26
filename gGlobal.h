#ifndef GGLOBAL_H_INCLUDED
#define GGLOBAL_H_INCLUDED
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
const int SCREEN_H = 800;
const int SCREEN_W = 1200;
// SDL_Renderer * renderer=nullptr;
// SDL_Window * window=nullptr;

enum Status_P { HERE,CLIO,BRON };
enum Menus {MAIN,DAY};

struct day { int clio_carnum; int num; int status; };
struct month { string name; day days[31]; };
struct year { month mon[12]; int num;};
struct data { year years[5];};
struct simple_data { int yr,mn,dy; };
struct fio {string fname,lname,oname;};
struct cords { int x,y; };

class Model;
struct cl_status { bool active; int dest; cords crd; };
struct output { int place; void (*m_out)(Model * modela); };
struct input { int place; int (*m_in)(Model * modela); };

inline void inccords(int x, int y, cords * crd) { crd->x = x; crd->y = y; }

struct button_cumback {
    bool pressed;
    int direct;

};

#endif // GGLOBAL_H_INCLUDED
