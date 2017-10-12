#include "Retangulo.h"

Retangulo::Retangulo(int x,int y,int alt,int larg)
{
    this->x = x;
    this->y = y;
    this->alt = alt;
    this->larg = larg;
}

void Retangulo::draw(Screen &t)
{
    int i;
    for(i=x; i<=larg+x-1; i++)
    {
        t.setPixel(y,i);
        t.setPixel(y+alt,i);
    }
    for(i=y+1; i<alt+y; i++)
    {
        t.setPixel(i,x);
        t.setPixel(i,x+larg-1);
    }
}
