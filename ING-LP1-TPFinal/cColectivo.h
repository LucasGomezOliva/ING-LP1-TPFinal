#pragma once
#include<string>
#include"cRecorrido.h"
#include"cSistemaDePagos.h"
#include"cListaPasajeros.h"
#include"cColectivero.h"
using namespace std;

class cColectivo
{

protected:

	static unsigned long int CantidadDeColectivos;
	string IDColectivo;
	bool EstadoOperaativo;
	cColectivero* Colectivero;
	cSistemaDePagos* SistemaDePagos;
	cRecorrido* Recorrido;
	cListaPasajeros* ListaPasajeros;
	
public:

#pragma region Constructores y destructores

	/// <summary>
	/// Constructor por defecto de la clase Colectivo 
	/// </summary>
	cColectivo();

	/// <summary>
	/// Constructor de la clase Colectivo 
	/// </summary>
	/// <param name="IDColectivo"></param>
	/// <param name="RecorridoAsignado"></param>
	cColectivo(string IDColectivo, cRecorrido* RecorridoAsignado);

	/// <summary>
	/// Destructor de la clase Colectivo 
	/// </summary>
	~cColectivo();

#pragma endregion

#pragma region Getter y setters

	/// <summary>
	/// Retorna el ID Colectivo
	/// </summary>
	/// <returns>String</returns>
	string GetIDColectivo() const;

	/// <summary>
	/// Retorna el Estado Operativo
	/// </summary>
	/// <returns>Bool</returns>
	bool GetEstadoOperativo() const ;

	/// <summary>
	/// Cambia el recorrido del colectivo por uno nuevo
	/// </summary>
	/// <param name="Nuevo Recorrido"></param>
	/// <returns></returns>
	void SetNuevoRecorrido(cRecorrido* NuevoRecorrido);

	/// <summary>
	/// Set colectivero
	/// </summary>
	/// <param name="Colectivero"></param>
	/// <returns></returns>
	void SetColectivero(cColectivero* Colectivero);

#pragma endregion

#pragma region Metodos

	/// <summary>
	/// Baja los pasajeros que llegaron al destino
	/// </summary>
	/// <param name="Destino"></param>
	/// <returns>Pasajero</returns>
	cPasajero* BajarPasajeros(string NombreParadaActual);

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

	/// <summary>
	/// Compara 2 colectivos para saber si son el mismo
	/// </summary>
	/// <param name="Colectivo"></param>
	/// <returns>
	/// TRUE : si es el mismo
	/// FALSE : si es otro colectivo
	/// </returns>
	bool operator==(const cColectivo& OtroColectivo);

#pragma endregion
};

