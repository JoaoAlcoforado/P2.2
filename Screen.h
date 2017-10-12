#ifndef SCREEN_H_INCLUDED
#define SCREEN_H_INCLUDED

#include <iostream>
#include <vector>

using namespace std;

class Screen
{
private:
    int nlin, ncol;
    char brush;
    vector< vector<char> > mat;
public:

    Screen(int nlin=0, int ncol=0);

    void setPixel(int x, int y);

    void clear();

    void setBrush(char brush);

    friend ostream& operator<<(ostream &os, Screen &t);
};

#endif // SCREEN_H_INCLUDED
