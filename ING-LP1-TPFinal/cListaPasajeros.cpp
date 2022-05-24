#include "cListaPasajeros.h"

cListaPasajeros::cListaPasajeros():cListaTemplate<cPasajero>() {

}

cListaPasajeros::cListaPasajeros(unsigned int TamMax, bool borrar):cListaTemplate<cPasajero>(TamMax,borrar) {

}

cListaPasajeros::~cListaPasajeros(){

}

cPasajero* cListaPasajeros::QuitarSillaRuedas(){
	for (unsigned int i = 0; i < CantidadActual; i++) {
		if (Array[i]->GetSillaDeRuedas()==true) {
			return Quitar(Array[i]);
		}
	}
	return NULL;
}

ostream& operator<<(ostream& os, const cListaPasajeros* ListaPasajeros) {
	os << "Lista de Pasajeros" << endl;

	return os;
}