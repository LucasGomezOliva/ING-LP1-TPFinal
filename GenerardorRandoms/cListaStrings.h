#pragma once
#include <string>
using namespace std;

class cGenerador;

class cListaStrings
{
protected:
	string** Array;
	unsigned int CantidadActual;
	unsigned int TamMAX;
public:
	friend class cGenerador;
	cListaStrings(unsigned int TamMAX = 500);
	~cListaStrings();
	bool Agregar(string* StringLista);
	string* QuitarenPos(unsigned int pos);
	string* getItem(unsigned int pos);
	unsigned int GetCantidadActual();
};

