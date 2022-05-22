#pragma once
#include<string>
#include<iostream>
using namespace std;
class cParada
{
private:
	string IDParada;
	string NombreParada;
	string Direccion;
	//cListaPasajeros* ListaPasajeros = NULL;
public:
	
#pragma region Constructores y destructores

	cParada();
	cParada(string IDParada, string NombreParada, string Direccion);
	~cParada();

#pragma endregion

#pragma region Getter y setters

#pragma endregion

#pragma region Metodos

	string ToStringParada() const;
	void imprimir() const;

#pragma endregion

#pragma region Sobrecarga Operadores

	friend ostream& operator<<(ostream& os, const cParada* Parada);

#pragma endregion

};

