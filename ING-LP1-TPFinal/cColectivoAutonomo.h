#pragma once
#include "cColectivoConAire.h"
using namespace std;
class cColectivoAutonomo : public cColectivoConAire
{
private:

	unsigned int Bateria;

public:

#pragma region Constructores y destructores

	/// <summary>
	/// Constructor por defecto de la clase ColectivoAutonomo 
	/// </summary>
	cColectivoAutonomo();

	/// <summary>
	/// Destructor de la clase ColectivoAutonomo 
	/// </summary>
	~cColectivoAutonomo();

#pragma endregion

#pragma region Metodos

	bool SubirPasajeros(cPasajero* Pasajero);

	/// <summary>
	/// Carga Bateria del colectivo 
	/// </summary>
	void CargarBateria();

	/// <summary>
	/// Descarrga de la bateria del colectivo
	/// </summary>
	void DescargarBateria();

	friend istream& operator>>(istream& input, cColectivoAutonomo& Colectivo);

	friend ostream& operator<<(ostream& os, const cColectivoAutonomo* Colectivo);

#pragma endregion

};

