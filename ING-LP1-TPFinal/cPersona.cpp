#include "cPersona.h"

cPersona::cPersona(): Nombre(""), DNI("") {

}

cPersona::cPersona(string Nombre, string DNI) : Nombre(Nombre), DNI(DNI) {
	
}

cPersona::~cPersona(){

}

string cPersona::GetNombre()const {
	return Nombre;
}

string cPersona::GetDNI()const {
	return DNI;
}