#include "cColectivero.h"

unsigned int cColectivero::CantidadDeColectiveros = 0;

cColectivero::cColectivero():cPersona(), Legajo(to_string(++CantidadDeColectiveros)) {
	
}

cColectivero::cColectivero(string Nombre, string DNI):cPersona(Nombre,DNI), Legajo(to_string(++CantidadDeColectiveros)) {
	
}

cColectivero::~cColectivero(){

}

string cColectivero::CargarDestinoPasajero(string DestinoPasajero){
	return "123";
}
