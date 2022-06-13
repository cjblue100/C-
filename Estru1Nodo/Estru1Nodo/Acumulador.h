#pragma once
#include "persona.h"

template<class T>
class Acumulador
{
private:
	T _total;
public:
	Acumulador(T valorInicio) : _total(valorInicio) {};
	T operator+=(T const& t) { return _total = _total + t; };
	T GetTotal() const { return _total; };
};

template<>
class Acumulador<Person>
{
private:
	int _total;
public:
	Acumulador(int valorInicio) : _total(valorInicio) {};
	int operator+=(Person& t) {
		_total = _total + t.GetNumeroAleatorio();
		return _total;
	};
	int GetTotal() const { return _total; };
};

