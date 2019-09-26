#include "cMenu_Handler.h"

void Menu_Handler::setup(SDL_Renderer * renderer, SDL_Window * window, Model * modela)
{
	wnd = window; rnd = renderer; this->modela = modela;
}

int Menu_Handler::seek_menu(int name)
{
try {//
    for(int i=0;i<menus.size();i++)
    {
        if(name == menus[i].get_name()) return i;
    }
    throw "EROR: menu with this name dosnt exist\n";
}//
    catch(const char* eror) { printf(eror); }
}

void Menu_Handler::check_runs()
{
try {//
	for(int i=0;i<menus.size();i++)//if( menus[i].is_on() )
	{
	     menus[i].run();
		cout << "menu # is active = " << "| " << i << " | " <<  menus[i].is_on() << endl;
	}
	throw "EROR: all menus closed\n";
}//
	catch(const char* eror) { printf(eror); }
}
