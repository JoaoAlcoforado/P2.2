#ifndef FIGURAGEOMETRICA_H_INCLUDED
#define FIGURAGEOMETRICA_H_INCLUDED

#include "Screen.h"

class FiguraGeometrica
{
public:
    FiguraGeometrica();
    virtual ~FiguraGeometrica();
    virtual void draw(Screen &t) = 0;

};

#endif // FIGURAGEOMETRICA_H_INCLUDED
