#pragma once
#include "cColectivoConAire.h"
using namespace std;
class cColectivoAcordeon :public cColectivoConAire
{
private:

public:

#pragma region Constructores y destructores

	/// <summary>
	/// Constructor por defecto de la clase ColectivoAcordeon
	/// </summary>
	cColectivoAcordeon();

	/// <summary>
	/// Deestructor de la clase ColectivoAcordeon 
	/// </summary>
	~cColectivoAcordeon();

#pragma endregion

#pragma region Getter y setters

#pragma endregion

#pragma region Metodos

	bool SubirPasajeros(cPasajero* Pasajero);

#pragma endregion

#pragma region Sobrecarga Operadores

	friend istream& operator>>(istream& input, cColectivoAcordeon& Colectivo);

	friend ostream& operator<<(ostream& os, const cColectivoAcordeon* Colectivo);

#pragma endregion

};

