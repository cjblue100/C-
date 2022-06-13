// Clase1.ED.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "persona.h"
#include <iostream>
#include "Acumulador.h"
#include "MiLista.h"
#include "ListaDoble.h"
#include "MyStack.h"
#include <conio.h>
#include "myQ.h"
using std::string;
using std::cout;
using std::endl;

template<class T>
T max(T const& t1, T const& t2) {
	return t1 < t2 ? t2 : t1;
}

int main()
{
	//int valor1 = 1;
	//int valor2 = 2;
	//cout << "mayor de 2 y 1 es " << max(valor1, valor2) << endl;
	//double dValor1 = 1.0;
	//double dValor2 = 2.0;
	//cout << "mayor de 2 y 1 es " << max(dValor1, dValor2) << endl;

	//Person persona1("Selvin", "Rodriguez", 50);
	//Person persona2("Gabriela", "Diaz", 60);

	//cout << "El mayor entre " << persona1.GetNombre()
	//	<< " y " << persona2.GetNombre() << " es " 
	//	<< max(persona1, persona2).GetNombre() << endl;

	//
	//Acumulador<int> numeros(10);
	//cout << "valor inicial: " << numeros.GetTotal() << endl;
	//numeros += 9;
	//numeros += 9;
	//cout << "valor despues de sumar 18: " << numeros.GetTotal() << endl;

	//Acumulador<string> cadena("");
	//cadena += "Hola ";
	//cadena += "Mundo";

	//cout << "Valor de variable cadena: " << cadena.GetTotal() << endl;

	//Acumulador<Person> personas(0);
	//personas += persona1;

	//cout << "Valor despues de sumar persona1: " << personas.GetTotal() << endl;
	////personas += persona2;

	//personas += persona2;

	//cout << "Valor despues de sumar persona2: " << personas.GetTotal() << endl;
	////personas += persona2;

	//MiLista<string> listaAlumnos;
	//listaAlumnos.Add("Selvin");
	//listaAlumnos.Add("Gabriela");
	//listaAlumnos.Add("Delia");
	//listaAlumnos.Add("Bilander");

	//Nodo<string>* cursor = listaAlumnos.FirstOrDefault();

	//while (cursor != nullptr) {
	//	cout << "Nombre de alumno: " << cursor->GetValor() << endl;
	//	cursor = cursor->GetSiguiente();
	//}

	//listaAlumnos.RemoveLast();
	//cout << "-------------------" << endl;

	//cursor = listaAlumnos.FirstOrDefault();

	//while (cursor != nullptr) {
	//	cout << "Nombre de alumno: " << cursor->GetValor() << endl;
	//	cursor = cursor->GetSiguiente();
	//}

	//cout << "-------------------" << endl;

	///*
	//listaAlumnos.RemoveFirst();
	//listaAlumnos.RemoveFirst();

	//cursor = listaAlumnos.FirstOrDefault();

	//while (cursor != nullptr) {
	//	cout << "Nombre de alumno: " << cursor->GetValor() << endl;
	//	cursor = cursor->GetSiguiente();
	//}

	//cout << "-------------------" << endl;*/

	//listaAlumnos.Remove("Delia");

	//cursor = listaAlumnos.FirstOrDefault();

	//while (cursor != nullptr) {
	//	cout << "Nombre de alumno: " << cursor->GetValor() << endl;
	//	cursor = cursor->GetSiguiente();
	//}

	//MiListaDoble<string> listaDobleAlumnos;
	//listaDobleAlumnos.Add("Selvin");
	//listaDobleAlumnos.Add("Gabriela");
	//listaDobleAlumnos.Add("Delia");
	//listaDobleAlumnos.Add("Bilander");

	//NodoDoble<string>* _cursor = listaDobleAlumnos.FirstOrDefault();

	//while (_cursor != nullptr) {
	//	cout << "Nombre de alumno: " << _cursor->GetValor() << endl;
	//	_cursor = _cursor->GetSiguiente();
	//}

	/*MyStack<string> miPila;
	miPila.Push("Selvin");
	miPila.Push("Gabriela");
	miPila.Push("Delia");
	miPila.Push("Bilander");

	while (miPila.Count != 0) {
		string nombreAlumno = miPila.Pop();
		cout << "Nombre de alumno: " << nombreAlumno << endl;
	}*/

myQ<string> miPila;
miPila.Enqueue("Selvin");
miPila.Enqueue("Gabriela");
miPila.Enqueue("Delia");
miPila.Enqueue("Bilander");

while (miPila.count != 0) {
	string nombreAlumno = miPila.Dequeue();
	cout << "Nombre de alumno: " << nombreAlumno << endl;
	
}


	_getch();
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file




    
