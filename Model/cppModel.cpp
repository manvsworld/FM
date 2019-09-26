#include "mModel.h"


int Kalendar::get_status(int d,int m,int y)
{
	for(int i=0;i<5;i++)
	if( y == (2019+i) ) return time.years[i].mon[m].days[d].status;
}

void Kalendar::setup_for_podmen()
{
	const int YRS = 5;
	const int MNT = 12;
	const int DYS = 31;
	for(int y=0;y<YRS;y++)
	{
		time.years[y].num = 2019 + y;
		for(int m=0;m<MNT;m++)
		{
			if(m==0) time.years[y].mon[m].name = "JANUARY";
			if(m==1) time.years[y].mon[m].name = "FEBRARY";
			if(m==2) time.years[y].mon[m].name = "MARCH";
			if(m==3) time.years[y].mon[m].name = "APRYL";
			if(m==4) time.years[y].mon[m].name = "MAY";
			if(m==5) time.years[y].mon[m].name = "JUNE";
			if(m==6) time.years[y].mon[m].name = "JULY";
			if(m==7) time.years[y].mon[m].name = "AUGUST";
			if(m==8) time.years[y].mon[m].name = "SEPTEMBER";
			if(m==9) time.years[y].mon[m].name = "OCTOBER";
			if(m==10) time.years[y].mon[m].name ="NOVEMBER";
			if(m==11) time.years[y].mon[m].name ="DECEMBER";
				for(int d=0;d<DYS;d++)
				{
					time.years[y].mon[m].days[d].num = d;
					time.years[y].mon[m].days[d].status = HERE;
				}
		}
	}
}




void Model::add_car(const char* vin, const char* name, int num)
{
	Podmenka new_;
	car.push_back(new_);
	car[car.size()-1].setup(vin,name,num);
	Kalendar newk; kalen.push_back(newk);
	kalen[kalen.size()-1].setup_for_podmen();
}
