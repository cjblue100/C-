#include "Nary.h"
#include <conio.h>
int main()
{
	Nary arbol(10);
	arbol.agregar(5,10);
	arbol.agregar(6, 10);
	arbol.agregar(2, 5);
	arbol.agregar(4, 5);
	arbol.agregar(1, 2);
	arbol.agregar(7, 4);
	arbol.agregar(13, 7);
	arbol.agregar(15, 13);



	_getch();
}