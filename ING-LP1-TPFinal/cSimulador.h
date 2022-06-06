#pragma once

#include"cListaColectivos.h"
#include"cColectivoAcordeon.h"
#include"cColectivoAutonomo.h"
#include"cColectivoSinAire.h"
#include"../GenerardorRandoms/cGenerador.h"
#include"DefinesSimulacion.h"

using namespace std;

class cSimulador
{

public:

#pragma region Constructores y destructores

	/// <summary>
	/// Constructor por defecto de la clase Simulador 
	/// </summary>
	cSimulador();

	/// <summary>
	/// Destructor de la clase Simulador 
	/// </summary>
	~cSimulador();

#pragma endregion

#pragma region Metodos

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
	string ResumenDelDia(cListaColectivos* ListaGlobalColectivos);

#pragma endregion

};

