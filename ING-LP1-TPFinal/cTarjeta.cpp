#include "cTarjeta.h"

unsigned long int cTarjeta::CantidadDeTarjetasCreadas = 0;

cTarjeta::cTarjeta() : NumeroTarjeta(to_string(++CantidadDeTarjetasCreadas)) {
	this->Saldo = 0;
	this->ListaDeViajesRealizados = new cListaViajes(100, true);
}

cTarjeta::cTarjeta(float Saldo) : NumeroTarjeta(to_string(++CantidadDeTarjetasCreadas)) {
	this->Saldo = Saldo;
	this->ListaDeViajesRealizados = new cListaViajes(100, true);
}

cTarjeta::~cTarjeta() {
	delete ListaDeViajesRealizados;
}
float cTarjeta::GetSaldo() const {
	return Saldo;
}
float cTarjeta::CargaDeSaldo(float SaldoAgregar) {
	this->Saldo = Saldo + SaldoAgregar;
	return Saldo;
}

float cTarjeta::DescuentoSalto(float Cargo) {
	this->Saldo = Saldo - Cargo;
	return Saldo;
}

void cTarjeta::AgregarViajeLista(cViaje* NuevoViaje) {
	ListaDeViajesRealizados->Agregar(NuevoViaje);
}

string cTarjeta::ToStringTarjeta()const {
	return 
		"\nNumero de Tarjeta:" + NumeroTarjeta +
		"\nSaldo:" + to_string(Saldo);
}

void cTarjeta::Imprimir()const {

}