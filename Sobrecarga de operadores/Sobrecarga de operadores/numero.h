#pragma once
#include <iostream>
#ifndef NUMERO_H
#define NUMERO_H

class numero
{
	friend std::ostream& operator<<(std::ostream&,const numero&);
	friend std::istream& operator>>(std::istream&, numero&);
	friend numero& operator+(const numero&, const numero&);
	//friend numero& operator+(const numero&, const int&);

	//friend numero& operator-(const numero&, const numero&);


private:
	unsigned int valor,valorB; //unsigned: entero sin signo

public:
	numero();
	numero(int,int);

	//numero& operator++();
	//numero& operator++(int);

};



#endif
