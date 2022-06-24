#pragma once
#include<string>
#include"cRecorrido.h"
#include"cSistemaDePagos.h"
#include"cListaPasajeros.h"
#include"cColectivero.h"
#include"eSentidoRecorrido.h"
#include"cFecha.h"
using namespace std;

class cColectivo
{

protected:

	const string IDColectivo;
	static unsigned long int CantidadDeColectivos;
	bool EstadoOperaativo;
	cColectivero* Colectivero;
	cSistemaDePagos* SistemaDePagos;
	cRecorrido* Recorrido;
	cListaPasajeros* ListaPasajeros;
	unsigned int PosDelRecorrido;
	cFecha* FechaUltimoMantenimiento;
	string GPS;
	eSentidoRecorrido Sentido;
	
public:

#pragma region Constructores y destructores

	/// <summary>
	/// Constructor por defecto de la clase Colectivo 
	/// </summary>
	cColectivo();

	/// <summary>
	/// Constructor de la clase Colectivo 
	/// </summary>
	/// <param name="RecorridoAsignado"></param>
	cColectivo(cRecorrido* RecorridoAsignado);

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
	/// Retorna el Recorrido del colectivo
	/// </summary>
	/// <returns>String</returns>
	cRecorrido* GetRecorrido() const;

	/// <summary>
	/// Retorna el Estado Operativo
	/// </summary>
	/// <returns>Bool</returns>
	bool GetEstadoOperativo() const ;

	/// <summary>
	/// Retorna el Sistema de pagos
	/// </summary>
	/// <returns>SistemaDePagos</returns>
	cSistemaDePagos* GetSistemaDePagos() const;

	/// <summary>
	/// Cambia el recorrido del colectivo por uno nuevo
	/// </summary>
	/// <param name="Nuevo Recorrido"></param>
	/// <returns></returns>
	void SetNuevoRecorrido(cRecorrido* NuevoRecorrido);

	/// <summary>
	/// Retorna la ubicacion del GPS
	/// </summary>
	/// <returns>String</returns>
	string GetGPS() const;

	/// <summary>
	/// Retorna la Posicion del recorrido
	/// </summary>
	/// <returns>unsigned int</returns>
	unsigned int GetPosicionRecorrido() const;
	

	/// <summary>
	/// Set colectivero
	/// </summary>
	/// <param name="Colectivero"></param>
	/// <returns></returns>
	void SetColectivero(cColectivero* Colectivero);

	/// <summary>
	/// Set nueva fecha de mantenimiento
	/// </summary>
	/// <param name="Fecha"></param>
	/// <returns></returns>
	void SetFechaMantenimiento(cFecha* Fecha);

#pragma endregion

#pragma region Metodos

	/// <summary>
	/// Avanza a la siguiente parada del recorrido
	/// </summary>
	void AvanzarRecorrido();

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
	//bool SubirPasajeros(cPasajero* Pasajero);
	virtual bool SubirPasajeros(cPasajero* Pasajero) = 0;

	/// <summary>
	/// Controla que el pasajero suba al sentido correcto del recorrido
	/// </summary>
	/// <param name="Pasajero"></param>
	/// <returns>bool</returns>
	bool ControlSentidoPasajero(cPasajero* Pasajero);

	/// <summary>
	/// Genera una averia en el colectivo
	/// </summary>
	/// <param></param>
	/// <returns></returns>
	void Averia();
	
	/// <summary>
	/// Actualiza el GPS del colectivo
	/// </summary>
	/// <param></param>
	/// <returns></returns>
	void ActualizarGPS();

	/// <summary>
	/// Cambia el sentido del recorrido
	/// </summary>
	/// <param></param>
	/// <returns></returns>
	void CambioDeSentidoRecorrido();

	string ToStringColectivo() const;

	virtual void Imprimir() = 0;

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

	friend istream& operator>>(istream& input, cColectivo& Colectivo);

	friend ostream& operator<<(ostream& os, const cColectivo* Colectivo);

	void operator++();

#pragma endregion
};

