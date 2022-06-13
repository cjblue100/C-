#pragma once
#ifndef RACIONAL_H
#define RACIONAL_H

class Racional
{
	friend std::ostream& operator<<(std::ostream&, const Racional&);
	friend std::istream& operator>>(std::istream&, Racional&);
	friend Racional& operator+(const Racional&, const Racional&);
	friend Racional& operator-(const Racional&, const Racional&);
	friend Racional& operator*(const Racional&, const Racional&);
	friend Racional& operator/(const Racional&, const Racional&);

public:
	unsigned int numerador;
	unsigned int denominador;


	Racional();
	Racional(int, int);

	
	void imprimirDecimal();

};

#endif // !RACIONALH

