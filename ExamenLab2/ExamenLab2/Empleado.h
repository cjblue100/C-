#pragma once
#include <string>




using namespace std;
class empleado
{
private:
	int codigoEmpleado;
	string nombreEmpleado;
	float salario;
	bool activo;
	empleado* siguiente;
	empleado* anterior;

public:
	empleado();
	empleado(int, string,float, bool, empleado*, empleado*);

	void setID(int);
	void setName(string);
	void setSalario(float);
	void setActivo(bool);
	void setSiguiente(empleado*);
	void setAnterior(empleado*);

	int getID();
	string getName();
	float getSalario();
	bool getActivo();
	empleado* getAnterior();
	empleado* getSiguente();

	void imprimir();
};
