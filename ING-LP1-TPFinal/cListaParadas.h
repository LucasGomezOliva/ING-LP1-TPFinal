#pragma once
#include "cListaTemplate.h"
#include "cParada.h"
class cRecorrido;
class cListaParadas : public cListaTemplate<cParada>
{
public:
	friend class cRecorrido;
#pragma region Constructores y destructores

	/// <summary>
	/// Constructor por defecto de la clase ListaParadas
	/// </summary>
	cListaParadas();

	/// <summary>
	/// Constructor de la clase ListaParadas 
	/// </summary>
	/// <param name="TamMax"></param>
	/// <param name="borrar"></param>
	cListaParadas(unsigned int TamMax, bool borrar);

	/// <summary>
	/// Destructor de la clase ListaParadas
	/// </summary>
	~cListaParadas();

#pragma endregion
};

