#include <iostream>
#include "Char.h"
#include "Integer.h"
#include "String.h"
#include <conio.h>
using namespace std;
int ingre, chara=0,inte=0,stri=0;
char ingre2;
string ingre3;
object* type;
object* muestra[6];

void imprimir(object*);

int buscarEspa() {
	for (int i = 0;i < 6;i++) {
		if (muestra[i]== NULL )
			return i;
	}

	return -1;
}

int main() {
	int ele;
	do {
		cout << "1.Integral\n2.Char\n3.String \n 4.Salir\n\n";
		cout << "Ingrese eleccion: ";
		cin >> ele;



		switch (ele) {
		case 1:



			cout << "Escriba un integral: ";
			cin >> ingre;

			if (buscarEspa() == -1) {
				cout << "Arreglo lleno";
			}
			else
			{
				integer cos;
				cos.setInt(ingre);
				muestra[buscarEspa()] = new integer(ingre);

				
			}
			inte++;

			break;

		case 2:



			cout << "Escriba un Character: ";
			cin >> ingre;

			if (buscarEspa() == -1) {
				cout << "Arreglo lleno";
			}
			else
			{
				muestra[buscarEspa()] = new Char(ingre2);
				
			}
			chara++;
			break;

		case 3:



			cout << "Escriba un String: ";
			cin >> ingre;

			if (buscarEspa() == -1) {
				cout << "Arreglo lleno";
			}
			else
			{
				muestra[buscarEspa()] = new String(ingre3);
		
			}
			stri++;
			break;

		default:
			cout << "Ingrese una eleccion posible";
			break;
		}

		for (int i = 0; i < 4; i++)
		{
			imprimir(muestra[i]);
		}
	} while (ele != 4);
}

void imprimir(object* tipo)
{
	
		if (Tipo::Tinteger == tipo->getTipo())
		{

			integer* tr = (integer*)tipo;

			cout << "Int: " << tr->getInt();
			cout << "\nCantidad de integer: " << inte;
		}
		else if (Tipo::Tchar == tipo->getTipo())
		{
			Char* tr = (Char*)tipo;

			cout << "Char: " << tr->getChar();
			cout << "\nCantidad de char: " << chara;
		}
		else if (Tipo::Tstring == tipo->getTipo())
		{
			String* tr = (String*)tipo;

			cout << "String: " << tr->getString();

			cout << "\nCanidad de string: " << stri;
		}
	
	
}