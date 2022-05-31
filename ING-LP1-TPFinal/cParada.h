#pragma once
#include<string>
#include<iostream>
#include"cListaPasajeros.h"
using namespace std;
class cParada
{
private:

	string IDParada;
	string NombreParada;
	string Direccion;
	cListaPasajeros* ListaPasajeros;

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

	/// <summary>
	/// Destructor de la clase Parada 
	/// </summary>
	~cParada();

#pragma endregion

#pragma region Getter y setters

	/// <summary>
	/// Retorna la lista de paradas de pasajeros
	/// </summary>
	/// <returns>cListaPasajeros</returns>
	cListaPasajeros* GetListaPasajeros() const;

	/// <summary>
	/// Retorna el IDParada
	/// </summary>
	/// <returns>string</returns>
	string GetIDParada() const;

	/// <summary>
	/// Retorna el Nombre de la Parada
	/// </summary>
	/// <returns>string</returns>
	string GetNombreParada() const;

#pragma endregion

#pragma region Metodos

	cPasajero* PasajeroSubeColectivo();

	string ToStringParada() const;

	void imprimir() const;

#pragma endregion

#pragma region Sobrecarga Operadores

	friend ostream& operator<<(ostream& os, const cParada* Parada);

	bool operator==(const cParada& OtraParada);

#pragma endregion

};

