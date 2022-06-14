#include "cColectivo.h"

unsigned long int cColectivo::CantidadDeColectivos = 0;

cColectivo::cColectivo() : IDColectivo(to_string(++CantidadDeColectivos)) {
	this->EstadoOperaativo = true;
	this->SistemaDePagos = new cSistemaDePagos();
	this->ListaPasajeros = new cListaPasajeros(50, true);
	this->Colectivero = NULL;
	this->Recorrido = NULL;
	this->FechaUltimoMantenimiento = NULL;
	this->PosDelRecorrido = 0;
}

cColectivo::cColectivo(cRecorrido* RecorridoAsignado) : IDColectivo(to_string(++CantidadDeColectivos)) {
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
	/*if (Colectivero != NULL) {
		delete Colectivero;
	}*/
	if (FechaUltimoMantenimiento != NULL) {
		delete FechaUltimoMantenimiento;
	}
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

cSistemaDePagos* cColectivo::GetSistemaDePagos() const {
	return SistemaDePagos;
}

string cColectivo::GetGPS() const {
	return GPS;
}

void cColectivo::SetNuevoRecorrido(cRecorrido* NuevoRecorrido) {
	this->Recorrido = NuevoRecorrido;
}

void cColectivo::SetColectivero(cColectivero* Colectivero) {
	this->Colectivero = Colectivero;
}

void  cColectivo::SetFechaMantenimiento(cFecha* Fecha) {
	this->FechaUltimoMantenimiento = Fecha;
}

void cColectivo::AvanzarRecorrido() {
	this->PosDelRecorrido++;
	BajarPasajeros((*Recorrido->GetListaParadas())[PosDelRecorrido]->GetNombreParada());
	// TODO : Crear otro metodo para subir al pasajero
	for (unsigned int Pos = 0; Pos < (*Recorrido->GetListaParadas())[PosDelRecorrido]->GetListaPasajeros()->GetCantidadActual(); Pos++) {
		if (ListaPasajeros->GetCantidadActual() < ListaPasajeros->GetCantidadMaxima()) {
			//TODO : usar el metodo PasajeroSubeColectivo de cParada
			//SubirPasajeros((*Recorrido->GetListaParadas())[PosDelRecorrido]->GetListaPasajeros()->QuitarSillaRuedas());
			cPasajero* PasajeroAux = (*Recorrido->GetListaParadas())[PosDelRecorrido]->PasajeroSubeColectivo();
			if (PasajeroAux != NULL) {
				SubirPasajeros(PasajeroAux);
			}
			else {
				//Ya subieron todos los pasajeros, colectivo continua su recorrido
			}

		}
	}
	/*
	for (unsigned int Pos = 0; Pos < (*Recorrido->GetListaParadas())[PosDelRecorrido]->GetListaPasajeros()->GetCantidadActual(); Pos++) {
		if (ListaPasajeros->GetCantidadActual() < ListaPasajeros->GetCantidadMaxima()) {
			//TODO : usar el metodo PasajeroSubeColectivo de cParada
			SubirPasajeros((*Recorrido->GetListaParadas())[PosDelRecorrido]->GetListaPasajeros()->QuitarPasajero());
		}
	}
	*/
}

cPasajero* cColectivo::BajarPasajeros(string NombreParadaActual) {
	for (unsigned int Pos = 0; Pos < ListaPasajeros->GetCantidadActual(); Pos++) {
		if ((*ListaPasajeros)[Pos]->GetDestino() == NombreParadaActual) {
			return ListaPasajeros->Quitar((*ListaPasajeros)[Pos]);
			//TODO : Hacer delete del pasajero una vez que este llega al destino
		}
	}
	return NULL;
}

bool cColectivo::SubirPasajeros(cPasajero* Pasajero) {

	//TODO : Hacer metodo virtual para los colectivos autonomos no dependan del colectivero para cobrar pasaje

	const string InicioPasajero = (*Recorrido->GetListaParadas())[PosDelRecorrido]->GetNombreParada();

	const string DestinoPasajero = Colectivero->CargarDestinoPasajero(Pasajero->GetDestino());

	const unsigned int CantidadParadas = Recorrido->CantidadDeParadasEntreDestinos(InicioPasajero, DestinoPasajero);

	bool EstadoPasajero = SistemaDePagos->GenerarViaje(InicioPasajero, DestinoPasajero, CantidadParadas, Pasajero->GetTarjetaPasajero());

	if (EstadoPasajero == true) {
		*(ListaPasajeros)+Pasajero;
		return true;
	}
	else {
		return false;
	}
}

void cColectivo::Averia() {
	//TODO : solicitud de enviar a un colectivo con poca gente a su ubicacion para llevar a los pasajeros
	//TODO : enviar colectivo al taller
	//TODO : una vez reparado asignar una fecha de mantenimiento (en cSimulador)
	this->EstadoOperaativo = false;
}

void cColectivo::ActualizarGPS() {
	if (Recorrido != NULL) {
		this->GPS = (*Recorrido->GetListaParadas())[PosDelRecorrido]->GetNombreParada();
	}
}

void cColectivo::operator+(cPasajero* Pasajero) {
	SubirPasajeros(Pasajero);
}

cPasajero* cColectivo::operator-(cPasajero* Pasajero) {
	return BajarPasajeros(Pasajero->GetDestino());
}

string cColectivo::ToStringColectivo() const {
	return 
		"\n\nID Colectivo: " + IDColectivo +
		"\nCantidad de Pasajeros: " + to_string(SistemaDePagos->GetCantidadDePasajeros()) +
		"\nMonto colectado: " + to_string(SistemaDePagos->GetColectaDelDia());
}

bool cColectivo::operator==(const cColectivo& OtroColectivo) {
	if (IDColectivo == OtroColectivo.GetIDColectivo()) {
		return true;
	}
	else
		return false;
}