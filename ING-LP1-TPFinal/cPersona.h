#pragma once
#include<iostream>
#include<string>
using namespace std;

class cPersona
{
protected:

	string Nombre;
	string DNI;

public:

#pragma region Constructores y destructores

	/// <summary>
	/// Constructor por defecto de la clase Persona 
	/// </summary>
	cPersona();

	/// <summary>
	/// Constructor de la clase Pasajero 
	/// </summary>
	/// <param name="Nombre"></param>
	/// <param name="DNI"></param>
	cPersona(string Nombre, string DNI);

	/// <summary>
	/// Destructor de la clase Persona 
	/// </summary>
	~cPersona();

#pragma endregion
};

