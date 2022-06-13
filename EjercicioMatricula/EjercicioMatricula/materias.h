#pragma once
#include <fstream>
#ifndef MATERIA_H
#define MATERIA_H

struct materiaRegistro
{
	int numeroMateria;
	char nombre[20];
	int uv;
};



class materia
{
private:
	std::fstream	materiaBinario;

public:
	materia();
	void ingresarMateria();
	void consultarMaterias();
	bool buscarMateria();
	void imprimirMateria();
};


#endif // !MATERIA_H

