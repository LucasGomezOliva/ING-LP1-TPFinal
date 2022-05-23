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

	cSistemaDePagos();
	~cSistemaDePagos();

#pragma endregion

#pragma region Getter y setters

	float GetColectaDelDia() const;

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

