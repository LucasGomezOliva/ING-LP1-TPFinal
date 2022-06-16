#include "cGenerador.h"

cGenerador::cGenerador(){
	this->ListaNombres = new cListaStrings(CantidadNombres);
	for (int i = 0; i < CantidadNombres; ++i) {
		try {
			this->ListaNombres->Agregar(&DefineNombres[i]);
		}
		catch (exception* ex) {
			cout << ex->what() << endl;
			delete ex;
		}
	}
	this->ListaDNI = new cListaStrings(CantidadDNI);
	for (int i = 0; i < CantidadDNI; ++i) {
		try {
			this->ListaDNI->Agregar(&DefineDNI[i]);
		}
		catch (exception* ex) {
			cout << ex->what() << endl;
			delete ex;
		}
	}
	this->ListaDireccionesParadas = new cListaStrings(CandidadDireccionParadas);
	for (int i = 0; i < CandidadDireccionParadas; ++i) {
		try {
			this->ListaDireccionesParadas->Agregar(&DefineDireccionParadas[i]);
		}
		catch (exception* ex) {
			cout << ex->what() << endl;
			delete ex;
		}
	}
}

cGenerador::~cGenerador(){
	delete ListaNombres;
	delete ListaDNI;
	delete ListaDireccionesParadas;
}

bool cGenerador::GenerarRandomBool() {
	srand((unsigned int)time(NULL));
	if ((rand() % 11) == 1) {
		return true;
	}
	else{
		return false;
	}
}

string* cGenerador::GenerarRandomNombre() {
	srand((unsigned int)time(NULL));
	string* aux = NULL;
	if (ListaNombres->GetCantidadActual() != 0) {
		try {
			aux = ListaNombres->QuitarenPos(rand() % ListaNombres->GetCantidadActual());
			return aux;
		}
		catch (exception* ex) {
			cout << ex->what() << endl;
			delete ex;
			return NULL;
		}
	}
	return NULL;
}

string* cGenerador::GenerarRandomDNI() {
	srand((unsigned int)time(NULL));
	string* aux = NULL;
	if (ListaDNI->GetCantidadActual() != 0) {
		try {
			aux = ListaDNI->QuitarenPos(rand() % ListaDNI->GetCantidadActual());
			return aux;
		}
		catch (exception* ex) {
			cout << ex->what() << endl;
			delete ex;
			return NULL;
		}
	}
	return NULL;
}

string* cGenerador::GenerarRandomDireccion() {
	srand((unsigned int)time(NULL));
	string* aux = NULL;
	if (ListaDireccionesParadas->GetCantidadActual() != 0) {
		try {
			aux = ListaDireccionesParadas->QuitarenPos(rand() % ListaDireccionesParadas->GetCantidadActual());
			return aux;
		}
		catch (exception* ex) {
			cout << ex->what() << endl;
			delete ex;
			return NULL;
		}
	}
	return NULL;
}

float cGenerador::GenerarRandomSaldo() {
	srand((unsigned int)time(NULL));
	return 300 + (rand() % 2000 - 300) / 10.0f;
}