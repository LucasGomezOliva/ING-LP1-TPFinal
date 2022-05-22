#pragma once
#include<string>
#include<iostream>
using namespace std;
class cViaje
{
private:
	string Inicio;
	string Destino;
	float CostoDelViaje;
public:

#pragma region Constructores y destructores

	cViaje();
	cViaje(string Inicio, string Destino, float CostoDelViaje);
	~cViaje();

#pragma endregion

#pragma region Metodos

	string ToStringViaje() const;
	void Imprimir() const;

#pragma endregion
};

