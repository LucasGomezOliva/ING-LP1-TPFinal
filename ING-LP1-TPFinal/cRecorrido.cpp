#include "cRecorrido.h"

cRecorrido::cRecorrido(){
	this->CodigoRecorrido = "";
	//this->ListaParadas = new cListaParadas(10, false);
}

cRecorrido::cRecorrido(string CodigoRecorrido){
	this->CodigoRecorrido = CodigoRecorrido;
}

cRecorrido::~cRecorrido(){
}

string cRecorrido::GetCodigoRecorrido(){
	return CodigoRecorrido;
}

int cRecorrido::CantidadDeParadasEntreDestinos(string ParadaInicio, string ParadaDestino) {
	return 0;
}
bool cRecorrido::AgregarParadasRecorrido(cParada* Parada){
	return false;
}

string cRecorrido::ToStringRecorrido() const {
	return "Codigo del recorrido" + CodigoRecorrido;
}

void cRecorrido::imprimir() const{
	cout << ToStringRecorrido();
}
