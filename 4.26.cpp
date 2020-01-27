#include <iostream>

using namespace std;


int main()
{
	int numero, a, b, c, d, e;

	cout << "Escribe un numero entero con 5 digitos: ";
	cin >> numero;

	
		if (numero <= 99999 && numero>10000) {
			a = numero / 10000;
			b = (numero % 10000) / 1000;
			c = (numero % 10000) % 1000 / 100;
			d = ((numero % 10000) % 1000) % 100 / 10;
			e = (((numero % 10000) % 1000) % 100) % 10;

			if (a == e && b == d) {
				cout << "\nEse numero es un palindromo!!!\n";
			}
			else if (a != e || b != d)
				cout << "Ese numero NO es un palindromo!!!\n";

		}
		else
			cout << "\nTiene que ser un numero de 5 digitosn\n";
	

	
	
}