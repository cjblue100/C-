#pragma once

#ifndef FIGURA2D_H
#define FIGURA2D_H

enum TipoFigura { TRectangulo, TTrianguloRectangulo };

class Figura2D
{
public:

	virtual float getArea() = 0; // FUERZA EL TENER QUE DARLE UNA FUNCION A ESTA COSA EN LA CLASE HIJA
	virtual float getPerimetro() = 0;
	virtual void imprimirFigura() = 0;
	virtual TipoFigura getTipo() = 0;


};









#endif
