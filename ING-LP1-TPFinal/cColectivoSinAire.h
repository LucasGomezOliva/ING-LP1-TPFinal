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

	bool SubirPasajeros(cPasajero* Pasajero);

	string ToStringColectivoSinAire();
	void Imprimir();

#pragma endregion

#pragma region Sobrecarga Operadores

	friend istream& operator>>(istream& input, cColectivoSinAire& Colectivo);

	friend ostream& operator<<(ostream& os, const cColectivoSinAire* Colectivo);

#pragma endregion
};

