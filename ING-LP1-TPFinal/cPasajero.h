#pragma once
#include<iostream>
#include<string>
#include"cTarjeta.h"
using namespace std;
class cPasajero
{
private:

	string Nombre;
	string DNI;
	string NombreParadaDestino;
	bool SillaDeRuedas;
	cTarjeta* TarjetaPasajero = NULL;

public:

#pragma region Constructores y destructores

	/// <summary>
	/// Constructor por defecto de la clase Pasajero 
	/// </summary>
	cPasajero();

	/// <summary>
	/// Constructor de la clase Pasajero 
	/// </summary>
	/// <param name="Nombre"></param>
	/// <param name="DNI"></param>
	/// <param name="NombreParadaDestino"></param>
	/// <param name="SillaDeRuedas"></param>
	/// <param name="Saldo"></param>
	cPasajero(string Nombre, string DNI, string NombreParadaDestino, bool SillaDeRuedas, float Saldo);

	/// <summary>
	/// Destructor de la clase Pasajero 
	/// </summary>
	~cPasajero();

#pragma endregion

#pragma region Getter y setters

	/// <summary>
	/// Retorna si el pasajero esta en silla de ruedas
	/// </summary>
	/// <returns>bool</returns>
	bool GetSillaDeRuedas() const ;

	/// <summary>
	/// Retorna el destino del pasajero
	/// </summary>
	/// <returns>string</returns>
	string GetDestino() const ;

	/// <summary>
	/// Retorna el puntero de la tarjeta del pasajero
	/// </summary>
	/// <returns>Tarjeta</returns>
	cTarjeta* GetTarjetaPasajero() const ;

	/// <summary>
	/// Retorna el DNI del pasajero
	/// </summary>
	/// <returns>string</returns>
	string GetDNI() const;

#pragma endregion

#pragma region Metodos

	string ToStringPasajero()const;

	void imprimir()const;

#pragma endregion

#pragma region Sobrecarga Operadores

	friend ostream& operator<<(ostream& os, const cPasajero* Pasajero);

	bool operator==(const cPasajero& OtroPasajero);

#pragma endregion

};

