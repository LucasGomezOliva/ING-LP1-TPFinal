#pragma once
#include"cPasajero.h"
#include "cListaTemplate.h"

class cListaPasajeros :public cListaTemplate<cPasajero>
{
private:

public:

#pragma region Constructores y destructores

	/// <summary>
	/// Constructor por defecto de la clase ListaPasajeros 
	/// </summary>
	cListaPasajeros();

	/// <summary>
	/// Constructor de la clase ListaPasajeros 
	/// </summary>
	/// <param name="TamMax"></param>
	/// <param name="borrar"></param>
	cListaPasajeros(unsigned int TamMax, bool borrar);

	/// <summary>
	/// Destructor de la clase ListaPasajeros 
	/// </summary>
	~cListaPasajeros();

#pragma endregion

#pragma region Metodos

	/// <summary>
	/// Quita de la lista un pasajero con silla de ruedas 
	/// </summary>
	/// <returns>Pasajero</returns>
	cPasajero* QuitarSillaRuedas();

#pragma endregion

#pragma region Sobrecarga Operadores

	friend ostream& operator<<(ostream& os, const cListaPasajeros* ListaPasajeros);

#pragma endregion
};

