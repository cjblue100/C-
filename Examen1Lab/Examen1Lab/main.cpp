#include <iostream>
#include "polinomio.h"
#include <conio.h>
int main()
{
	polinomio a;
	polinomio b;

	a.ingresarTerminos();
	b.ingresarTerminos();
	
	std::cout << "Primer polinomio: " << a;
	std::cout << "\nSegundo polinomio: " << b;

	polinomio c;

	c = a + b;
	std::cout << "\nc = a + b resultado es: " << c;

	c = a - b;
	std::cout << "\nc = a - b resultado es: " << c;

	c = a * b;
	std::cout << "\nc = a * b resultado es: " << c;

	_getch();

}