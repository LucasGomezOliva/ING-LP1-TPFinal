#include "cColectivo.h"

unsigned long int cColectivo::CantidadDeColectivos = 0;

cColectivo::cColectivo() {
	this->CantidadDeColectivos++;
	this->IDColectivo = "";
	this->EstadoOperaativo = true;
}

cColectivo::cColectivo(string IDColectivo) {
	this->CantidadDeColectivos++;
	this->IDColectivo = IDColectivo;
	this->EstadoOperaativo = true;
}

cColectivo::~cColectivo() {

}

cPasajero* cColectivo::BajarPasajeros(string NombreParada) {
	//return pasajero
	return NULL;
}

bool cColectivo::SubirPasajeros(cPasajero* Pasajero) {
	return true;
}

void cColectivo::Averia() {
	this->EstadoOperaativo = false;
}

string cColectivo::GetIDColectivo() const {
	return IDColectivo;
}

bool cColectivo::GetEstadoOperativo() const {
	return EstadoOperaativo;
}

void cColectivo::operator+(cPasajero* Pasajero) {
	SubirPasajeros(Pasajero);
}

cPasajero* cColectivo::operator-(cPasajero* Pasajero) {
	return BajarPasajeros(Pasajero->GetDestino());

}

string cColectivo::ToStringColectivo() {
	return "ID Colectivo" + IDColectivo;
}