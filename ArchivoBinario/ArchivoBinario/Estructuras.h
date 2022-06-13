#pragma once

#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

struct InfoTabla
{
	int cantidadRegistros;
	int cantidadCampos;
};//sizeof =  bytes

enum  TipoCampo { tipoEntero, tipoCadena, tipoChar, tipoDecimal, tipoLogico
};
struct InfoCampo
{
	char nombreCampo[20];
	TipoCampo tipoCampo;

};//sizeof = 24

struct RegistroEntero
{
	unsigned int valor;
};

struct RegistroCadena
{
	char valor[100];
};
struct RegistroCaracter
{
	char valor;
};

struct RegistroDecimal
{
	float valor;
};

struct RegistroLogico
{
	bool valor;
};

class Estructuras
{
public :
	void imprimir();

	
};

#endif //!ESTRUCTURAS_H