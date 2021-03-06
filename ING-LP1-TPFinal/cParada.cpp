#include "cParada.h"
unsigned int cParada::CantidadDeParadasCreadas = 0;
cParada::cParada() : IDParada(to_string(++CantidadDeParadasCreadas)), NombreParada(""), Direccion("") {
	this->ListaPasajeros = new cListaPasajeros();
}

cParada::cParada(string NombreParada, string Direccion) : IDParada(to_string(++CantidadDeParadasCreadas)), NombreParada(NombreParada), Direccion(Direccion) {
	this->ListaPasajeros = new cListaPasajeros(100, true);
}

cParada::~cParada() {
	delete ListaPasajeros;
}

cListaPasajeros* cParada::GetListaPasajeros() const {
	return ListaPasajeros;
}

string cParada::GetIDParada() const {
	return IDParada;
}

string cParada::GetNombreParada() const {
	return NombreParada;
}

cPasajero* cParada::PasajeroSubeColectivo() {
	cPasajero* PasajeroAux = ListaPasajeros->QuitarSillaRuedas();
	if (PasajeroAux == NULL) {
		return ListaPasajeros->QuitarPasajero();
	}
	else{
		return PasajeroAux;
	}
}

string cParada::ToStringParada() const {
	return 
		"\nID Parada:" + IDParada +
		"\nNombre de la Parada: " + NombreParada +
		"\nDireccion:" + Direccion;
}

void cParada::imprimir() const {
	cout << ToStringParada();
}

ostream& operator<<(ostream& os, const cParada* Parada) {
	os << Parada->ToStringParada();
	return os;
}

bool cParada::operator==(const cParada& OtraParada) {
	if (IDParada == OtraParada.GetIDParada())
		return true;
	else
		return false;
}