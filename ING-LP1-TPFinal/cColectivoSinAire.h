#pragma once
#include "cColectivo.h"
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
	/// <param name="IDColectivo"></param>
	/// <param name="RecorridoAsignado"></param>
	cColectivoSinAire(string IDColectivo, cRecorrido* RecorridoAsignado);

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

