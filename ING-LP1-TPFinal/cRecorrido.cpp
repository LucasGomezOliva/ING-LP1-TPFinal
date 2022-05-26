#include "cRecorrido.h"

cRecorrido::cRecorrido(){
	this->CodigoRecorrido = "";
	this->ListaParadas = new cListaParadas(5, true);
}

cRecorrido::cRecorrido(string CodigoRecorrido){
	this->CodigoRecorrido = CodigoRecorrido;
	this->ListaParadas = new cListaParadas(5, true);
}

cRecorrido::~cRecorrido(){
	delete ListaParadas;
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
	return "\nCodigo del recorrido: " + CodigoRecorrido;
}

void cRecorrido::imprimir() const{
	cout << ToStringRecorrido() << endl;;
	cout << "\nLista de Paradas del recorrido" << endl;
	ListaParadas->Listar();
}
