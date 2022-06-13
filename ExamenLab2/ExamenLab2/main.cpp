#include "listaEmpleados.h"
#include <conio.h>
#include <iostream>

int main()
{
	lista a;
	
	a.agregarlista(12, "Paul", 12);
	a.agregarlista(14, "Carlos", 500);
	a.agregarlista(13, "Daniel", 800);
	a.agregarlista(15, "Karol", 10000);
	a.agregarlista(16, "Muriel", 2000);

	a.eliminar(12);
	a.desactivarEmpleado(16);
	a.imprimirLista();

	

	a.guardarEmpleado();

	_getch();
}