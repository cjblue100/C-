#include "Alumno.h"
#include <iostream>

using namespace std;
Alumno::Alumno() {
	alumnosBinario.open("alumnos.dat", ios::in | ios::out | ios::app | ios::binary);

	if (!alumnosBinario) {
		cout << "Error de apertura en archivo de Alumnos";
	}

	alumnosBinario.close();
}

void Alumno::ingresarAlumno() {
	alumnosBinario.open("alumnos.dat", ios::in | ios::out | ios::app | ios::binary);

	AlumnoRegistro nuevoAlumno;

	cout << "Ingrese numero de cuenta: ";
	cin >> nuevoAlumno.numeroCuenta;

	cout << "Ingrese nombre de alumno: ";
	cin >> nuevoAlumno.nombre;

	nuevoAlumno.promedio = 0;

	//colocar posicion de escritura al final del archivo
	alumnosBinario.seekp(0, ios::end);

	alumnosBinario.write(reinterpret_cast<const char*>(&nuevoAlumno), sizeof(AlumnoRegistro));

	alumnosBinario.close();

	cout << "Alumno agregado exitosamente\n";
}

void Alumno::imprimirAlumnos() {
	alumnosBinario.open("alumnos.dat", ios::in | ios::binary);

	AlumnoRegistro alumnoLectura;

	//coloca el cursor de lectura en un byte indicado
	alumnosBinario.seekg(0, ios::beg);

	alumnosBinario.read(reinterpret_cast<char*>(&alumnoLectura), sizeof(AlumnoRegistro));

	while (!alumnosBinario.eof()) {
		

		cout << "Alumno { Cuenta: " << alumnoLectura.numeroCuenta << ", Nombre: " <<
			alumnoLectura.nombre << ", Promedio: " << alumnoLectura.promedio << " }\n";

		alumnosBinario.read(reinterpret_cast<char*>(&alumnoLectura), sizeof(AlumnoRegistro));
	}

	alumnosBinario.close();
}

int Alumno::obtenerCantidadAlumnos() {
	alumnosBinario.open("alumnos.dat", ios::in | ios::binary);

	long finalArchivo;
	alumnosBinario.seekg(0, ios::end);

	finalArchivo = alumnosBinario.tellg(); //obtiene el byte en el que se encuentra el cursor de lectura

	alumnosBinario.close();

	return finalArchivo / sizeof(AlumnoRegistro);
}

bool Alumno::buscarAlumno(char numeroCuentaI[]) {
	alumnosBinario.open("alumnos.dat", ios::in | ios::binary);

	alumnosBinario.seekg(0, ios::beg);

	AlumnoRegistro alumnoLectura;

	alumnosBinario.read(reinterpret_cast<char*>(&alumnoLectura), sizeof(AlumnoRegistro));
	
	while (!alumnosBinario.eof()) {

		//valida si el resultado de ambas cadenas son iguales, mayores o menor dado su valor ASCII
		if (strcmp(alumnoLectura.numeroCuenta, numeroCuentaI) == 0) {
			alumnosBinario.close();
			return true;
		}

		alumnosBinario.read(reinterpret_cast<char*>(&alumnoLectura), sizeof(AlumnoRegistro));
	}

	alumnosBinario.close();
	return false;
}
//ios::in allows input(read operations) from a stream.ios::out allows
//output(write operations) to a stream.of std::fstream enables both inputand output for the stream.
void Alumno::actualizarPromedio(char idAlumno[],float _promedio)
{

	temp.open("Temp.dat", ios::in | ios::out | ios::app | ios::binary);

	alumnosBinario.open("alumnos.dat", ios::in | ios::binary);
	alumnosBinario.seekg(0, ios::beg);

	AlumnoRegistro alumnoEscritura;
	
	alumnosBinario.read(reinterpret_cast<char*>(&alumnoEscritura), sizeof(AlumnoRegistro));
	cout << alumnoEscritura.promedio;
	while (!alumnosBinario.eof()) {
		
		//valida si el resultado de ambas cadenas son iguales, mayores o menor dado su valor ASCII
		if (strcmp(alumnoEscritura.numeroCuenta, idAlumno) == 0) {
			
			alumnoEscritura.promedio += _promedio;
			cout << "fin: " << alumnoEscritura.promedio;
		}
		
		temp.seekp(0, ios::end);
		temp.write(reinterpret_cast<const char*>(&alumnoEscritura), sizeof(AlumnoRegistro));
		alumnosBinario.read(reinterpret_cast<char*>(&alumnoEscritura), sizeof(AlumnoRegistro));

		
	}
	temp.close();
	alumnosBinario.close();
	remove("alumnos.dat");
	rename("Temp.dat", "alumnos.dat");
}