#pragma once
#include"cListaTemplate.h"
#include"cColectivo.h"
using namespace std;

class cListaColectivos : public cListaTemplate<cColectivo>
{
public:

#pragma region Constructores y destructores

	/// <summary>
	/// Constructor por defecto de la clase ListaColectiovos 
	/// </summary>
	cListaColectivos();

	/// <summary>
	/// Constructor de la clase ListaColectiovos 
	/// </summary>
	/// <param name="TamMax"></param>
	/// <param name="borrar"></param>
	cListaColectivos(unsigned int TamMax, bool borrar);

	/// <summary>
	/// Destructor de la clase ListaColectiovos 
	/// </summary>
	~cListaColectivos();

#pragma endregion

#pragma region Metodos


#pragma endregion

#pragma region Sobrecarga Operadores

	//friend ostream& operator<<(ostream& os, const cListaColectiovos* ListaColectiovos);

#pragma endregion
};

