#pragma once
#include "Empleado.h"


class lista
{
	struct registroEmpleados
	{
		int code;
		string nomb;
		float moni;
	};


private:
	empleado* primero;
	empleado* ultimo;

public:

	lista();
	bool ifEmpty();
	void agregarlista(int _id, string _name, float _salario);
	void imprimirLista();
	void eliminar(int );
	void desactivarEmpleado(int);

	void guardarEmpleado();
};









