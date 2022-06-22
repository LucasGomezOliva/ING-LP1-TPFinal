#include "cRecorrido.h"

cRecorrido::cRecorrido() : CodigoRecorrido(""), NombreRecorrido("") {
	this->ListaParadas = new cListaParadas(30, false);
	this->KmRecorrido = 0;
}

cRecorrido::cRecorrido(string CodigoRecorrido, string NombreRecorrido, float KmRecorrido) : CodigoRecorrido(CodigoRecorrido), NombreRecorrido(NombreRecorrido) {
	this->KmRecorrido = KmRecorrido;
	this->ListaParadas = new cListaParadas(30, false);
}

cRecorrido::~cRecorrido(){
	delete ListaParadas;
}

cListaParadas* cRecorrido::GetListaParadas()const {
	return ListaParadas;
}

string cRecorrido::GetCodigoRecorrido()const {
	return CodigoRecorrido;
}

unsigned int cRecorrido::GetCantidadParadas() const {
	return ListaParadas->CantidadActual;
}

int cRecorrido::CantidadDeParadasEntreDestinos(string ParadaInicio, string ParadaDestino) {
	unsigned int PosInicio = 0;
	unsigned int PosDestino = 0;
	for (unsigned int PosParadas = 0; PosParadas < ListaParadas->GetCantidadActual(); PosParadas++) {
		if ((*ListaParadas)[PosParadas]->GetNombreParada() == ParadaInicio) {
			PosInicio = PosParadas;
		}
		if ((*ListaParadas)[PosParadas]->GetNombreParada() == ParadaDestino) {
			PosDestino = PosParadas;
		}
	}
	if(PosDestino>PosInicio)
		return PosDestino - PosInicio;
	if (PosDestino < PosInicio)
		return PosInicio - PosDestino;
	//return 0;
}
bool cRecorrido::AgregarParadasRecorrido(cParada* Parada){
	ListaParadas->Agregar(Parada);
	return false;
}

string cRecorrido::ToStringRecorrido() const {
	return 
		"\nCodigo del recorrido: " + CodigoRecorrido +
		"\nNombre del recorrido: " + NombreRecorrido + 
		"\nKM Totales del Recorrido: " + to_string(KmRecorrido);
}

void cRecorrido::imprimir() const{
	cout << ToStringRecorrido() << endl;;
	cout << "\nLista de Paradas del recorrido" << endl;
	ListaParadas->Listar();
}
