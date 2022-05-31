#pragma once
#include "cColectivo.h"
using namespace std;
class cColectivoSinAire :public cColectivo
{
private:

public:
	
#pragma region Constructores y destructores

	/// <summary>
	/// Constructor por defecto de la clase ColectivoSinAire 
	/// </summary>
	cColectivoSinAire();

	/// <summary>
	/// Constructor de la clase ColectivoSinAire
	/// </summary>
	/// <param name="RecorridoAsignado"></param>
	cColectivoSinAire(cRecorrido* RecorridoAsignado);

	/// <summary>
	/// Destructor de la clase ColectivoSinAire 
	/// </summary>
	~cColectivoSinAire();

#pragma endregion

#pragma region Getter y setters

#pragma endregion

#pragma region Metodos

	string ToStringColectivoSinAire();
	void Imprimir();

#pragma endregion

#pragma region Sobrecarga Operadores

#pragma endregion
};

