#include "cRecorrido.h"

cRecorrido::cRecorrido(){
	this->CodigoRecorrido = "";
	this->NombreRecorrido = "";
	this->ListaParadas = new cListaParadas(30, false);
	this->KmRecorrido = 0;
}

cRecorrido::cRecorrido(string CodigoRecorrido, string NombreRecorrido, float KmRecorrido){
	this->CodigoRecorrido = CodigoRecorrido;
	this->NombreRecorrido = NombreRecorrido;
	this->KmRecorrido = KmRecorrido;
	this->ListaParadas = new cListaParadas(30, false);
}

cRecorrido::~cRecorrido(){
	delete ListaParadas;
}

cListaParadas* cRecorrido::GetListaParadas()const {
	return ListaParadas;
}

string cRecorrido::GetCodigoRecorrido(){
	return CodigoRecorrido;
}

int cRecorrido::GetCantidadParadas() const {
	return ListaParadas->CantidadActual;
}

int cRecorrido::CantidadDeParadasEntreDestinos(string ParadaInicio, string ParadaDestino) {
	return 0;
}
bool cRecorrido::AgregarParadasRecorrido(cParada* Parada){
	ListaParadas->Agregar(Parada);
	return false;
}

string cRecorrido::ToStringRecorrido() const {
	return 
		"\nCodigo del recorrido: " + CodigoRecorrido +
		"\n Nombre del recorrido: " + NombreRecorrido + 
		"\n KM Totales del Recorrido: " + to_string(KmRecorrido);
}

void cRecorrido::imprimir() const{
	cout << ToStringRecorrido() << endl;;
	cout << "\nLista de Paradas del recorrido" << endl;
	ListaParadas->Listar();
}
