#pragma once
#include<string>
#include<iostream>

//borr
#include"cPasajero.h"
//borr
using namespace std;
class cParada
{
private:

	string IDParada;
	string NombreParada;
	string Direccion;
	//cListaPasajeros* ListaPasajeros = NULL;

public:
	
#pragma region Constructores y destructores

	/// <summary>
	/// Constructor por defecto de la clase Parada 
	/// </summary>
	cParada();

	/// <summary>
	/// Constructor de la clase Parada 
	/// </summary>
	/// <param name="IDParada"></param>
	/// <param name="NombreParada"></param>
	/// <param name="Direccion"></param>
	cParada(string IDParada, string NombreParada, string Direccion);

	~cParada();

#pragma endregion

#pragma region Getter y setters

#pragma endregion

#pragma region Metodos

	cPasajero* PasajeroSubeColectivo();
	string ToStringParada() const;
	void imprimir() const;

#pragma endregion

#pragma region Sobrecarga Operadores

	friend ostream& operator<<(ostream& os, const cParada* Parada);

#pragma endregion

};

