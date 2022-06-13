#include "Alumno.h"
#include "Materia.h"
#include <conio.h>

#include <iostream>

using namespace std;

int main() {
	Alumno alumno;
	Materia materia;

	/*alumno.ingresarAlumno();
	alumno.ingresarAlumno();
	alumno.ingresarAlumno();
	alumno.ingresarAlumno();

	alumno.imprimirAlumnos();*/

	cout << "Cantidad de Alumnos: " << alumno.obtenerCantidadAlumnos();

	/*materia.ingresarMateria();
	materia.ingresarMateria();
	materia.ingresarMateria();
	
	materia.imprimirMaterias();*/

	//cout << "Cantidad de Alumnos: " << alumno.obtenerCantidadAlumnos();

	_getch();
}