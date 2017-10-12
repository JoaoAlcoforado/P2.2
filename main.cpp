#include <iostream>
#include "Screen.h"
#include <fstream>
#include <stdlib.h>
#include "Reta.h"
#include <string>
#include <string.h>
#include "Retangulo.h"
#include "Circulo.h"

using namespace std;

Screen& loadScreen(istream& is)
{
    string s;
    Screen *t;

    int nl,nc;
    char b;
    is >> s;

    if(strcmp(s.c_str(),"dim")==0)
    {
        is >> nl;
        is >> nc;
        t = new Screen(nl, nc);

        if(t==NULL)
        {
            cout << "erro ao alocar screen" <<endl;
            exit(1);
        }
        else
        {
            cout << "screen alocada!" <<endl;
        }


    }
    else
    {
        cerr << "Erro ao inicializar screen, formato do arquivo nao esta correto" << endl;
        exit(1);
    }
    is >> s;

    if(strcmp(s.c_str(), "brush")==0)
    {
        is >> b;
        t->setBrush(b);
    }
    else
    {
        t->setBrush('*');
    }

    return *t;

}

int drawFigFromStream(istream& is,Screen& t)
{
    FiguraGeometrica *pfig;
    string s;
    int n1,n2,n3,n4;
    if(!is.good())
        cout<<"O arquivo nao esta bom para leitura, ou ja chegou no seu EOF"<<endl;
    while(is.good())
    {

        is >> s;

        if(strcmp(s.c_str(),"line")==0)
        {
            is >> n1 >> n2 >> n3 >> n4;

            pfig = new Reta(n1,n2,n3,n4);
            pfig->draw(t);
            delete pfig;
        }
        if(strcmp(s.c_str(),"rectangle")==0)
        {
            is >> n1 >> n2 >> n3 >> n4;

            pfig = new Retangulo(n1,n2,n3,n4);
            pfig->draw(t);
            delete pfig;
        }
        if(strcmp(s.c_str(),"circle")==0)
        {
            is >> n1 >> n2 >> n3 >> n4;

            pfig = new Circulo(n1,n2,n3,n4);
            pfig->draw(t);
            delete pfig;
        }

    }
    return 0;

}

int main()
{
    ifstream infile;

    ofstream outfile;

    string pathIn = "figuras.txt",
           pathOut = ".\\saidascreen.txt";

    /*
        Formato do arquivo:
        dim nlin ncol  -  define o tamanho do screen
        brush 'char'   -  define o brush a ser usado
        line 5 5 10 8   -- a partir daqui ,as figuras
        rectangle 5 6 10 20
        circle 10 10 5 1
        circle 10 10 5 0
    */
    Screen myscr;
    //=========teste de abertura do arquivo===========
    if(infile.is_open())
    {
        cout << " arquivo aberto com sucesso!" << endl;
    }
    else
    {
        cerr << "erro ao abrir arquivo" << endl;
        exit(1);
    }
    myscr = loadScreen(infile);// carregando a screen
    //myscr.clear();
    //===============================
    drawFigFromStream(infile, myscr);// TODO, desenha todas as figuras listadas no arquivo, na screen passada


    outfile << myscr;
    cout << myscr;

    return 0;
}
