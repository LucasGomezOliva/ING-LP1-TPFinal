#include "cListaStrings.h"

cListaStrings::cListaStrings(unsigned int TamMAX) {
	Array = new string * [TamMAX];
	for (unsigned int i = 0; i < TamMAX; i++) {
		Array[i] = NULL;
	}
	this->TamMAX = TamMAX;
	CantidadActual = 0;
}

cListaStrings::~cListaStrings(){
	if (Array != NULL){
		delete[] Array;
	}
}

bool cListaStrings::Agregar(string* StringLista) {
	if (CantidadActual < TamMAX)
		Array[CantidadActual++] = StringLista;
	else throw new exception("No se puede agregar");;
	return true;
}

string* cListaStrings::QuitarenPos(unsigned int pos) {
	if (pos >= CantidadActual)throw new exception("Posicion no disponible");
	string* aux = Array[pos];
	for (unsigned int i = 0; i < CantidadActual - 1; i++) {
		Array[i] = Array[i + 1];
	}
	Array[CantidadActual - 1] = NULL;
	CantidadActual--;
	return aux;
}

string* cListaStrings::getItem(unsigned int pos){
	if (pos < CantidadActual)
		return Array[pos];
	else return NULL;
}

unsigned int cListaStrings::GetCantidadActual() {
	return CantidadActual;
}