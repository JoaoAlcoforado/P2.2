#ifndef RETA_H_INCLUDED
#define RETA_H_INCLUDED

#include "FiguraGeometrica.h"

class Reta : public FiguraGeometrica
{
public:
    Reta(float x0=0,float y0=0,float x1=0, float y1=0);
    void draw(Screen &t);
private:
    int x0,x1,y0,y1;
};

#endif // RETA_H_INCLUDED
