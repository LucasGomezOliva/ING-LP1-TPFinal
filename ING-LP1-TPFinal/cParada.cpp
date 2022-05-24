#include "cParada.h"
cParada::cParada() {
	this->IDParada = "";
	this->NombreParada = "";
	this->Direccion = "";
	this->ListaPasajeros = new cListaPasajeros();
}

cParada::cParada(string IDParada, string NombreParada, string Direccion) {
	this->IDParada = IDParada;
	this->NombreParada = NombreParada;
	this->Direccion = Direccion;
	this->ListaPasajeros = new cListaPasajeros(100, false);
}

cParada::~cParada() {
	delete ListaPasajeros;
}

string cParada::GetNombreParada() const {
	return NombreParada;
}

cPasajero* cParada::PasajeroSubeColectivo() {
	//Retornar primero los pasajeros con silla de ruedas
	return NULL;
}

string cParada::ToStringParada() const {
	return 
		"\nID Parada:" + IDParada +
		"\nNombreParada:" + NombreParada +
		"\nDireccion:" + Direccion;
}

void cParada::imprimir() const {
	
}

ostream& operator<<(ostream& os, const cParada* Parada) {
	os << Parada->ToStringParada();
	return os;
}