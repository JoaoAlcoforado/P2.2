#include "Circulo.h"
#include <iostream>
#include <cmath>

using namespace std;

void Circulo::draw(Screen &t)
{
    if(raio == 0)
    {
        cout << "circulo com raio zero!!" << endl;
        return;
    }
    if(this->fillmode == 0)
    {
        float x,y,d;
        x = 0;
        y = raio;
        d = 1 - raio;
        pontosDaCirc(round(x),round(y),t);
        while(y > x)
        {
            if(d < 0)
            {
                d = d + 2*x + 3;
                x = x + 1;
            }
            else
            {
                d = d + 2*(x-y) + 5;
                x = x + 1;
                y = y - 1;
            }
            pontosDaCirc(round(x),round(y),t);
        }


    }

    else
    {
        float x,y,d;
        x = 0;
        y = raio;
        d = 1 - raio;
        pontosDaCirc(round(x),round(y),t);
        while(y > x)
        {
            if(d < 0)
            {
                d = d + 2*x + 3;
                x = x + 1;
            }
            else
            {
                d = d + 2*(x-y) + 5;
                x = x + 1;
                y = y - 1;
            }
            pontosDaCirc(round(x),round(y),t);
        }
        //cout<<"estou preenchido sqn"<<endl;
        // preencher a circunferencia

        float xs = xc - raio ;
        float ys = yc - raio;
        for(int i=0; i<2*raio; i++)
        {
            for(int j=0; j<2*raio; j++)
            {

                if(estaNaCirc(xs+i,ys+j)<0)
                    t.setPixel(xs+i,ys+j);
            }

        }

    }

}

void Circulo::pontosDaCirc(float x, float y,Screen &t)
{
    t.setPixel(x+xc,y+yc);
    t.setPixel(-x+xc,y+yc);
    t.setPixel(x+xc,-y+yc);
    t.setPixel(-x+xc,-y+yc);
    t.setPixel(y+xc,x+yc);
    t.setPixel(-y+xc,x+yc);
    t.setPixel(y+xc,-x+yc);
    t.setPixel(-y+xc,-x+yc);
}

float Circulo::estaNaCirc(float x,float y)
{
    return pow(x-xc,2)+pow(y-yc,2)-pow(raio,2);
}


Circulo::Circulo(float _xc,float _yc,float _raio,int _fillmode)
{
    xc = _xc;
    yc = _yc;
    raio = _raio;
    fillmode = _fillmode;
}
