#include "Screen.h"
#include <iostream>

Screen::Screen(int nlin,int ncol)
{
    this->ncol = ncol;
    this->nlin = nlin;
    mat.resize(nlin);
    for ( int i = 0 ; i < nlin ; i++ )
        mat[i].resize(ncol);
    for(int i=0; i<nlin; i++)
    {
        for(int j=0; j<ncol; j++)
        {
            mat[i][j] = ' ';
        }
    }
}

void Screen::clear()
{
    for(int i=0; i<nlin; i++)
    {
        for(int j=0; j<ncol; j++)
        {
            this->mat[i][j] = ' ';
        }
    }
}

void Screen::setBrush(char brush)
{
    this->brush = brush;
}

void Screen::setPixel(int x, int y)
{
    mat[y][x] = brush;
}

ostream& operator<<(ostream &os, Screen &t)
{
    os<<"|";
    for(int i=0; i<2*t.ncol-1; i++)
    {
        os <<"=";
    }
    os <<"|"<<endl;

    for(int i=0; i<t.nlin; i++)
    {
        for(int j=0; j<t.ncol; j++)
        {

            os << " " << t.mat[i][j];

        }
        os << endl;
    }

    os <<"|";
    for(int i=0; i<2*t.ncol-1; i++)
    {
        os <<"=";
    }
    os <<"|"<<endl;
    return os;
}
