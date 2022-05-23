#pragma once
#include "cColectivo.h"
class cColectivoConAire :public cColectivo
{
private:
	bool AireAcondicionado;
public:
	
#pragma region Constructores y destructores

	cColectivoConAire();
	cColectivoConAire(string IDColectivo, cRecorrido* RecorridoAsignado);
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

