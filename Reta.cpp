#include "Reta.h"
#include <cmath>
using namespace std;

Reta::Reta(float x0,float y0,float x1, float y1)
{
    this->x0 = x0;
    this->y0 = y0;
    this->x1 = x1;
    this->y1 = y1;
}
void Reta::draw(Screen &t)
{
    float step,xinc,yinc;
    float x,y;
    int deltax = abs(x1-x0);
    int deltay = abs(y1-y0);
    if(deltax >= deltay)
    {
        step = deltax;
    }
    else
        step = deltay;
    xinc = deltax/step;
    yinc = deltay/step;
    x = x0;
    y = y0;

    for(int i=0; i<step; i++)
    {
        t.setPixel(round(x),round(y));
        x+=xinc;
        y+=yinc;
    }

}
