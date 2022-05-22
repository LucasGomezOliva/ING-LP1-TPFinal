#include "cTarjeta.h"

unsigned long int cTarjeta::CantidadDeTarjetasCreadas = 0;

cTarjeta::cTarjeta() {
	this->CantidadDeTarjetasCreadas++;
	this->NumeroTarjeta = CantidadDeTarjetasCreadas;
	this->Saldo = 0;
}

cTarjeta::cTarjeta(float Saldo) {
	this->CantidadDeTarjetasCreadas++;
	this->NumeroTarjeta = CantidadDeTarjetasCreadas;
	this->Saldo = Saldo;
}

cTarjeta::~cTarjeta() {

}

float cTarjeta::CargaDeSaldo(float SaldoAgregar) {
	this->Saldo = Saldo + SaldoAgregar;
	return Saldo;
}

float cTarjeta::DescuentoSalto(float Cargo) {
	this->Saldo = Saldo - Cargo;
	return Saldo;
}

string cTarjeta::ToStringTarjeta()const {
	return "Numero de Tarjeta:" + to_string(NumeroTarjeta) +
		"Saldo:" + to_string(Saldo);
}

void cTarjeta::Imprimir()const {

}