#pragma once
#include <iostream>
#include"Defines.h"
#include"cListaStrings.h"
using namespace std;
class cGenerador
{
private:

	cListaStrings* ListaNombres;
	cListaStrings* ListaDNI;
	cListaStrings* ListaDireccionesParadas;

public:

#pragma region Constructores y destructores

	/// <summary>
	/// Constructor por defecto de la clase Generador
	/// </summary>
	cGenerador();

	/// <summary>
	/// Destructor de la clase Colectivo 
	/// </summary>
	~cGenerador();

#pragma endregion

#pragma region Metodos

	/// <summary>
	/// Retorna un Random bool
	/// </summary>
	/// <returns>Bool</returns>
	bool GenerarRandomBool();

	/// <summary>
	/// Retorna un Random Nombre
	/// </summary>
	/// <returns>String puntero</returns>
	string* GenerarRandomNombrePasajero();

	/// <summary>
	/// Retorna un Random DNI
	/// </summary>
	/// <returns>String puntero</returns>
	string* GenerarRandomDNI();

	/// <summary>
	/// Retorna un Random Direccion
	/// </summary>
	/// <returns>String puntero</returns>
	string* GenerarRandomDireccion();

	/// <summary>
	/// Retorna un Random Saldo entre 300 y 1700
	/// </summary>
	/// <returns>Float</returns>
	float GenerarRandomSaldo();

#pragma endregion
};

