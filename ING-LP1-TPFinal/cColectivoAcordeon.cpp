#include "cColectivoAcordeon.h"
cColectivoAcordeon::cColectivoAcordeon() : cColectivoConAire() {

}


cColectivoAcordeon::~cColectivoAcordeon() {

}
bool cColectivoAcordeon::SubirPasajeros(cPasajero* Pasajero) {

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