#pragma once
#include<string>
using namespace std;
class cTarjeta
{
private:
	unsigned int long NumeroTarjeta;
	float Saldo;
	static unsigned long int CantidadDeTarjetasCreadas;

	//cListaDeViajes* ListaDeViajesRealizados = NULL;

public:

#pragma region Constructores y destructores

	cTarjeta();
	cTarjeta(float Saldo);
	~cTarjeta();

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

	string ToStringTarjeta()const;

	void Imprimir()const;
#pragma endregion
};

