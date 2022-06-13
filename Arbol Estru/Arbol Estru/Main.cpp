#include <iostream>
#include"ArbolBinario.h"
#include <conio.h>;
using namespace std;
using std::string;


int main()
{

    ArbolBinario arbolito;
    arbolito.Agregar("4");
    arbolito.Agregar("2");
    arbolito.Agregar("1");
    arbolito.Agregar("3");
    arbolito.Agregar("8");
    arbolito.Agregar("6");
    
    arbolito.Agregar("5");
    arbolito.Agregar("7");
    arbolito.Agregar("9");
    arbolito.imprimir();

    _getch();
}