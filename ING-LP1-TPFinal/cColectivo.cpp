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
	this->GPS = "";
	this->Sentido = eSentidoRecorrido::Arriba;
}

cColectivo::cColectivo(cRecorrido* RecorridoAsignado) : IDColectivo(to_string(++CantidadDeColectivos)) {
	this->EstadoOperaativo = true;
	this->SistemaDePagos = new cSistemaDePagos();
	this->ListaPasajeros = new cListaPasajeros(50, true);
	this->Recorrido = RecorridoAsignado;
	this->Colectivero = NULL;
	this->FechaUltimoMantenimiento = NULL;
	this->PosDelRecorrido = 0;
	this->GPS = "";
	this->Sentido = eSentidoRecorrido::Arriba;
}

cColectivo::~cColectivo() {
	delete SistemaDePagos;
	delete ListaPasajeros;
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

unsigned int cColectivo::GetPosicionRecorrido() const {
	return PosDelRecorrido;
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

	if (Sentido == eSentidoRecorrido::Arriba) {
		this->PosDelRecorrido++;
	}
	if (Sentido == eSentidoRecorrido::Abajo) {
		this->PosDelRecorrido--;
	}

	cout << (*Recorrido->GetListaParadas())[PosDelRecorrido]->GetNombreParada() << endl;

	BajarPasajeros((*Recorrido->GetListaParadas())[PosDelRecorrido]->GetNombreParada());

	for (unsigned int PosPasajerosParada = 0; PosPasajerosParada < (*Recorrido->GetListaParadas())[PosDelRecorrido]->GetListaPasajeros()->GetCantidadActual(); PosPasajerosParada++) {
		if (ListaPasajeros->GetCantidadActual() < ListaPasajeros->GetCantidadMaxima()) {
			if ((*(*Recorrido->GetListaParadas())[PosDelRecorrido]->GetListaPasajeros())[PosPasajerosParada]->GetSillaDeRuedas() == true) {
				if (true == ControlSentidoPasajero((*(*Recorrido->GetListaParadas())[PosDelRecorrido]->GetListaPasajeros())[PosPasajerosParada])) {
					cPasajero* PasajeroAux = ((*Recorrido->GetListaParadas())[PosDelRecorrido]->GetListaPasajeros()->Quitar(
						(*(*Recorrido->GetListaParadas())[PosDelRecorrido]->GetListaPasajeros())[PosPasajerosParada]
					));
					if (PasajeroAux != NULL) {
						SubirPasajeros(PasajeroAux);
					}
				}
			}
		}
	}
	for (unsigned int PosPasajerosParada = 0; PosPasajerosParada < (*Recorrido->GetListaParadas())[PosDelRecorrido]->GetListaPasajeros()->GetCantidadActual(); PosPasajerosParada++) {
		if (ListaPasajeros->GetCantidadActual() < ListaPasajeros->GetCantidadMaxima()) {
			if ((*(*Recorrido->GetListaParadas())[PosDelRecorrido]->GetListaPasajeros())[PosPasajerosParada]->GetSillaDeRuedas() == false) {
				if (true == ControlSentidoPasajero((*(*Recorrido->GetListaParadas())[PosDelRecorrido]->GetListaPasajeros())[PosPasajerosParada])) {
					cPasajero* PasajeroAux = ((*Recorrido->GetListaParadas())[PosDelRecorrido]->GetListaPasajeros()->Quitar(
						(*(*Recorrido->GetListaParadas())[PosDelRecorrido]->GetListaPasajeros())[PosPasajerosParada]
					));
					if (PasajeroAux != NULL) {
						SubirPasajeros(PasajeroAux);
					}
				}
			}
		}
	}
}

cPasajero* cColectivo::BajarPasajeros(string NombreParadaActual) {
	//Elimina todos los paajeros que tengan como destino la ParadaActual
	for (unsigned int Pos = 0; Pos < ListaPasajeros->GetCantidadActual(); Pos++) {
		int aux = ListaPasajeros->GetCantidadActual();
		string DestinoPasajero = (*ListaPasajeros)[Pos]->GetDestino();
		if (DestinoPasajero == NombreParadaActual) {
			delete ListaPasajeros->Quitar((*ListaPasajeros)[Pos]);
		}
	}
	return NULL;
}

bool cColectivo::ControlSentidoPasajero(cPasajero* Pasajero) {
	if (Sentido == eSentidoRecorrido::Arriba) {
		for (unsigned int Pos = PosDelRecorrido; Pos < Recorrido->GetListaParadas()->GetCantidadActual(); Pos++) {
			if ((*Recorrido->GetListaParadas())[Pos]->GetNombreParada() == Pasajero->GetDestino()) {
				return true;
			}
		}
		return false;
	}

	if (Sentido == eSentidoRecorrido::Abajo) {
		for (unsigned int Pos = 0; Pos < PosDelRecorrido; Pos++) {
			if ((*Recorrido->GetListaParadas())[Pos]->GetNombreParada() == Pasajero->GetDestino()) {
				return true;
			}
		}
		return false;
	}
	return false;
}

void cColectivo::Averia() {
	this->EstadoOperaativo = false;
	for (unsigned int Pos = 0; Pos < ListaPasajeros->GetCantidadActual(); Pos++) {
		(*Recorrido->GetListaParadas())[PosDelRecorrido]->GetListaPasajeros()->Agregar(ListaPasajeros->Quitar((*ListaPasajeros)[Pos]));
	}
}

void cColectivo::RepararColectivo() {
	EstadoOperaativo == true;
}

void cColectivo::ActualizarGPS() {
	if (Recorrido != NULL) {
		this->GPS = (*Recorrido->GetListaParadas())[PosDelRecorrido]->GetNombreParada();
	}
}

void cColectivo::CambioDeSentidoRecorrido() {
	if (Sentido == eSentidoRecorrido::Arriba) {
		Sentido = eSentidoRecorrido::Abajo;
	}
	else {
		Sentido = eSentidoRecorrido::Arriba;
	}
}

void cColectivo::operator+(cPasajero* Pasajero) {
	SubirPasajeros(Pasajero);
}

cPasajero* cColectivo::operator-(cPasajero* Pasajero) {
	return BajarPasajeros(Pasajero->GetDestino());
}

string cColectivo::ToStringColectivo() const {
	string codigoaux;
	if (Recorrido == NULL) {
		codigoaux = "Recorrido no asignado";
	}
	else{
		codigoaux = Recorrido->GetCodigoRecorrido();
	}
	return 
		"\n\nID Colectivo: " + IDColectivo +
		"\nCodigo de Recorrido: " + codigoaux +
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

void cColectivo::operator++() {
	AvanzarRecorrido();
}

istream& operator>>(istream& input, cColectivo& Colectivo) {
	input >> Colectivo.GPS;
	return input;
}

ostream& operator<<(ostream& os, const cColectivo* Colectivo) {
	os << Colectivo->ToStringColectivo();
	return os;
}