#include "TrianguloRectangulo.h"
#include <iostream>
#include <cmath>
using std::cout;

TrianguloRectangulo::TrianguloRectangulo() : base(0), altura(0), hipotenusa(0)
{}

TrianguloRectangulo::TrianguloRectangulo(float _base, float _altura)
{
	setBase(_base);
	setAltura(_altura);
	this->hipotenusa = getHipotenusa();
}

void TrianguloRectangulo::setBase(float _base)
{
	if (_base > 0)
		this->base = _base;
	else
		cout << "Error de ingreso de Base \n";

}

void TrianguloRectangulo::setAltura(float _altura)
{
	if (_altura > 0)
		this->altura = _altura;
	else
		cout << "Error de ingreso de Altura\n";

}

float TrianguloRectangulo::getBase()
{
	return this->base;
}

float TrianguloRectangulo::getAltura()
{
	return this->altura;
}

float TrianguloRectangulo::getHipotenusa()
{
	return sqrt(pow(getBase(),2) + pow(getAltura(), 2));
}

float TrianguloRectangulo::getArea()
{
	return (getBase() * getAltura()) / 2;
}

float TrianguloRectangulo::getPerimetro()
{
	return getBase() + getAltura() + getHipotenusa();
}

void TrianguloRectangulo::imprimirFigura()
{
	cout << "TrianguloRectangulo { Base: " << getBase()
		<< ", altura: " << getAltura() << "}\n";
}

TipoFigura TrianguloRectangulo::getTipo()
{
	return TipoFigura:: TTrianguloRectangulo;

}