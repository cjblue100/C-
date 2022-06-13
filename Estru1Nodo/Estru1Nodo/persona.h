#pragma once
#include <string>

using std::string;

class Person
{
private:
	string _nombre;
	string _apellido;
	int _numeroAleatorio;

public:
	Person(string nombre, string apellido, int valor);
	~Person();
	string GetNombre();
	int GetNumeroAleatorio() const { return _numeroAleatorio; }
	void SetNumeroAleatorio(int valor) { _numeroAleatorio = valor; }
	bool operator<(Person const& person) const;
};


