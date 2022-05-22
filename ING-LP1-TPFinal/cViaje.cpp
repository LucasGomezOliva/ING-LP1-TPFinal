#include "cViaje.h"
cViaje::cViaje() {
	this->Inicio = "";
	this->Destino = "";
	this->CostoDelViaje = 0;
}

cViaje::cViaje(string Inicio, string Destino, float CostoDelViaje) {
	this->Inicio = Inicio;
	this->Destino = Destino;
	this->CostoDelViaje = CostoDelViaje;
}

cViaje::~cViaje() {

}

string cViaje::ToStringViaje() const {
	return "Inicio:" + Inicio +
		"Destino:" + Destino +
		"Costo DelViaje:" + to_string(CostoDelViaje);
}

void cViaje::Imprimir() const {
	cout << ToStringViaje();
}