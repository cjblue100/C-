#include "Materia.h"

#include <iostream>

using namespace std;

Materia::Materia() {
	materiasBinario.open("materias.dat", ios::in | ios::out | ios::app | ios::binary);

	if (!materiasBinario) {
		cout << "Error de apertura en archivo de Alumnos";
	}

	materiasBinario.close();
}

void Materia::ingresarMateria() {
	materiasBinario.open("materias.dat", ios::in | ios::out | ios::app | ios::binary);

	MateriaRegistro nuevaMateria;

	cout << "Ingrese codigo de materia: ";
	cin >> nuevaMateria.codigoMateria;

	cout << "Ingrese nombre de materia: ";
	cin >> nuevaMateria.nombre;

	cout << "Ingrese numero de Unidades Valorativas: ";
	cin >> nuevaMateria.uv;

	//colocar posicion de escritura al final del archivo
	materiasBinario.seekp(0, ios::end);

	materiasBinario.write(reinterpret_cast<const char*>(&nuevaMateria), sizeof(MateriaRegistro));

	cout << "Materia agregada exitosamente\n";

	materiasBinario.close();
}

void Materia::imprimirMaterias() {
	materiasBinario.open("materias.dat", ios::in | ios::binary);

	MateriaRegistro materiaLectura;

	//coloca el cursor de lectura en un byte indicado
	materiasBinario.seekg(0, ios::beg);

	materiasBinario.read(reinterpret_cast<char*>(&materiaLectura), sizeof(MateriaRegistro));

	while (!materiasBinario.eof()) {
		cout << "Materia { Codigo: " << materiaLectura.codigoMateria << ", Nombre: " <<
			materiaLectura.nombre << ", UV: " << materiaLectura.uv << " }\n";

		materiasBinario.read(reinterpret_cast<char*>(&materiaLectura), sizeof(MateriaRegistro));
	}

	materiasBinario.close();
}

bool Materia::buscarMateria(int codigoMateriaI) {
	materiasBinario.open("materias.dat", ios::in | ios::binary);

	materiasBinario.seekg(0, ios::beg);

	MateriaRegistro materiaLectura;

	materiasBinario.read(reinterpret_cast<char*>(&materiaLectura), sizeof(MateriaRegistro));

	while (!materiasBinario.eof()) {

		//valida si el resultado de ambas cadenas son iguales, mayores o menor dado su valor ASCII
		if (materiaLectura.codigoMateria==codigoMateriaI) {
			materiasBinario.close();
			return true;
		}

		materiasBinario.read(reinterpret_cast<char*>(&materiaLectura), sizeof(MateriaRegistro));
	}

	materiasBinario.close();
	return false;
}