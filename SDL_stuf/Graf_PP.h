#ifndef GRAF_PP_H_INCLUDED
#define GRAF_PP_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include <vector>
#include <thread>
#include <sstream>
#include <string>
#include "SDL.h"
#include "cGraf.h"
#include "customSDL.h"
using namespace std;

#include "../Logs/cLog.h"
string ccint(int x1,int y1, int x2, int y2)
{
    string all_data;
    string s[4];
    s[0] = std::to_string(x1);
    s[1] = std::to_string(y1);
    s[2] = std::to_string(x2);
    s[3] = std::to_string(y2);
    all_data = "x1 : " + s[0] +"| y1  : " + s[1] + "| x2 :" + s[2] + "| y2 : " + s[3] + "\n";
    return all_data;
}
string peremen(const char* text,int x)
{
    string buf;
    buf = to_string(x);

    string rez = text + buf + "\n";
}
class Graf_PP {
public:
	Graf_PP() {}
	void setup(SDL_Window * window, SDL_Renderer * renda);
	void set_draw_color(SDL_Color clr) { d_color = clr; }

	void test_line(cords p1, cords p2) { graf.Line(p1,p2, Red); }

	//	LIST
	void lista( int x,int y, int stolb,int lines, int pix_w, int pix_h);
	void vertical_lines(int x,int y, int stolb,int lines, int pix_w, int pix_h);
	void horizontal_lines(int x,int y, int stolb,int lines, int pix_w, int pix_h);

	void pad_mat(int ampad_x,int ampad_y,int x,int y, int w,int h,int pix_ot_w, int pix_ot_h) {}
protected:
	View graf;
	customSDL cast;
	SDL_Color d_color;

	Logys log;
};
///////	SETUPS
void Graf_PP::setup( SDL_Window * window, SDL_Renderer * renda )
{
	cast.setup(renda);
	graf.setup(renda,window);
}
///////	LIST
void Graf_PP::lista( int x,int y, int stolb,int lines, int pix_w, int pix_h )
{
    log.open("Logs\\log_line_coords.txt");
    log.write("|||  √Œ–»«ŒÕ“¿À‹Õ€≈ À»Õ»»  |||\n");
	int current_pos_x = x;
	int current_pos_y = y;
	for(int line=0;line<lines;line++)
	{
		cords p1,p2;
		p1.x = current_pos_x;
		p1.y = current_pos_y;
		p2.x = stolb * pix_w;
		p2.y = current_pos_y;
		//
		string rez = ccint(p1.x,p1.y,p2.x,p2.y);
		log.write( rez.c_str() );
		rez = peremen("line# : ",line);
		log.write( rez.c_str() );
		//
		graf.Line(p1,p2,d_color);
		current_pos_y = current_pos_y + pix_h;
	}
	log.write("|||  ¬≈–“» ¿À‹Õ€≈ À»Õ»»  |||\n");
	 current_pos_x = x;
	 current_pos_y = y;
	for(int stb=0;stb<stolb;stb++)
	{
		cords p1,p2;
		p1.x = current_pos_x;
		p1.y = current_pos_y;
		p2.x = current_pos_x;
		p2.y = lines * pix_h;
		//
		string rez = ccint(p1.x,p1.y,p2.x,p2.y);
		log.write( rez.c_str() );
		rez = peremen("stolb# : ",stb);
		log.write( rez.c_str() );
		//
		graf.Line(p1,p2,d_color);
		current_pos_x = current_pos_x + pix_w;
	}
}


////////

/*void Graf_PP::pad_mat(int ampad_x,int ampad_y,int x,int y, int w,int h,int pix_ot_w, int pix_ot_h)
{
	cords p1,p2;
	int current_pos_x = x;
	int current_pos_y = y;
	for(int verti=0;verti<ampad_x;verti++)
	{
		for(int horiz=0;horiz<ampad_y;horiz++)
		{
			p1.x = current_pos_x;
			p1.y = current_pos_y;
			graf.baseSquare();
			current_pos_x = current_pos_x + w + pix_ot_w;
		}
		current_pos_x = x;
		current_pos_y = current_pos_y + h + pix_ot_h;
	}
}*/

#endif // GRAF_PP_H_INCLUDED
