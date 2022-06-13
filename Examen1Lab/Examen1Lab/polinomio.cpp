#include "polinomio.h"

using namespace std;

polinomio::polinomio()
{
	for (int x = 0;x < 30;x++)
	{
		coeficientes[x] = 0;
		exponentes[x] = 0;
	}

	cantidad = 0;
}

polinomio::~polinomio(){}

void polinomio::ingresarTerminos()
{
	cout << "Ingrese cantidad terminos polinomio: ";
	cin >> cantidad;

	for (int x = 0;x < cantidad;x++)
	{
		cout << "\nIngrese coeficiente: ";
		cin >> coeficientes[x];
		cout << "\nIngrese exponente: ";
		cin >> exponentes[x];
	}
}

void polinomio::ordenarTerminos()
{
	int temp, temp2;
	for (int x = 0;x < cantidad;x++)
	{
		for (int y = x+1;y < cantidad;y++)
		{
			if (exponentes[x] < exponentes[y])
			{
				temp = exponentes[x];
				exponentes[x] = exponentes[y];
				exponentes[y] = temp;
				
				temp2 = coeficientes[x];
				coeficientes[x] = coeficientes[y];
				coeficientes[y] = temp2;

			}
		}
	}
}


polinomio& operator+(const polinomio& a, const polinomio& b)
{
	polinomio suma;
	polinomio resta;
	polinomio temp1 = a;
	polinomio temp2 = b;
	int contx=0,conty=0;
	temp1.ordenarTerminos();
	temp2.ordenarTerminos();
	for (int x = 0;x < 30;x++)
	{
		
		for (int y = 0;y < 30;y++) {
			if (temp1.exponentes[x] == temp2.exponentes[y])
			{
				suma.coeficientes[y] = temp1.coeficientes[x] + temp2.coeficientes[y];
				suma.exponentes[y] = temp1.exponentes[x];
				
			}


		}


		
	}

	
	return suma;
}

polinomio& operator-(const polinomio& a, const polinomio& b)
{
	
	polinomio resta;
	polinomio temp1 = a;
	polinomio temp2 = b;
	temp1.ordenarTerminos();
	temp2.ordenarTerminos();
	for (int x = 0;x < 30;x++)

	{
		for (int y = 0;y < 30;y++) {
			if (temp1.exponentes[x] == temp2.exponentes[y])
			{
				resta.coeficientes[y] = temp1.coeficientes[x] - temp2.coeficientes[y];
				resta.exponentes[y] = temp1.exponentes[x];
			}


		}
		
	}

	return resta;
}

polinomio& operator*(const polinomio& a, const polinomio& b)
{
	polinomio multi;
	polinomio temp1 = a;
	polinomio temp2 = b;
	temp1.ordenarTerminos();
	temp2.ordenarTerminos();
	for (int x = 0;x < 30;x++)
	{
		
			for (int y = 0;y < 30;y++) {
				if (temp1.coeficientes[x] != 0 && temp2.coeficientes[x] != 0 && temp2.coeficientes[y]!=0) {
					multi.coeficientes[y] = temp1.coeficientes[x] * temp2.coeficientes[y];
					multi.exponentes[y] = temp1.exponentes[x] + temp2.exponentes[y];
				}
			}
		
	}
	
	return multi;
}


std::ostream& operator<<(std::ostream& out, const polinomio& tmp) {
	polinomio a = tmp;
	a.ordenarTerminos();
	for (int x = 0;x < 30;x++)
	{
		
		if (a.coeficientes[x] != 0 && a.exponentes[x] != 0) {
			if (x > 0 && x < 30){
				out << "+";
				}

			out  << a.coeficientes[x] << "x^" << a.exponentes[x];

		}

	}
	return out;
}