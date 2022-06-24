#include "cColectivoConAire.h"
cColectivoConAire::cColectivoConAire(): cColectivo() {
	this->AireAcondicionado = false;
}

cColectivoConAire::cColectivoConAire(cRecorrido* RecorridoAsignado): cColectivo(RecorridoAsignado) {
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
	return ToStringColectivo();
}

void cColectivoConAire::Imprimir() {

}