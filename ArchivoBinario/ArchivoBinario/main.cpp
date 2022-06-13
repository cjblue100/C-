#include "Estructuras.h"
#include <iostream>
#include <conio.h>

#include <fstream>
#include <string>

using namespace std;

int main()
{
	InfoTabla informacion;
	char nombreTabla[25];

	//debe indicar el nombre del arhcivo con extension .dat
	cout << "Indique nombre de archivo/tabla: ";
	cin >> nombreTabla;


	fstream archivoTabla(nombreTabla, ios::in | ios::out | ios::app | ios::binary);

	if (!archivoTabla)
	{
		cout << "Error de Lectura/Escritura en archivo!\n";
		_getch();
		return 1;
	}

	cout << "Indique cantidad de campos: ";
	int cantCampos;
	cin >> cantCampos;

	cout << "Indique cantidad de registros: ";
	int cantRegistros;
	cin >> cantRegistros;


	
	informacion.cantidadRegistros = cantRegistros;
	informacion.cantidadCampos = cantCampos;

	archivoTabla.write(reinterpret_cast<const char*>(&informacion), sizeof(InfoTabla));

	for (int i = 0; i < informacion.cantidadCampos; i++)
	{
		cout << "\nSeleccione tipo de dato en campo " << (i + 1) << ":\n";
		cout << "1. Entero\n2. Cadena\n3. Caracter\n4. Decimal\n5. Logico\n>> ";
		int tipoCampo;
		cin >> tipoCampo;

		TipoCampo campoSeleccionado;

		switch (tipoCampo)
		{
		case 1:
			campoSeleccionado = TipoCampo::tipoEntero;
			break;
		case 2:
			campoSeleccionado = TipoCampo::tipoCadena;
			break;
		case 3:
			campoSeleccionado = TipoCampo::tipoChar;
			break;
		case 4:
			campoSeleccionado = TipoCampo::tipoDecimal;
			break;
		case 5:
			campoSeleccionado = TipoCampo::tipoLogico;
			break;
		default:
			cout << "\nError en seleccion de tipo de dato en campo\n";
			break;
		}

		InfoCampo campo;

		cout << "\nIngrese nombre de campo: " << (i + 1) << ":\n";
		cin >> campo.nombreCampo;
		campo.tipoCampo = campoSeleccionado;

		archivoTabla.write(reinterpret_cast<const char*>(&campo), sizeof(InfoCampo));
	}



	for (int i = 0; i < informacion.cantidadRegistros; i++)
	{
		//seekg es para posicion de lectura y seekp es para posicion de escritura
		archivoTabla.seekg(sizeof(InfoTabla), ios::beg);
		long posicionLectura = archivoTabla.tellg(); //devuelve posicion de lectura

		cout << "Registro " << (i + 1) << ": \n";

		for (int j = 0; j < informacion.cantidadCampos; j++)
		{
			archivoTabla.seekg(posicionLectura, ios::beg);
			InfoCampo campo;
			archivoTabla.read(reinterpret_cast<char*>(&campo), sizeof(InfoCampo));
			posicionLectura = archivoTabla.tellg();

			switch (campo.tipoCampo)
			{
			case TipoCampo::tipoEntero:
			{
				cout << "Ingrese valor tipo Entero: ";
				RegistroEntero v;
				cin >> v.valor;
				archivoTabla.seekp(0, ios::end); //ubicarse al final
				archivoTabla.write(reinterpret_cast<const char*>(&v), sizeof(RegistroEntero));
			}
			break;
			case TipoCampo::tipoCadena:
			{
				cout << "Ingrese valor tipo Cadena: ";
				RegistroCadena v;

				cin >> v.valor;

				archivoTabla.seekp(0, ios::end); //ubicarse al final
				archivoTabla.write(reinterpret_cast<const char*>(&v), sizeof(RegistroCadena));
			}
			break;
			case TipoCampo::tipoChar:
			{
				cout << "Ingrese valor tipo Caracter: ";
				RegistroCaracter v;
				cin >> v.valor;
				archivoTabla.seekp(0, ios::end); //ubicarse al final
				archivoTabla.write(reinterpret_cast<const char*>(&v), sizeof(RegistroCaracter));
			}
			break;
			case TipoCampo::tipoDecimal:
			{
				cout << "Ingrese valor tipo Decimal: ";
				RegistroDecimal v;
				cin >> v.valor;
				archivoTabla.seekp(0, ios::end);
				archivoTabla.write(reinterpret_cast<const char*>(&v), sizeof(RegistroDecimal));
			}
			break;
			case TipoCampo::tipoLogico:
			{
				cout << "Ingrese valor tipo Logico: ";
				int vLogico;
				cin >> vLogico;
				RegistroLogico v;

				(vLogico == 1) ? v.valor = true : v.valor = false;

				archivoTabla.seekp(0, ios::end);
				archivoTabla.write(reinterpret_cast<const char*>(&v), sizeof(RegistroLogico));

			}
			break;
			}//FIN SWITCH

		}//FIN DE FOR CAMPOS
	}//FIN DE FOR REGISTROS

	cout << "¡Archivo creado correctamente!\n";
	
	for (int i = 0; i < informacion.cantidadRegistros; i++)
	{
		//seekg es para posicion de lectura y seekp es para posicion de escritura
		archivoTabla.seekg(sizeof(InfoTabla), ios::beg);
		long posicionLectura = archivoTabla.tellg(); //devuelve posicion de lectura

		cout << "Registro " << (i + 1) << ": \n";

		for (int j = 0; j < informacion.cantidadCampos; j++)
		{
			archivoTabla.seekg(posicionLectura, ios::beg);
			InfoCampo campo;
			archivoTabla.read(reinterpret_cast<char*>(&campo), sizeof(InfoCampo));
			posicionLectura = archivoTabla.tellg();

			cout << "/ "<< campo.nombreCampo;

			//switch (campo.tipoCampo)
			//{
			//case TipoCampo::tipoEntero:
			//{
			//	cout << "Ingrese valor tipo Entero: ";
			//	RegistroEntero v;
			//	cin >> v.valor;
			//	archivoTabla.seekp(0, ios::end); //ubicarse al final
			//	archivoTabla.write(reinterpret_cast<const char*>(&v), sizeof(RegistroEntero));
			//}
			//break;
			//case TipoCampo::tipoCadena:
			//{
			//	cout << "Ingrese valor tipo Cadena: ";
			//	RegistroCadena v;

			//	cin >> v.valor;

			//	archivoTabla.seekp(0, ios::end); //ubicarse al final
			//	archivoTabla.write(reinterpret_cast<const char*>(&v), sizeof(RegistroCadena));
			//}
			//break;
			//case TipoCampo::tipoChar:
			//{
			//	cout << "Ingrese valor tipo Caracter: ";
			//	RegistroCaracter v;
			//	cin >> v.valor;
			//	archivoTabla.seekp(0, ios::end); //ubicarse al final
			//	archivoTabla.write(reinterpret_cast<const char*>(&v), sizeof(RegistroCaracter));
			//}
			//break;
			//case TipoCampo::tipoDecimal:
			//{
			//	cout << "Ingrese valor tipo Decimal: ";
			//	RegistroDecimal v;
			//	cin >> v.valor;
			//	archivoTabla.seekp(0, ios::end);
			//	archivoTabla.write(reinterpret_cast<const char*>(&v), sizeof(RegistroDecimal));
			//}
			//break;
			//case TipoCampo::tipoLogico:
			//{
			//	cout << "Ingrese valor tipo Logico: ";
			//	int vLogico;
			//	cin >> vLogico;
			//	RegistroLogico v;

			//	(vLogico == 1) ? v.valor = true : v.valor = false;

			//	archivoTabla.seekp(0, ios::end);
			//	archivoTabla.write(reinterpret_cast<const char*>(&v), sizeof(RegistroLogico));

			//}
			//break;
			//}//FIN SWITCH

		}//FIN DE FOR CAMPOS
	}//FIN DE FOR REGISTROS

	archivoTabla.close();

	_getch();
}