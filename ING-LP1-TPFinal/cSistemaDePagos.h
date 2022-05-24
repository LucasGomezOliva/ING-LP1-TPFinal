#pragma once
#include<string>
#include"cViaje.h"
#include"cTarjeta.h"
using namespace std;
class cSistemaDePagos
{
private:

	float ColectaDelDia;
	unsigned int CantidadDePasajeros;
	const float PrecioPorParada = 15;

public:

#pragma region Constructores y destructores

	/// <summary>
	/// Constructor por defecto de la clase SistemaDePagos 
	/// </summary>
	cSistemaDePagos();

	/// <summary>
	/// Destructor de la clase SistemaDePagos 
	/// </summary>
	~cSistemaDePagos();

#pragma endregion

#pragma region Getter y setters

	/// <summary>
	/// Retorna el monto de la colecta del dia de ese colectivo
	/// </summary>
	/// <returns>float</returns>
	float GetColectaDelDia() const;

	/// <summary>
	/// Retorna la cantidad de pasajeros que viajaron en el dia en ese colectivo
	/// </summary>
	/// <returns>Bool</returns>
	unsigned int GetCantidadDePasajeros() const;

#pragma endregion

#pragma region Metodos

	/// <summary>
	/// Crea el viaje y gestina el pago del pasaje
	/// </summary>
	/// <param name="Inicio"></param>
	/// <param name="Destino"></param>
	/// <param name="CantidadDeParadas"></param>
	/// <param name="TarjetaPasajero"></param>
	/// <returns>
	/// True si el pasajero puede pagar el viaje 
	/// False si el NO pasajero puede pagar el viaje
	/// </returns>
	bool GenerarViaje(string Inicio, string Destino, int CantidadDeParadas, cTarjeta* TarjetaPasajero);

#pragma endregion

#pragma region Sobrecarga Operadores

#pragma endregion
};

