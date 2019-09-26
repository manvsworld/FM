#ifndef CPODMENK_H_INCLUDED
#define CPODMENK_H_INCLUDED
///////////////////////////////////////////////////////////////////////
//struct day { string name; int num; };
//struct month { string name; day days[31]; };
//struct year { month mon[12]; };
//struct fio {string fname,lname,oname;};
//////////////////////////////////////////////////////////////////////
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

class Podmenka {
public:
	Podmenka() {}
	Podmenka(Podmenka * new_car);
	/////////////
	void setup(const char * vin, const char * model, int gosnum)
	{
	this->gosnum = gosnum;
	this->vin = vin;
	this->model = model;
	//here = true;
    }
    /////////////
	void car_out();
	void car_in();

	//void set_here(bool here) { this->here=here; }
	//void set_arend(int arend) { this->arend=arend; }
	void set_gosnum(int gosnum) { this->gosnum=gosnum; }
	void set_vin(const char * vin) { this->vin = vin; }
	void set_model(const char * model) { this->model = model; }

	//int get_ammount_days() { return arend; }
	//bool am_here() { return here; }
	string get_vin() { return vin; }
	int get_gosnum() { return gosnum; }
	string get_model() { return model; }
protected:
	//bool here;

	int gosnum;
	string vin;
	string model;
};

#endif // CPODMENK_H_INCLUDED
