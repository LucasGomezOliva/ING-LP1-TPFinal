#include "cColectivoConAire.h"
cColectivoConAire::cColectivoConAire(): cColectivo() {
	this->AireAcondicionado = false;
}

cColectivoConAire::cColectivoConAire(string IDColectivo): cColectivo(IDColectivo) {
	this->AireAcondicionado = false;
}

cColectivoConAire::~cColectivoConAire() {

}

void cColectivoConAire::EncenderAire() {
	this->AireAcondicionado = true;
}

void cColectivoConAire::ApagarAire() {
	this->AireAcondicionado = false;
}

string cColectivoConAire::ToStringColectivoConAire() {
	return "123";
}

void cColectivoConAire::Imprimir() {

}