#pragma once
#include <iostream>
#include <string>
#include "cRecorrido.h"
using namespace std;

#define CantidadTotalParadas 28

const string CodigoRecorridos[] = { "A","B","C" };

const string NombreRecorridos[] = { 
	"Barracas - San Idrio",
	"Barracas de Belgrano - Rincon de Milberg",
	"Barracas de Belgrano - Estacion Terminal de Omnibus de Escobar"
};

const float TotalKilometrosRecorrido[] = { 31, 27.2, 49.7 };

const string ParadasDireccion[] = { 
	"Pedro de Lujan y Santa Maria del Buen Aire",
	"Av. Suarez y Gral Hornos",
	"Pte. Suarez y Av Hipolito Yrigoyen",
	"Junin y Av Las Heras",
	"Aav Santa Fe y Godoy Cruz",
	"Virrey Vertriz y Sucre",
	"Av Cabildo y Av Congreso",
	"Est. Transferencia Vicente Lopez",
	"Estacion Bartolome Mitre",
	"Av Santa Fe y Gral Alvear",
	"Av Centenario y Gral M.Belgrano",
	"Primera Junta y Av Tiscornia",
	"Av Cabildo y Av Gral Paz",
	"Au Panamericana y Laprida",
	"Au Panamericana y Manuel Ugarte",
	"Au Panamericana y Tomas Edison",
	"Au Panamericana y Av Marquez",
	"Au Panamericana y Uruguay",
	"Acceso Norte y Ruta Nacional 197",
	"Liniers y Santa Maria de las Conchas",
	"Ruta Provincial 27 y Ugarte",
	"Liniers y Ruta Provincial 24",
	"Ruta Provincial 24 y Boulogne Sur Mer",
	"Constituyrntes y Cervantes",
	"Barrio Mutual",
	"Av Gral J.D Peron y Av Benavidez",
	"Au Panamericana y VillaNueva",
	"Terminal Escobar"
};

#pragma region Inicializacion de los recorridos y paradas

	/// <summary>
	/// Constructor de la clase Lista Global Paradas 
	/// </summary>
	/// <param name="ListaGlobalParadas"></param>
void GenerarParadas(cListaParadas* ListaGlobalParadas);

	/// <summary>
	/// Agrega las Paradas a los recorridos
	/// </summary>
	/// <param name="RecorridoA"></param>
	/// <param name="RecorridoB"></param>
	/// <param name="RecorridoC"></param>
	/// <param name="ListaGlobalParadas"></param>
void AgregarParadasRecorrido(cRecorrido* RecorridoA, cRecorrido* RecorridoB, cRecorrido* RecorridoC, cListaParadas* ListaGlobalPardas);

#pragma endregion

#pragma region Inicializacion de los Colectivos

#pragma endregion