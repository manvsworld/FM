#include "cButton.h"
#include "../cMenu_Handler.h"
#include "../gGlobal.h"

button_cumback Button::check_clck(int mx, int my)
{
    button_cumback result = { false,status.dest };
    if( mx > x && mx < (x+w) && my > y && my < (y+h) ) { result.pressed = true; return result; }//todo
    else return result;
}
