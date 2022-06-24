#include "cColectivoSinAire.h"
cColectivoSinAire::cColectivoSinAire():cColectivo() {

}

cColectivoSinAire::cColectivoSinAire(cRecorrido* RecorridoAsignado):cColectivo(RecorridoAsignado) {

}
cColectivoSinAire::~cColectivoSinAire() {

}

string cColectivoSinAire::ToStringColectivoSinAire() {
	return ToStringColectivo();
}
void cColectivoSinAire::Imprimir() {
	cout << "Imprimir";
}
bool cColectivoSinAire::SubirPasajeros(cPasajero* Pasajero) {

	//TODO : Hacer metodo virtual para los colectivos autonomos no dependan del colectivero para cobrar pasaje

	const string InicioPasajero = (*Recorrido->GetListaParadas())[PosDelRecorrido]->GetNombreParada();

	const string DestinoPasajero = Colectivero->CargarDestinoPasajero(Pasajero->GetDestino());

	const unsigned int CantidadParadas = Recorrido->CantidadDeParadasEntreDestinos(InicioPasajero, DestinoPasajero);

	cout << CantidadParadas << endl;

	bool EstadoPasajero = SistemaDePagos->GenerarViaje(InicioPasajero, DestinoPasajero, CantidadParadas, Pasajero->GetTarjetaPasajero());

	if (EstadoPasajero == true) {
		*(ListaPasajeros)+Pasajero;
		return true;
	}
	else {
		return false;
	}
}