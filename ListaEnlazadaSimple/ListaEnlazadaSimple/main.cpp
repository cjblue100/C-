#include "listaEnlazadaSimple.h"
#include <conio.h>

int main()
{
	listaEnlazada lista;

	lista.agregarElemento(4);
	lista.agregarElemento(2);
	lista.agregarElemento(8);
	lista.agregarElemento(5);

	lista.eliminarElemento(5);
	
	

	lista.imprimir();


	_getch();

}