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

	BajarPasajeros((*Recorrido->GetListaParadas())[PosDelRecorrido]->GetNombreParada());// TODO : Revisar que se borren los pasajeros

	for (unsigned int PosPasajerosParada = 0; PosPasajerosParada < (*Recorrido->GetListaParadas())[PosDelRecorrido]->GetListaPasajeros()->GetCantidadActual(); PosPasajerosParada++) {
		if (ListaPasajeros->GetCantidadActual() < ListaPasajeros->GetCantidadMaxima()) {;
		string Inicio = (*Recorrido->GetListaParadas())[PosDelRecorrido]->GetNombreParada();
		string Destino = (*(*Recorrido->GetListaParadas())[PosDelRecorrido]->GetListaPasajeros())[PosPasajerosParada]->GetDestino();
			if (true == ControlSentidoPasajero((*(*Recorrido->GetListaParadas())[PosDelRecorrido]->GetListaPasajeros())[PosPasajerosParada])) {
				cPasajero* PasajeroAux = (*Recorrido->GetListaParadas())[PosDelRecorrido]->PasajeroSubeColectivo();
				if (PasajeroAux != NULL) {
					SubirPasajeros(PasajeroAux);
				}
			}
		}
	}
}

cPasajero* cColectivo::BajarPasajeros(string NombreParadaActual) {
	//Elimina todos los paajeros que tengan como destino la ParadaActual
	for (unsigned int Pos = 0; Pos < ListaPasajeros->GetCantidadActual(); Pos++) {
		if ((*ListaPasajeros)[Pos]->GetDestino() == NombreParadaActual) {
			delete ListaPasajeros->Quitar((*ListaPasajeros)[Pos]);
		}
	}
	return NULL;
}

//bool cColectivo::SubirPasajeros(cPasajero* Pasajero) {
//
//	//TODO : Hacer metodo virtual para los colectivos autonomos no dependan del colectivero para cobrar pasaje
//	//TODO : Controlar que los pasajeros se suban al sentido correcto (metodo de control al inico de SubirPasajero)
//
//	const string InicioPasajero = (*Recorrido->GetListaParadas())[PosDelRecorrido]->GetNombreParada();
//
//	const string DestinoPasajero = Colectivero->CargarDestinoPasajero(Pasajero->GetDestino());
//
//	const unsigned int CantidadParadas = Recorrido->CantidadDeParadasEntreDestinos(InicioPasajero, DestinoPasajero);
//
//	bool EstadoPasajero = SistemaDePagos->GenerarViaje(InicioPasajero, DestinoPasajero, CantidadParadas, Pasajero->GetTarjetaPasajero());
//
//	if (EstadoPasajero == true) {
//		*(ListaPasajeros)+Pasajero;
//		return true;
//	}
//	else {
//		return false;
//	}
//}

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
		//for (unsigned int Pos = PosDelRecorrido; Pos > 0; Pos--) {
			if ((*Recorrido->GetListaParadas())[Pos]->GetNombreParada() == Pasajero->GetDestino()) {
				return true;
			}
		}
		return false;
	}
}

void cColectivo::Averia() {
	//TODO : solicitud de enviar a un colectivo con poca gente a su ubicacion para llevar a los pasajeros
	//TODO : enviar colectivo al taller
	//TODO : una vez reparado asignar una fecha de mantenimiento (en cSimulador)
	this->EstadoOperaativo = false;

	//Baja a los pasajeros del colectivo y los agrega a la lista de pasajeros de la parada donde se encoentraba
	for (unsigned int Pos = 0; Pos < ListaPasajeros->GetCantidadActual(); Pos++) {
		(*Recorrido->GetListaParadas())[PosDelRecorrido]->GetListaPasajeros()->Agregar(ListaPasajeros->Quitar((*ListaPasajeros)[Pos]));
	}
}

void cColectivo::ActualizarGPS() {
	if (Recorrido != NULL) {
		this->GPS = (*Recorrido->GetListaParadas())[PosDelRecorrido]->GetNombreParada();
	}
}

void cColectivo::CambioDeSentidoRecorrido() {
	if (Sentido == eSentidoRecorrido::Arriba) {
		Sentido == eSentidoRecorrido::Abajo;
	}
	else {
		Sentido == eSentidoRecorrido::Arriba;
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

void cColectivo::operator++() {
	AvanzarRecorrido();
}