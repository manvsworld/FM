#ifndef GSWITCHER_H_INCLUDED
#define GSWITCHER_H_INCLUDED

#include "cMenu_Handler.h"
#include "Model/mModel.h"
#include "bSwither.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <map>
#include <vector>
#include <thread>
#include <mutex>
#include <string>
using namespace std;
/*
int global_redirect(Menu_Handler * hand, int off,int on, Model * modela)
{
    if(on == MAIN || on == DAY) {
        switcher(hand);
    } else {
        button_exeptions(on,modela);

    }

}
*/

inline int global_redirect(Menu_Handler * hand, int off,int on, Model * modela)
{
    if(on == MAIN || on == DAY) {
        hand->run_menu( hand->seek_menu(off),false );
        hand->run_menu( hand->seek_menu(on),true );
    } else {
        //todo
       // button_exeptions(on,modela);

    }

}
#endif // GSWITCHER_H_INCLUDED
