#ifndef MMODEL_H_INCLUDED
#define MMODEL_H_INCLUDED


#include <iostream>
#include <stdio.h>
#include <string>
#include <map>
#include <vector>
#include <thread>
#include <mutex>
#include <string>
using namespace std;
#include "../gGlobal.h"
#include "../Logs/cLog.h"
#include "cPodmenk.h"


//enum Status_P { HERE,KLIO,BRON };

class Kalendar {
public:
	Kalendar() {}
	void setup_for_podmen();
	int get_status(int d,int m,int y);
protected:
	data time;
	bool exist;
};

class Model {
public:
	Model() {ch_day.yr = 2019; ch_day.mn = 9; ch_day.dy = 24;}
	void setup_stuf(SDL_Renderer * rnd, SDL_Window * wnd) { this->wnd=wnd; this->rnd=rnd; }
	void get_rnd_wnd(SDL_Renderer * rnd, SDL_Window * wnd) { rnd = this->rnd; wnd = this->wnd; }

	void add_car(const char* vin, const char* name, int num);
	int get_ch_day() { return ch_day.dy; }
	int get_ch_month() { return ch_day.mn; }
	int get_ch_year() { return ch_day.yr; }
	void set_ch_day(int d, int m, int y) { simple_data buf = {d,m,y}; ch_day = buf; }

	string get_vin(int id) { return car[id].get_vin(); }
	string get_name(int id){ return car[id].get_model(); }
	int get_gosnum(int id) { return car[id].get_gosnum(); }
	int get_status(int d, int m, int y) { }

protected:
	vector<Podmenka> car;
	vector<Kalendar> kalen;
	simple_data ch_day;

	SDL_Renderer * rnd;
	SDL_Window * wnd;

};


#endif // MMODEL_H_INCLUDED
