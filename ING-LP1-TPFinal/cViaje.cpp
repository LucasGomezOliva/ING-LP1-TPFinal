#include "cViaje.h"

unsigned int cViaje::CantidadDeViajesCreados = 0;

cViaje::cViaje() : IDViaje(to_string(++CantidadDeViajesCreados)), Inicio(""), Destino(""), CostoDelViaje(0) {
	
}

cViaje::cViaje(string Inicio, string Destino, float CostoDelViaje) : IDViaje(to_string(++CantidadDeViajesCreados)), Inicio(Inicio), Destino(Destino), CostoDelViaje(CostoDelViaje) {
	
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