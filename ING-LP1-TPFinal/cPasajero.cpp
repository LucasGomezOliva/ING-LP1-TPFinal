#include "cPasajero.h"
cPasajero::cPasajero() : cPersona() {
	this->NombreParadaDestino = "";
	this->SillaDeRuedas = false;
	this->TarjetaPasajero = new cTarjeta();
}

cPasajero::cPasajero(string Nombre, string DNI, string NombreParadaDestino, bool SillaDeRuedas, float Saldo) : cPersona(Nombre,DNI) {
	this->NombreParadaDestino = NombreParadaDestino;
	this->SillaDeRuedas = SillaDeRuedas;
	this->TarjetaPasajero = new cTarjeta(Saldo);
}

cPasajero::~cPasajero() {
	delete TarjetaPasajero;
}

bool cPasajero::GetSillaDeRuedas() const {
	return SillaDeRuedas;
}

string cPasajero::GetDestino()const {
	return NombreParadaDestino;
}

cTarjeta* cPasajero::GetTarjetaPasajero() const {
	return TarjetaPasajero;
}

string cPasajero::GetDNI() const {
	return DNI;
}

string cPasajero::ToStringPasajero() const {
	string aux=
		"\nNombre: " + Nombre +
		"\nDNI: " + DNI +
		"\nDestino: " + NombreParadaDestino +
		"\nDatos de Tarjeta: " + TarjetaPasajero->ToStringTarjeta();
	if (SillaDeRuedas == true) {
		aux += "\nSilla de ruedas: SI";
	}
	else
		aux += "\nSilla de ruedas: NO";
	return aux;
}

void cPasajero::imprimir() const {
	cout << ToStringPasajero();
}

ostream& operator<<(ostream& os, const cPasajero* Pasajero) {
	os << Pasajero->ToStringPasajero();
	return os;
}

bool cPasajero::operator==(const cPasajero& OtroPasajero) {
	if (DNI == OtroPasajero.GetDNI()) {
		return true;
	}
	else
		return false;
}