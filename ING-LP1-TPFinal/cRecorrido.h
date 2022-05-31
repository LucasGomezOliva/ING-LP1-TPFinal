#pragma once
#include<iostream>
#include<string>
#include"cListaParadas.h"
using namespace std;
class cRecorrido
{
private:

	string CodigoRecorrido;
	string NombreRecorrido;
	cListaParadas* ListaParadas;
	float KmRecorrido;

public:

#pragma region Constructores y destructores

	/// <summary>
	/// Constructor por defecto de la clase Recorrido 
	/// </summary>
	cRecorrido();

	/// <summary>
	/// Constructor de la clase Recorrido 
	/// </summary>
	/// <param name="CodigoRecorrido"></param>
	/// <param name="NombreRecorrido"></param>
	/// <param name="KmRecorridoo"></param>
	cRecorrido(string CodigoRecorrido, string NombreRecorrido, float KmRecorrido);

	/// <summary>
	/// Destructor de la clase Recorrido 
	/// </summary>
	~cRecorrido();

#pragma endregion

#pragma region Getter y setters

	/// <summary>
	/// Retorna la lista de paradas del recorrido
	/// </summary>
	/// <returns>cListaParadas</returns>
	cListaParadas* GetListaParadas()const;

	/// <summary>
	/// Retorna el codigo del recorrido
	/// </summary>
	/// <returns>string</returns>
	string GetCodigoRecorrido();

	/// <summary>
	/// Retorna la cantidad de paradas del recorrido
	/// </summary>
	/// <returns>int</returns>
	int GetCantidadParadas() const;

#pragma endregion

#pragma region Metodos

	/// <summary>
	/// Compara el inicio del recorrido con el destino para saber la cantidad
	/// de paradas que se va a recorrer el pasajero
	/// </summary>
	/// <param name="NombreParadaInicio"></param>
	/// <param name="NombreParadaDestino"></param>
	/// <returns>Cantidad de paradas entre las 2 paradas</returns>
	int CantidadDeParadasEntreDestinos(string ParadaInicio, string ParadaDestino);

	bool AgregarParadasRecorrido(cParada* Parada);

	string ToStringRecorrido() const ;

	void imprimir() const ;

#pragma endregion

#pragma region Sobrecarga Operadores

#pragma endregion
};

