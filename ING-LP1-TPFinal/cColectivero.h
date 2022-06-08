#pragma once
#include "cPersona.h"
using namespace std;
class cColectivero :public cPersona
{
private:

	const string Legajo;
	static unsigned int CantidadDeColectiveros;

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

#pragma region Gets

	string GetLegajo()const;

#pragma endregion

#pragma region Metodos

	/// <summary>
	/// Retorna el Destino del Pasajero
	/// </summary>
	/// <returns>String</returns>
	string CargarDestinoPasajero(string DestinoPasajero);

	string ToStringColectivero()const;

#pragma endregion

#pragma region Operadores

	friend ostream& operator<<(ostream& os, const cColectivero* Colectivero);

	bool operator==(const cColectivero& OtroColectivo);

#pragma endregion
};

