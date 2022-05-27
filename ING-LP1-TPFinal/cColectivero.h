#pragma once
#include "cPersona.h"
class cColectivero :public cPersona
{
private:

	string Legajo;

public:

#pragma region Constructores y destructores

	/// <summary>
	/// Constructor por defecto de la clase Colectivero 
	/// </summary>
	cColectivero();

	/// <summary>
	/// Constructor de la clase Colectivero 
	/// </summary>
	/// <param name="Nombre"></param>
	/// <param name="DNI"></param>
	cColectivero(string Nombre, string DNI);

	/// <summary>
	/// Destructor de la clase Colectivero 
	/// </summary>
	~cColectivero();

#pragma endregion

#pragma region Metodos

	/// <summary>
	/// Retorna el Destino del Pasajero
	/// </summary>
	/// <returns>String</returns>
	string CargarDestinoPasajero(string DestinoPasajero);

#pragma endregion

#pragma region Operadores

#pragma endregion
};

