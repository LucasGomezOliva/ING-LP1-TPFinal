#pragma once
#include "cColectivo.h"
using namespace std;
class cColectivoConAire :public cColectivo
{
private:
	bool AireAcondicionado;
public:
	
#pragma region Constructores y destructores

	/// <summary>
	/// Constructor por defecto de la clase ColectivoConAire 
	/// </summary>
	cColectivoConAire();

	/// <summary>
	/// Constructor de la clase ColectivoConAire
	/// </summary>
	/// <param name="IDColectivo"></param>
	/// <param name="RecorridoAsignado"></param>
	cColectivoConAire(string IDColectivo, cRecorrido* RecorridoAsignado);

	/// <summary>
	/// Destructor de la clase ColectivoConAire 
	/// </summary>
	~cColectivoConAire();

#pragma endregion

#pragma region Getter y setters

#pragma endregion

#pragma region Metodos

	void EncenderAire();

	void ApagarAire();

	string ToStringColectivoConAire();

	void Imprimir();

#pragma endregion

#pragma region Sobrecarga Operadores

#pragma endregion
};

