#include "cColectivero.h"

cColectivero::cColectivero():cPersona() {

}

cColectivero::cColectivero(string Nombre, string DNI):cPersona(Nombre,DNI) {

}

cColectivero::~cColectivero(){

}

string cColectivero::CargarDestinoPasajero(string DestinoPasajero){
	return "123";
}
