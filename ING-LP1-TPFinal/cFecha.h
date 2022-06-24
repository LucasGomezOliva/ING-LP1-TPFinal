#pragma once
#include <iostream>
#include <ctime>
#include <string>
using namespace std;
class cFecha
{
private:

	tm fecha;

public:

#pragma region Constructores y destructores

	/// <summary>
	/// Constructor por defecto de la clase Fecha 
	/// </summary>
	cFecha();

	/// <summary>
	/// Constructor de la clase Fecha 
	/// </summary>
	/// <param name="dia"></param>
	/// <param name="mes"></param>
	/// <param name="anio"></param>
	/// <param name="hora"></param>
	/// <param name="minutos"></param>
	cFecha(unsigned int dia, unsigned int mes, unsigned int anio, unsigned int hora, unsigned int minutos);

	/// <summary>
	/// Destructor de la clase fecha
	/// </summary>
	~cFecha();

#pragma endregion

#pragma region Getter y Setter 

	unsigned int getDia() const;

	unsigned int getMes() const;

	unsigned int getAnio() const;

	unsigned int getHora() const;

	unsigned int getMinutos() const;

#pragma endregion

#pragma region Metodos

	bool CompararFechas(cFecha* fecha);

	string to_stringFecha() const ;

	void imprimir() const ;

	friend istream& operator>>(istream& input, cFecha& Fecha);
	friend ostream& operator<<(ostream& os, const cFecha* Fecha);
	bool operator!=(cFecha* Fecha);
	bool operator==(cFecha* Fecha);
	bool operator > (cFecha* Fecha);
	bool operator < (cFecha* Fecha);
	
#pragma endregion
};

