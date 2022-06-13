#include <iostream>
#include "numero.h"
#include <conio.h>
using std::cout;
using std::cin;
int main() 
{
	numero a(9,3);
	numero b(3,3);
	numero c;
	
	/*cout << "Ingrese valor de a: ";
	cin >> a;
	cout << "Valor de a: " << a;
	*/
	c = a + b;
	/*c = c + 2;*/
	cout << c;

	//cout << "c=  " << c<<"\n";//c=14
	//numero d;
	//d = c++;
	//cout << "c++ = " << c<<"\n";//c=15
	//numero e;
	//e = ++c;

	//cout << "++c = " << c<<"\n";//c=16

	

	_getch();
}