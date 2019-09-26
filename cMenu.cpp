
#include "cMenu.h"
#include "gGlobal.h"
#include "gSwitcher.h"
Menu::Menu()
{
    m_status.active = false;
	outs.m_out = nullptr;
	ins.m_in = nullptr;
	//modela.setup();
}

void Menu::setup(int ncodename, SDL_Window * window, SDL_Renderer * renderer, Model * modela,Menu_Handler * hand)
{
    butt.reserve(1); //allways exit but
    m_status.dest = ncodename;
    swindow = window; srenderer = renderer;
    this->modela = modela;
    this->hand=hand;
}

void Menu::add_button(int x,int y,int w,int h,int dest)
{
    Button news;
    butt.push_back(news);
    butt[butt.size()-1].crt(dest,x,y,w,h,modela);
}



void Menu::run()
{

        thread inp(Menu::inputs, this);
        thread outp(Menu::outputs,this);
        inp.detach();
        outp.detach();
}

void Menu::inputs()
{
    while(SDL_WaitEvent(&e) != 0)
    {
        if(e.type == SDL_MOUSEBUTTONDOWN)
        {
            Click mouse;
            mouse.born(&mx,&my);
            for(int i=0;i<butt.size();i++)
			{
				button_cumback button = butt[i].check_clck( mx,my );
				if(button.pressed) global_redirect(hand,m_status.dest,button.direct,modela);
			}
        }
        try {//
            if(ins.m_in == nullptr) throw "ERROR: input not connected\n";
            ins.m_in(modela); //ссылка на функцию ввода
        }//
        catch(const char * eror) { printf(eror); }
    }
}

void Menu::outputs()
{
    /*
    for(int i=0;i<butt.size();i++)	//wtf1
    {
        cords p[2];
        p[0] = butt[i].GetXY();
        p[1].x = p[0].x + butt[i].GetW();
        p[1].y = p[0].y + butt[i].GetH();
        //graf->baseSquare(p[0],p[1]);
    }								//wtf1[jhj
    */
    try {//
        if(outs.m_out == nullptr) throw "ERROR: output not connected\n";
    outs.m_out(modela);//ссылка на фкнцию отрисовки
    }//
    catch(const char * eror) { printf(eror); }
}

void Menu::connect_output(output outs) { this->outs=outs; }
void Menu::connect_input(input ins) { this->ins=ins; }

