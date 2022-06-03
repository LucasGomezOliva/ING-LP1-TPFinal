#include "cColectivo.h"

unsigned long int cColectivo::CantidadDeColectivos = 0;

cColectivo::cColectivo() {
	this->CantidadDeColectivos++;
	this->IDColectivo = to_string(CantidadDeColectivos);
	this->EstadoOperaativo = true;
	this->SistemaDePagos = new cSistemaDePagos();
	this->ListaPasajeros = new cListaPasajeros(50, true);
	this->Colectivero = NULL;
	this->Recorrido = NULL;
	this->FechaUltimoMantenimiento = NULL;
	this->PosDelRecorrido = 0;
}

cColectivo::cColectivo(cRecorrido* RecorridoAsignado) {
	this->CantidadDeColectivos++;
	this->IDColectivo = to_string(CantidadDeColectivos);
	this->EstadoOperaativo = true;
	this->SistemaDePagos = new cSistemaDePagos();
	this->ListaPasajeros = new cListaPasajeros(50, true);
	this->Recorrido = RecorridoAsignado;
	this->Colectivero = NULL;
	this->FechaUltimoMantenimiento = NULL;
	this->PosDelRecorrido = 0;
}

cColectivo::~cColectivo() {
	delete SistemaDePagos;
	delete ListaPasajeros;
	if (Colectivero != NULL) {
		delete Colectivero;
	}
}

void cColectivo::AvanzarRecorrido() {
	this->PosDelRecorrido++;

	BajarPasajeros((*Recorrido->GetListaParadas())[PosDelRecorrido]->GetNombreParada());

	for (unsigned int Pos = 0; Pos < (*Recorrido->GetListaParadas())[PosDelRecorrido]->GetListaPasajeros()->GetCantidadActual(); Pos++) {
		if (ListaPasajeros->GetCantidadActual() < ListaPasajeros->GetCantidadMaxima()) {
			SubirPasajeros((*Recorrido->GetListaParadas())[PosDelRecorrido]->GetListaPasajeros()->QuitarSillaRuedas());
		}
	}
	for (unsigned int Pos = 0; Pos < (*Recorrido->GetListaParadas())[PosDelRecorrido]->GetListaPasajeros()->GetCantidadActual(); Pos++) {
		if (ListaPasajeros->GetCantidadActual() < ListaPasajeros->GetCantidadMaxima()) {
			SubirPasajeros((*Recorrido->GetListaParadas())[PosDelRecorrido]->GetListaPasajeros()->QuitarPasajero());
		}
	}
}

cPasajero* cColectivo::BajarPasajeros(string NombreParadaActual) {
	for (unsigned int Pos = 0; Pos < ListaPasajeros->GetCantidadActual(); Pos++) {
		if ((*ListaPasajeros)[Pos]->GetDestino() == NombreParadaActual) {
			return ListaPasajeros->Quitar((*ListaPasajeros)[Pos]);
		}
	}
	return NULL;
}

bool cColectivo::SubirPasajeros(cPasajero* Pasajero) {

	bool EstadoPasajero = SistemaDePagos->GenerarViaje("ParadaActual", Pasajero->GetDestino(), Recorrido->CantidadDeParadasEntreDestinos("ParadaActual", Pasajero->GetDestino()), Pasajero->GetTarjetaPasajero());
	if (EstadoPasajero == true) {
		//agregar pasajero a la lista
		*(ListaPasajeros) + Pasajero;
		//pasajero sube al colectivo
		return true;
	}
	else {
		//pasajero no cumple con el saldo requerido
		//no sube al colectivo
		return false;
	}
}

void cColectivo::Averia() {
	this->EstadoOperaativo = false;
}

cRecorrido* cColectivo::GetRecorrido() const {
	return Recorrido;
}

string cColectivo::GetIDColectivo() const {
	return IDColectivo;
}

bool cColectivo::GetEstadoOperativo() const {
	return EstadoOperaativo;
}

void cColectivo::SetNuevoRecorrido(cRecorrido* NuevoRecorrido) {
	this->Recorrido = NuevoRecorrido;
}

void cColectivo::SetColectivero(cColectivero* Colectivero) {
	this->Colectivero = Colectivero;
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

bool cColectivo::operator==(const cColectivo& OtroColectivo) {
	if (IDColectivo == OtroColectivo.GetIDColectivo()) {
		return true;
	}
	else
		return false;
}