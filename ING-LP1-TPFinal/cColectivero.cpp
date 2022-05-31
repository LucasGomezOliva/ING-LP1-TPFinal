#include "cColectivero.h"

unsigned int cColectivero::CantidadDeColectiveros = 0;

cColectivero::cColectivero():cPersona() {
	this->Legajo = to_string(CantidadDeColectiveros);
	CantidadDeColectiveros++;
}

cColectivero::cColectivero(string Nombre, string DNI):cPersona(Nombre,DNI) {
	this->Legajo = to_string(CantidadDeColectiveros);
	CantidadDeColectiveros++;
}

cColectivero::~cColectivero(){

}

string cColectivero::CargarDestinoPasajero(string DestinoPasajero){
	return "123";
}
