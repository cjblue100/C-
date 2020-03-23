#pragma once
#ifndef ALUMNO_H
#define ALUMNO_H

#include <fstream>
using namespace std;

struct AlumnoRegistro {
	char numeroCuenta[9];
	char nombre[25];
	float promedio;
};

class Alumno {
private:
	fstream alumnosBinario;
	fstream temp;
public:
	Alumno();

	void ingresarAlumno();
	void imprimirAlumnos();
	void consultarAlumno();
	bool buscarAlumno(char[]);
	void actualizarPromedio(char[],float);
	int obtenerCantidadAlumnos();
};


#endif 