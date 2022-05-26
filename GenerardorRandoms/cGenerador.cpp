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

string* cGenerador::GenerarRandomNombrePasajero() {
	srand((unsigned int)time(NULL));
	//return ListaNombres->QuitarenPos(rand() % ListaNombres->getCA());
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
	//return ListaDNI->QuitarenPos(rand() % ListaDNI->getCA());
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
	srand(time(NULL));
	//return ListaDireccionesParadas->QuitarenPos(rand() % ListaDireccionesParadas->getCA());
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
	//return 100 + rand() % 1500;
	return 300 + (rand() % 2000 - 300) / 10.0f;
	
}