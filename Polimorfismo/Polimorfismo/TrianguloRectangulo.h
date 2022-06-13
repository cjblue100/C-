#pragma once

#ifndef TRI_RECTANGULO_H
#define TRI_RECTANGULO_H
#include "Figura2D.h"

class TrianguloRectangulo : public Figura2D
{
private:
	float base, altura;
	float hipotenusa;

public:
	TrianguloRectangulo();
	TrianguloRectangulo(float, float);

	void setBase(float);
	void setAltura(float);

	float getBase();
	float getAltura();
	float getHipotenusa();

	float getArea();
	float getPerimetro();
	

	void imprimirFigura();
	TipoFigura getTipo();
};

#endif
