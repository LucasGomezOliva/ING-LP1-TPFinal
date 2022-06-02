#pragma once
#include <iostream>
#include <string>
#include"cListaColectivos.h"
#include"cColectivoAcordeon.h"
#include"cColectivoAutonomo.h"
#include"cColectivoSinAire.h"
#include"../GenerardorRandoms/cGenerador.h"
using namespace std;

const unsigned int CantidadTotalColectivos = 20;

const unsigned int CantidadColectivosSinAire = 10;

const unsigned int CantidadColectivosAutonomos = 5;

const unsigned int CantidadColectivosAcordeon = 5;

const string CodigoRecorridos[] = { "A","B","C" };

const string NombreRecorridos[] = { 
	"Barracas - San Idrio",
	"Barracas de Belgrano - Rincon de Milberg",
	"Barracas de Belgrano - Estacion Terminal de Omnibus de Escobar"
};

const float TotalKilometrosRecorrido[] = { 31, (float) 27.2, (float) 49.7 };

const unsigned int CantidadTotalParadasRecorridoA = 12;

const unsigned int ParadasRecorridoA[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };

const unsigned int CantidadTotalParadasRecorridoB = 11;

const unsigned int ParadasRecorridoB[] = { 5, 6, 12, 13, 14, 15, 16, 17, 18, 19, 20 };

const unsigned int CantidadTotalParadasRecorridoC = 16;

const unsigned int ParadasRecorridoC[] = { 5, 6, 12, 13, 14, 15, 16, 17, 18, 21, 22, 23, 24, 25, 26, 27 };

const unsigned int CantidadTotalParadas = 28;

const string ParadasNombre[] = { 
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

const string ParadasDireccion[] = {
	"Direccion 1",
	"Direccion 2",
	"Direccion 3",
	"Direccion 4",
	"Direccion 5",
	"Direccion 6",
	"Direccion 7",
	"Direccion 8",
	"Direccion 9",
	"Direccion 10",
	"Direccion 11",
	"Direccion 12",
	"Direccion 13",
	"Direccion 14",
	"Direccion 15",
	"Direccion 16",
	"Direccion 17",
	"Direccion 18",
	"Direccion 19",
	"Direccion 20",
	"Direccion 21",
	"Direccion 22",
	"Direccion 23",
	"Direccion 24",
	"Direccion 25",
	"Direccion 26",
	"Direccion 27",
	"Direccion 28"
};

#pragma region Funciones

	/// <summary>
	/// Genera paradas y las agrega a la Lista Global Paradas 
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

	/// <summary>
	/// Genera colectivos y los agrega a la lista global de colectivos
	/// </summary>
	/// <param name="RecorridoA"></param>
void GenerarColectivos(cListaColectivos* ListaGlobalColectivos);

	/// <summary>
	/// Genera los colectiveros en cada colectivo siempre y cuando no sean ColectivosAutonomos
	/// </summary>
	/// <param name="ListaGlobalColectivos"></param>
	/// <param name="GeneradorRandoms"></param>
void GenerarAsignarColectiveros(cListaColectivos* ListaGlobalColectivos, cGenerador* GeneradorRandoms);

	/// <summary>
	/// Actualizacion de objetos
	/// </summary>
	/// <param name="ListaGlobalColectivos"></param>
	/// <param name="ListaGlobalPardas"></param>
	/// <param name="RecorridoA"></param>
	/// <param name="RecorridoB"></param>
	/// <param name="RecorridoC"></param>
	/// <param name="GeneradorRandoms"></param>
void ActualizarObjetos(cListaColectivos* ListaGlobalColectivos, cListaParadas* ListaGlobalParadas, cRecorrido* RecorridoA, cRecorrido* RecorridoB, cRecorrido* RecorridoC, cGenerador* GeneradorRandoms);

	/// <summary>
	/// Actualiza todos los colectivos (avanzan en su recorrido - suben y bajan pasajeros)
	/// </summary>
	/// <param name="ListaGlobalColectivos"></param>
void ActualizarColectivos(cListaColectivos* ListaGlobalColectivos);

	/// <summary>
	/// Actualiza todos los paradas (agrega nuevas personas a las mismas)
	/// </summary>
	/// <param name="ListaGlobalPardas"></param>
	/// <param name="RecorridoA"></param>
	/// <param name="RecorridoB"></param>
	/// <param name="RecorridoC"></param>
	/// <param name="GeneradorRandoms"></param>
void ActualizarParadas(cListaParadas* ListaGlobalParadas, cRecorrido* RecorridoA, cRecorrido* RecorridoB, cRecorrido* RecorridoC, cGenerador* GeneradorRandoms);

	/// <summary>
	/// Generar un destino random del pasajero dependiendo en la parada en la que se lo cree
	/// </summary>
	/// <param name="ParadaActual"></param>
	/// <param name="RecorridoA"></param>
	/// <param name="RecorridoB"></param>
	/// <param name="RecorridoC"></param>
	/// <returns>string</returns>
string GeneradorDestinoRandom(cParada* ParadaActual, cRecorrido* RecorridoA, cRecorrido* RecorridoB, cRecorrido* RecorridoC);

	/// <summary>
	/// Actualiza los GPS de todos los colectivos
	/// </summary>
	/// <param name="ListaGlobalColectivos"></param>
void ActualizarColectivosGPS(cListaColectivos* ListaGlobalColectivos);

	/// <summary>
	/// Indica el resumen del dia de cada colectivo y el total
	/// </summary>
	/// <param name="ListaGlobalColectivos"></param>
void ResumenDelDia(cListaColectivos* ListaGlobalColectivos);

#pragma endregion