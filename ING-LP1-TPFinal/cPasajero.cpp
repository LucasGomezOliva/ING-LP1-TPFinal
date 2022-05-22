#include "cPasajero.h"
cPasajero::cPasajero() {
	this->Nombre = "";
	this->DNI = 0;
	this->NombreParadaDestino = "";
	this->SillaDeRuedas = false;
	this->TarjetaPasajero = new cTarjeta();
}

cPasajero::cPasajero(string Nombre, unsigned int long DNI, string NombreParadaDestino, bool SillaDeRuedas, float Saldo) {
	this->Nombre = Nombre;
	this->DNI = DNI;
	this->NombreParadaDestino = NombreParadaDestino;
	this->SillaDeRuedas = SillaDeRuedas;
	this->TarjetaPasajero = new cTarjeta(Saldo);
}

cPasajero::~cPasajero() {
	delete TarjetaPasajero;
}

string cPasajero::GetDestino()const {
	return NombreParadaDestino;
}

string cPasajero::ToStringPasajero() const {
	return "Nombre" + Nombre +
		"DNI" + to_string(DNI) +
		"Destino" + NombreParadaDestino +
		"Datos de Tarjeta:" + TarjetaPasajero->ToStringTarjeta();
}

void cPasajero::imprimir() const {
	cout << ToStringPasajero();
}

ostream& operator<<(ostream& os, const cPasajero* Pasajero) {
	os << Pasajero->ToStringPasajero();
	return os;
}