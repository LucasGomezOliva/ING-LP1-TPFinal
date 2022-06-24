#include "cColectivoAutonomo.h"

cColectivoAutonomo::cColectivoAutonomo() : cColectivoConAire() {
	this->Bateria = 0;
}

cColectivoAutonomo::~cColectivoAutonomo(){
}

void cColectivoAutonomo::CargarBateria(){

}

void cColectivoAutonomo::DescargarBateria(){

}

bool cColectivoAutonomo::SubirPasajeros(cPasajero* Pasajero) {

	const string InicioPasajero = (*Recorrido->GetListaParadas())[PosDelRecorrido]->GetNombreParada();

	const string DestinoPasajero = Pasajero->GetDestino();

	const unsigned int CantidadParadas = Recorrido->CantidadDeParadasEntreDestinos(InicioPasajero, DestinoPasajero);
	cout << "==================" << endl;
	cout << CantidadParadas << endl;
	cout << "I:" << InicioPasajero << endl;
	cout << "D:" << DestinoPasajero << endl;
	cout << "==================" << endl;
	bool EstadoPasajero = SistemaDePagos->GenerarViaje(InicioPasajero, DestinoPasajero, CantidadParadas, Pasajero->GetTarjetaPasajero());

	if (EstadoPasajero == true) {
		*(ListaPasajeros)+Pasajero;
		return true;
	}
	else {
		return false;
	}
}

istream& operator>>(istream& input, cColectivoAutonomo& Colectivo) {
	input >> Colectivo.GPS;
	return input;
}

ostream& operator<<(ostream& os, const cColectivoAutonomo* Colectivo) {
	os << Colectivo->ToStringColectivo();
	return os;
}