#include "listaDoble.h"
#include <conio.h>

int main()
{
	listaDoble val;
	val.agregarElemento(4);
	val.agregarElemento(2);
	val.agregarElemento(1);
	val.agregarElemento(3);

	val.ordenar();
	val.eliminarElemento(2);

	

	val.imprimir();

	_getch();
}