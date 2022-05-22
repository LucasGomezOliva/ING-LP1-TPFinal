#pragma once
#include<iostream>
#include<string>
#include"cTarjeta.h"
using namespace std;
class cPasajero
{
private:

	string Nombre;
	unsigned int long DNI;
	string NombreParadaDestino;
	bool SillaDeRuedas;
	cTarjeta* TarjetaPasajero = NULL;

public:

#pragma region Constructores y destructores

	cPasajero();
	cPasajero(string Nombre, unsigned int long DNI, string NombreParadaDestino, bool SillaDeRuedas,float Saldo);
	~cPasajero();

#pragma endregion

#pragma region Getter y setters

	string GetDestino() const ;

#pragma endregion

#pragma region Metodos

	string ToStringPasajero()const;
	void imprimir()const;

#pragma endregion

#pragma region Sobrecarga Operadores

	friend ostream& operator<<(ostream& os, const cPasajero* Pasajero);

#pragma endregion

};

