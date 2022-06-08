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
	try {
		aux = ListaNombres->QuitarenPos(rand() % ListaNombres->GetCantidadActual());
	}
	catch (exception* ex) {
		cout << ex->what() << endl;
		delete ex;
		return NULL;
	}
}

string* cGenerador::GenerarRandomDNI() {
	srand((unsigned int)time(NULL));
	try {
		ListaDNI->QuitarenPos(rand() % ListaDNI->GetCantidadActual());
	}
	catch (exception* ex) {
		cout << ex->what() << endl;
		delete ex;
		return NULL;
	}
}

string* cGenerador::GenerarRandomDireccion() {
	srand((unsigned int)time(NULL));
	try {
		ListaDireccionesParadas->QuitarenPos(rand() % ListaDireccionesParadas->GetCantidadActual());
	}
	catch (exception* ex) {
		cout << ex->what() << endl;
		delete ex;
		return NULL;
	}
}

float cGenerador::GenerarRandomSaldo() {
	srand((unsigned int)time(NULL));
	return 300 + (rand() % 2000 - 300) / 10.0f;
}