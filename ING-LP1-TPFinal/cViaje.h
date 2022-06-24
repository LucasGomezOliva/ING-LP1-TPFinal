#pragma once
#include<string>
#include<iostream>
using namespace std;
class cViaje
{
private:

	static unsigned int CantidadDeViajesCreados;
	const string IDViaje;
	const string Inicio;
	const string Destino;
	const float CostoDelViaje;

public:

#pragma region Constructores y destructores

	/// <summary>
	/// Constructor por defecto de la clase Viaje 
	/// </summary>
	cViaje();

	/// <summary>
	/// Constructor de la clase Viaje 
	/// </summary>
	/// <param name="Inicio"></param>
	/// <param name="Destino"></param>
	/// <param name="CostoDelViaje"></param>
	cViaje(string Inicio, string Destino, float CostoDelViaje);

	/// <summary>
	/// Destructor de la clase Viaje 
	/// </summary>
	~cViaje();

#pragma endregion

#pragma region Metodos

	string GetIDViaje()const;

	string ToStringViaje() const;
	void Imprimir() const;

#pragma endregion

#pragma region Operadores

	bool operator==(const cViaje& OtroViaje);

#pragma endregion
};

