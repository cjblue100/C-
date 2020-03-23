#include "Alumno.h"
#include "materias.h"
#include <conio.h>
#include "Nota.h"
#include <iostream>

using namespace std;

int main() {
	Alumno alumno;
	Materia materia;
	Nota nota;

	/*alumno.ingresarAlumno();
	alumno.ingresarAlumno();*/
	
	
	nota.agregarNota();
	

	alumno.imprimirAlumnos();

	//materia.imprimirMaterias();

	//cout << "Cantidad de Alumnos: " << alumno.obtenerCantidadAlumnos();

	//materia.ingresarMateria();
	//materia.ingresarMateria();
	//materia.ingresarMateria();

	

	/*materia.imprimirMaterias();*/

	/*cout << "Cantidad de Alumnos: " << alumno.obtenerCantidadAlumnos();*/

	_getch();
}