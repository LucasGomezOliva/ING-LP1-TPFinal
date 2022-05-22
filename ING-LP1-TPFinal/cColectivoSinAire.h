#pragma once
#include "cColectivo.h"
class cColectivoSinAire :public cColectivo
{
private:

public:
	
#pragma region Constructores y destructores

	cColectivoSinAire();
	cColectivoSinAire(string IDColectivo);
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

