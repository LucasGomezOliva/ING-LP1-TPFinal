#pragma once
#include<string>

#include"cListaTemplate.h"

#include"cRecorrido.h"

//Borrar cuando este la lista
#include"cPasajero.h"
//borrar cuando este la lista

using namespace std;

class cColectivo
{

protected:

	static unsigned long int CantidadDeColectivos;

	string IDColectivo;
	
	bool EstadoOperaativo;

	//cSistemaDePagos* SistemaDePagos = NULL;
	
	cRecorrido* Recorrido = NULL;

	//cListaPasajeros* Pasajeros = NULL;
	
public:

#pragma region Constructores y destructores

	cColectivo();
	cColectivo(string IDColectivo);
	~cColectivo();

#pragma endregion

#pragma region Getter y setters

	string GetIDColectivo() const;
	bool GetEstadoOperativo() const ;

#pragma endregion

#pragma region Metodos

	/// <summary>
	/// Baja los pasajeros que llegaron al destino
	/// </summary>
	/// <param name="Destino"></param>
	/// <returns>Pasajero</returns>
	cPasajero* BajarPasajeros(string NombreParada);

	/// <summary>
	/// Agrega un nuevo pasajero a la lista pasajeros del colectivo
	/// </summary>
	/// <param name="Pasajero"></param>
	/// <returns>bool</returns>
	bool SubirPasajeros(cPasajero* Pasajero);

	/// <summary>
	/// Genera una averia en el colectivo
	/// </summary>
	/// <param></param>
	/// <returns></returns>
	void Averia();

	string ToStringColectivo();
	virtual void imprimir() = 0;

#pragma endregion

#pragma region Operadores

	/// <summary>
	/// Agrega un nuevo pasajero a la lista pasajeros del colectivo
	/// </summary>
	/// <param name="Pasajero"></param>
	/// <returns></returns>
	void operator+(cPasajero* Pasajero);

	/// <summary>
	/// Quita un nuevo pasajero a la lista pasajeros del colectivo
	/// </summary>
	/// <param name="Pasajero"></param>
	/// <returns></returns>
	cPasajero* operator-(cPasajero* Pasajero);

#pragma endregion
};

