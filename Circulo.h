#ifndef CIRCULO_H_INCLUDED
#define CIRCULO_H_INCLUDED

#include "FiguraGeometrica.h"

class Circulo: public FiguraGeometrica
{
public:
    Circulo(float _xc=0,float _yc=0,float _raio=0,int _fillmode=0);

    void draw(Screen &t);
//        friend double estaNoCirc(float x,float y);
    void pontosDaCirc(float x,float y,Screen &t);
    float estaNaCirc(float x,float y);

private:
    int raio,xc,yc,fillmode;
};

#endif // CIRCULO_H_INCLUDED
