#include "cViaje.h"

int cViaje::CantidadDeViajesCreados = 0;

cViaje::cViaje() {
	this->IDViaje = to_string(CantidadDeViajesCreados);
	this->Inicio = "";
	this->Destino = "";
	this->CostoDelViaje = 0;
	CantidadDeViajesCreados++;
}

cViaje::cViaje(string Inicio, string Destino, float CostoDelViaje) {
	this->IDViaje = to_string(CantidadDeViajesCreados);
	this->Inicio = Inicio;
	this->Destino = Destino;
	this->CostoDelViaje = CostoDelViaje;
	CantidadDeViajesCreados++;
}

cViaje::~cViaje() {

}

string cViaje::ToStringViaje() const {
	return 
		"\nInicio:" + Inicio +
		"\nDestino:" + Destino +
		"\nCosto DelViaje:" + to_string(CostoDelViaje);
}

void cViaje::Imprimir() const {
	cout << ToStringViaje();
}