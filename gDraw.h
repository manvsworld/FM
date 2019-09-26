#ifndef GDRAW_H_INCLUDED
#define GDRAW_H_INCLUDED

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
#include "SDL_stuf/cGraf.h"
#include "SDL_stuf/customSDL.h"
#include "gGlobal.h"
#include "Model/mModel.h"

void d_main(Model * modela)
{
	//	LINES
	const int HORIZL_AM = 10;
	const int VERTL_AM = 31;

        SDL_Renderer * renderer=nullptr;
    SDL_Window * window=nullptr;

	modela->get_rnd_wnd(renderer,window);
	customSDL cast;
	View graf;
	cast.setup(renderer);
	graf.setup(renderer,window);

	cords p1 = { 0,300 };
	cords p2 = { 1200,300 };
	for(int i=0;i<HORIZL_AM;i++)
	{
		graf.Line(p1,p2,Black);
		p1.y = p1.y + 50;
		p2.y = p2.y + 50;
	}

	inccords(180,300,&p1); //== cords p1 = {180,300};
	inccords(180,800,&p2);
	graf.Line(p1,p2,Black);

	p1.x = p1.x + 180;
	p2.x = p2.x + 180;
	graf.Line(p1,p2,Black);

	p1.x = p1.x + 120;
	p2.x = p2.x + 120;
	graf.Line(p1,p2,Black);

	for(int i=0;i<VERTL_AM;i++)
	{
		p1.x = p1.x + 23;
		p2.x = p2.x + 23;
		graf.Line(p1,p2,Black);
	}

	//	BUTON SQUARES
	inccords(25,240,&p1);
	inccords(125,290,&p2);
	graf.baseSquare(p1,p2,Black);
	cast.DrawText("<<<",(p1.x+10),(p1.y+10),90,40,Black,30);

	p1.x = p1.x + 110;
	p2.x = p2.x + 110;
	graf.baseSquare(p1,p2,Black);
	cast.DrawText("<<",(p1.x+10),(p1.y+10),90,40,Black,30);

	p1.x = p1.x + 110;
	p2.x = p2.x + 110;
	graf.baseSquare(p1,p2,Black);
	cast.DrawText("<",(p1.x+10),(p1.y+10),90,40,Black,30);

	p1.x = p1.x + 110;
	p2.x = p2.x + 110;
	graf.baseSquare(p1,p2,Black);
	cast.DrawText(">",(p1.x+10),(p1.y+10),90,40,Black,30);

	p1.x = p1.x + 110;
	p2.x = p2.x + 110;
	graf.baseSquare(p1,p2,Black);
	cast.DrawText(">>",(p1.x+10),(p1.y+10),90,40,Black,30);

	p1.x = p1.x + 110;
	p2.x = p2.x + 110;
	graf.baseSquare(p1,p2,Black);
	cast.DrawText(">>>",(p1.x+10),(p1.y+10),90,40,Black,30);
	//	TEXT
	cast.DrawPeremen("",modela->get_ch_day(),25,25,20,20,Black,26);
	cast.DrawPeremen(".",modela->get_ch_month(),35,25,20,20,Black,26);
	cast.DrawPeremen(".",modela->get_ch_year(),45,25,20,20,Black,26);
	//

	//	TABL TEXT
	// 	ШАПКА
	cast.DrawText("VIN",20,320,170,40,Black,30);
	cast.DrawText("MODEL",200,320,170,40,Black,30);
	cast.DrawText("GOS#",380,320,170,40,Black,30);
	inccords(500,320,&p1);
	for(int i=0;i<VERTL_AM;i++)
	{
		cast.DrawPeremen("",(i+1),p1.x,p1.y,20,20,Black,20);
	}
	//	ALL VINS
	inccords(20,370,&p1);
	for(int i=0;i<(HORIZL_AM-1);i++)
	{
		string vin_buf = modela->get_vin(i);
		cast.DrawText(vin_buf.c_str(),p1.x,p1.y,170,40,Black,20);
		p1.y = p1.y + 50;
	}
	//	ALL MODEL NAMES
	inccords(200,370,&p1);
	for(int i=0;i<(HORIZL_AM-1);i++)
	{
		string name_buf = modela->get_name(i);
		cast.DrawText(name_buf.c_str(),p1.x,p1.y,170,40,Black,20);
		p1.y = p1.y + 50;
	}
	//	ALL GOSNUMS
	inccords(380,370,&p1);
	for(int i=0;i<(HORIZL_AM-1);i++)
	{
		int num_buf = modela->get_gosnum(i);
		cast.DrawPeremen("",num_buf,p1.x,p1.y,110,40,Black,20);
		p1.y = p1.y + 50;
	}
	//	ALL DAY STATUS(COLORS)
	inccords(480,350,&p1);
	inccords(503,400,&p2);
	for(int i=0;i<(HORIZL_AM-1);i++)
	{
		for(int d=0;d<VERTL_AM;d++)
		{
			if(modela->get_status( modela->get_ch_day(), modela->get_ch_month(),modela->get_ch_year() ) == CLIO )
			{ graf.fillSquare(p1,p2,Green); }
			else if(modela->get_status( modela->get_ch_day(), modela->get_ch_month(),modela->get_ch_year() ) == BRON )
			{ graf.fillSquare(p1,p2,Red); }
			p1.x = p1.x + 23;
			p2.x = p2.x + 23;
		}
		p1.y = p1.y + 50;
		p2.y = p2.y + 50;
	}

}
#endif // GDRAW_H_INCLUDED
