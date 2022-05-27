#pragma once
#include "cListaTemplate.h"
#include"cViaje.h"
using namespace std;
class cListaViajes : public cListaTemplate<cViaje>
{
public:

	/// <summary>
	/// Constructor por defecto de la clase ListaViajes
	/// </summary>
	cListaViajes();

	/// <summary>
	/// Constructor de la clase ListaViajes
	/// </summary>
	/// <param name="TamMax"></param>
	/// <param name="borrar"></param>
	cListaViajes(unsigned int TamMax, bool borrar);

	/// <summary>
	/// Destructor de la clase ListaViajes
	/// </summary>
	~cListaViajes();
};

