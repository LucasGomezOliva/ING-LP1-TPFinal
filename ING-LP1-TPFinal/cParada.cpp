#include "cParada.h"
cParada::cParada() {
	this->IDParada = "";
	this->NombreParada = "";
	this->Direccion = "";
}

cParada::cParada(string IDParada, string NombreParada, string Direccion) {
	this->IDParada = IDParada;
	this->NombreParada = NombreParada;
	this->Direccion = Direccion;
}

cParada::~cParada() {

}

ostream& operator<<(ostream& os, const cParada* Parada) {
	os << Parada->ToStringParada();
	return os;
}

string cParada::ToStringParada() const {
	return "ID Parada:" + IDParada +
		"NombreParada:" + NombreParada +
		"Direccion:" + Direccion;
}

void cParada::imprimir() const {
	
}