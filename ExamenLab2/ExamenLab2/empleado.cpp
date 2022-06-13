#include"Empleado.h"
#include <iostream>

empleado::empleado() : codigoEmpleado(-1),nombreEmpleado(" "), salario(-1), siguiente(nullptr), anterior(nullptr), activo(NULL)
{}

empleado::empleado(int _id, string _name, float _salario , bool _activo, empleado* _sigue, empleado* _anterior)
{
	setID(_id);
	setName(_name);
	setSalario(_salario);
	setActivo(_activo);
	setSiguiente(_sigue);
	setAnterior(_anterior);
}

void empleado::setID(int _id)
{
	this->codigoEmpleado = _id;
}

void empleado::setName(string _name)
{
	this->nombreEmpleado = _name;
}

void empleado::setSalario(float sal)
{
	this->salario = sal;
}

void empleado::setActivo(bool act)
{
	this->activo = act;
}

void empleado::setSiguiente(empleado* sigue)
{
	this->siguiente = sigue;
}

void empleado::setAnterior(empleado* ante)
{
	this->anterior = ante;
}


int empleado::getID()
{
	return this->codigoEmpleado;
}

string empleado::getName()
{
	return this->nombreEmpleado;
}

float empleado::getSalario()
{
	return this->salario;
}

bool empleado::getActivo()
{
	return this->activo;
}

empleado* empleado::getSiguente()
{
	return this->siguiente;
}

empleado* empleado::getAnterior()
{
	return this->anterior;
}

void empleado::imprimir()
{
	cout << "{ Codigo: " << getID() << " nombre: " << getName() << " Salario: " << getSalario() << " }";
}