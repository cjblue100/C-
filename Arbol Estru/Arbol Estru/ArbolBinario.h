#pragma once
#include<iostream>
#include<sstream>
#include"NodoArbol.h"

class ArbolBinario
{
private:

	NodoArbol* Encontrar(NodoArbol* nodoPadre, string valor)
	{
		stringstream converter1(valor);
		stringstream converter2(nodoPadre->GetValor());

		int valorString = 0;
		int valorActual = 0;
		converter1 >> valorString;
		converter2 >> valorActual;

		if (nodoPadre == nullptr)
			return nullptr;
		else if (nodoPadre->GetValor() == valor)
			return nodoPadre;
		else if (valorString < valorActual)
			return Encontrar(nodoPadre->GetIzquierdo(), valor);
		else
			return Encontrar(nodoPadre->GetDerecho(), valor);
	}

	void Insertar(NodoArbol* nodoPadre, string value)
	{
		string valorActualString = nodoPadre->GetValor();

		stringstream converter1(value);
		stringstream converter2(valorActualString);

		int nuevoValor = 0;
		int valorActual = 0;
		converter1 >> nuevoValor;
		converter2 >> valorActual;

		if (nuevoValor >= valorActual)
		{
			if (nodoPadre->GetDerecho() == nullptr) {
				NodoArbol* nuevo = new NodoArbol(value);
				nodoPadre->SetDerecho(nuevo);
				nuevo->SetPadre(nodoPadre);
				return;

			}
			else {
				Insertar(nodoPadre->GetDerecho(), value);
			}
		}
		else if (nuevoValor < valorActual)
		{
			if (nodoPadre->GetIzquierdo() == nullptr) {
				NodoArbol* nuevo = new NodoArbol(value);
				nodoPadre->SetIzquierdo(nuevo);
				nuevo->SetPadre(nodoPadre);
				return;

			}
			else {
				Insertar(nodoPadre->GetIzquierdo(), value);
			}
		}
	}

public:

	NodoArbol* Raiz;
	int Count;

	ArbolBinario() :Raiz(nullptr) {
		Count = 0;
	}

	void Eliminar(string valor)
	{
		NodoArbol* valorEncontrado = Buscar(valor);
		NodoArbol* padreEncontrado = valorEncontrado->GetPadre();

		if (valorEncontrado->GetDerecho() == nullptr) {
			if (padreEncontrado == nullptr)
				Raiz = valorEncontrado->GetIzquierdo();
			else {
				if (padreEncontrado->toInt() > valorEncontrado->toInt()) {
					padreEncontrado->SetIzquierdo(valorEncontrado->GetIzquierdo());
				}
				else if (padreEncontrado->toInt() < valorEncontrado->toInt())
				{
					padreEncontrado->SetDerecho(valorEncontrado->GetIzquierdo());
				}
			}
		}
		else if (valorEncontrado->GetDerecho()->GetIzquierdo() == nullptr)
		{
			valorEncontrado->GetDerecho()->SetIzquierdo(valorEncontrado->GetIzquierdo());

			if (padreEncontrado == nullptr)
				Raiz = valorEncontrado->GetDerecho();
			else
			{
				if (padreEncontrado->toInt() > valorEncontrado->toInt())
				{
					padreEncontrado->SetIzquierdo(valorEncontrado->GetDerecho());
				}
				else if (padreEncontrado->toInt() < valorEncontrado->toInt())
				{
					padreEncontrado->SetDerecho(valorEncontrado->GetDerecho());
				}
			}
		}
		else
		{
			NodoArbol* masIzquierdo = valorEncontrado->GetDerecho()->GetIzquierdo();
			NodoArbol* masIzquierdoPadre = valorEncontrado->GetDerecho();

			while (masIzquierdo->GetIzquierdo() != nullptr) {
				masIzquierdoPadre = masIzquierdo;
				masIzquierdo = masIzquierdo->GetIzquierdo();
			}
			
			masIzquierdoPadre->SetIzquierdo(masIzquierdo->GetDerecho());

			masIzquierdo->SetIzquierdo(valorEncontrado->GetIzquierdo());
			masIzquierdo->SetDerecho(valorEncontrado->GetDerecho());




			if (padreEncontrado == nullptr)
				Raiz = masIzquierdoPadre->GetIzquierdo();
			else if(padreEncontrado->toInt() > valorEncontrado->toInt())
			{
				padreEncontrado->SetIzquierdo(masIzquierdo);
			}
			else if (padreEncontrado->toInt() < masIzquierdo->toInt())
			{
				padreEncontrado->SetDerecho(masIzquierdo);
			}



		}

	}
	void Agregar(string valor) {
		if (Count == 0) {
			NodoArbol* nuevo = new NodoArbol(valor);
			Raiz = nuevo;

		}
		else {

			Insertar(Raiz, valor);

		}
		Count++;

	}

	NodoArbol* Buscar(string valor)
	{
		return Encontrar(Raiz, valor);
	}


	int Preorder(NodoArbol* nodo)
	{
		if (nodo == nullptr)
		{
			return 0;
		}
		else
		{
			cout << nodo->GetValor() << endl;
			Preorder(nodo->GetIzquierdo());
			
			Preorder(nodo->GetDerecho());
		}
	}

	void Print()
	{
		Preorder(Raiz);
	}

	void imprimir()
	{
		imprimirRec(Raiz);

	}

	void imprimirRec(NodoArbol* _raiz)
	{
		if (_raiz == nullptr)
			return;

		//printf("[ %s ] ", _raiz->getNombre());
		
		imprimirRec(_raiz->GetIzquierdo());
		cout << "[ " << _raiz->GetValor() << " ] "; //postOrden
		imprimirRec(_raiz->GetDerecho());

	}
};


