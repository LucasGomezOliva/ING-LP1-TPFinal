#include "cColectivero.h"

unsigned int cColectivero::CantidadDeColectiveros = 0;

cColectivero::cColectivero():cPersona(), Legajo(to_string(++CantidadDeColectiveros)) {
	
}

cColectivero::cColectivero(string Nombre, string DNI):cPersona(Nombre,DNI), Legajo(to_string(++CantidadDeColectiveros)) {
	
}

cColectivero::~cColectivero(){

}

string cColectivero::GetLegajo()const { 
	return Legajo; 
}

string cColectivero::CargarDestinoPasajero(string DestinoPasajero){
	return "123";
}

string cColectivero::ToStringColectivero()const {
	string aux;
	aux = 
		"\nNombre:" + Nombre + 
		"\nDNI:" + DNI + 
		"\nLegajo:" + Legajo;
	return aux;
}

ostream& operator<<(ostream& os, const cColectivero* Colectivero) {
	os << Colectivero->ToStringColectivero();
	return os;
}

bool cColectivero::operator==(const cColectivero& OtroColectivo) {
	if (DNI == OtroColectivo.GetDNI()) {
		return true;
	}
	else
		return false;
}