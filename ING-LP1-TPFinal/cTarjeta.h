#pragma once
#include<string>
#include"cListaViajes.h"
using namespace std;
class cTarjeta
{
private:
	
	unsigned int long NumeroTarjeta;
	float Saldo;
	static unsigned long int CantidadDeTarjetasCreadas;
	cListaViajes* ListaDeViajesRealizados;

public:

#pragma region Constructores y destructores

	/// <summary>
	/// Constructor por defecto de la clase Tarjeta 
	/// </summary>
	cTarjeta();

	/// <summary>
	/// Constructor de la clase Tarjeta 
	/// </summary>
	/// <param name="Saldo"></param>
	cTarjeta(float Saldo);

	/// <summary>
	/// Destructor de la clase Tarjeta 
	/// </summary>
	~cTarjeta();

#pragma endregion

#pragma region Getter y setters

	/// <summary>
	/// Retorna el saldo actual de la tarjeta
	/// </summary>
	/// <param></param>
	/// <returns>Saldo</returns>
	float GetSaldo() const ;

#pragma endregion

#pragma region Metodos

	/// <summary>
	/// Agrega saldo a la tarjeta
	/// </summary>
	/// <param name="Saldo"></param>
	/// <returns>Nuevo saldo total</returns>
	float CargaDeSaldo(float SaldoAgregar);
	
	/// <summary>
	/// Resta el saldo del viaje
	/// </summary>
	/// <param name="Saldo"></param>
	/// <returns>Nuevo saldo total</returns>
	float DescuentoSalto(float Cargo);

	/// <summary>
	/// Agrega el viaje a la lista
	/// </summary>
	/// <param name="Viaje"></param>
	/// <returns></returns>
	void AgregarViajeLista(cViaje* NuevoViaje);

	string ToStringTarjeta()const;

	void Imprimir()const;

#pragma endregion
};

