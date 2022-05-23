#include "cSistemaDePagos.h"

cSistemaDePagos::cSistemaDePagos(){
	this->ColectaDelDia = 0;
	this->CantidadDePasajeros = 0;
}

cSistemaDePagos::~cSistemaDePagos(){
}

float cSistemaDePagos::GetColectaDelDia() const {
	return ColectaDelDia;
}

unsigned int cSistemaDePagos::GetCantidadDePasajeros() const {
	return CantidadDePasajeros;
}

bool cSistemaDePagos::GenerarViaje(string Inicio, string Destino, int CantidadDeParadas, cTarjeta* TarjetaPasajero){
	float MontoDelViaje = 0;
	MontoDelViaje = CantidadDeParadas * PrecioPorParada;
	if (MontoDelViaje <= TarjetaPasajero->GetSaldo()) {
		TarjetaPasajero->DescuentoSalto(MontoDelViaje);
		TarjetaPasajero->AgregarViajeLista(new cViaje(Inicio, Destino, MontoDelViaje));
		return true;
	}
	else{
		return false;
	}
}
