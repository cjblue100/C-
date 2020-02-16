#include <iostream>
using std::cout;
using std::cin;
#include "Racional.h"

Racional simplificar(Racional num)
{
	while ((num.numerador % 2 == 0) && (num.denominador % 2 == 0))
	{
		num.numerador = num.numerador / 2;
		num.denominador = num.denominador / 2;
	}
	return num;
}

double decimal(Racional num)
{
	double deci;
	deci = num.numerador / num.denominador;
	return deci;
}

int main()
{
	Racional a(90, 40);
	Racional b(8, 4);
	Racional d(15, 3);

	Racional c;
	c = a + d;
	cout << "c: " << c;
	cout << "\n\nSimplificado : " << simplificar(c);
	cout << "\nDecimal: " << decimal(c);

	Racional d;
	d = a - b;
	cout << "\n\nd: " << d << "\nsimplificado: " << simplificar(d);
	cout << "\nDecimal: " << decimal(d);

	Racional e;
	e = a * b;
	cout << "\n\ne: " << e << "\nSimplificado: " << simplificar(e);
	cout << "\nDecimal: " << decimal(e);

	Racional f;
	f = a / d;
	cout << "\n\nf: " << f << "\nSimplificado: " << simplificar(f);
	cout << "\nf: " << decimal(f);



}