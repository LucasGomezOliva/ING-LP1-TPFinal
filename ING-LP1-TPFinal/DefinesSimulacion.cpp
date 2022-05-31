#include"DefinesSimulacion.h"

void GenerarParadas(cListaParadas* ListaGlobalParadas) {
	for (int Pos = 0; Pos < CantidadTotalParadas; Pos++) {
		try {
			ListaGlobalParadas->Agregar(new cParada(to_string(Pos), ParadasNombre[Pos], ParadasDireccion[Pos]));
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}
}

void AgregarParadasRecorrido(cRecorrido* RecorridoA, cRecorrido* RecorridoB, cRecorrido* RecorridoC, cListaParadas* ListaGlobalPardas) {

	for (unsigned int Pos = 0; Pos < CantidadTotalParadasRecorridoA; Pos++) {
		try {
			RecorridoA->AgregarParadasRecorrido((*ListaGlobalPardas)[ParadasRecorridoA[Pos]]);
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}

	for (unsigned int Pos = 0; Pos < CantidadTotalParadasRecorridoB; Pos++) {
		try {
			RecorridoB->AgregarParadasRecorrido((*ListaGlobalPardas)[ParadasRecorridoB[Pos]]);
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}

	for (unsigned int Pos = 0; Pos < CantidadTotalParadasRecorridoC; Pos++) {
		try {
			RecorridoC->AgregarParadasRecorrido((*ListaGlobalPardas)[ParadasRecorridoC[Pos]]);
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}
}

void GenerarColectivos(cListaColectivos* ListaGlobalColectivos) {
	for (int Pos = 0; Pos < CantidadTotalColectivos; Pos++) {
		try {
			//ListaGlobalColectivos->Agregar(new cColectivoSinAire());
			//ListaGlobalColectivos->Agregar(new cColectivoAcordeon());
			//ListaGlobalColectivos->Agregar(new cColectivoAutonomo());
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}
}

void ActualizarObjetos(cListaColectivos* ListaGlobalColectivos, cListaParadas* ListaGlobalParadas, cRecorrido* RecorridoA, cRecorrido* RecorridoB, cRecorrido* RecorridoC, cGenerador* GeneradorRandoms) {
	ActualizarParadas(ListaGlobalParadas, RecorridoA, RecorridoB, RecorridoC, GeneradorRandoms);
	ActualizarColectivos(ListaGlobalColectivos);
}

void ActualizarColectivos(cListaColectivos* ListaGlobalColectivos) {

}

void ActualizarParadas(cListaParadas* ListaGlobalParadas, cRecorrido* RecorridoA, cRecorrido* RecorridoB, cRecorrido* RecorridoC, cGenerador* GeneradorRandoms) {
	bool Generador = false; // true para agregar pasajeros
	if (Generador) {
		for (int Pos = 0; Pos < CantidadTotalParadas; Pos++) {
			try {
				(*ListaGlobalParadas)[Pos]->GetListaPasajeros()->Agregar(new cPasajero(
					*GeneradorRandoms->GenerarRandomNombrePasajero(),
					*GeneradorRandoms->GenerarRandomDNI(),
					GeneradorDestinoRandom((*ListaGlobalParadas)[Pos], RecorridoA, RecorridoB, RecorridoC),
					GeneradorRandoms->GenerarRandomBool(),
					GeneradorRandoms->GenerarRandomSaldo()));
			}
			catch (exception& e) {
				cout << e.what() << endl;
			}
		}
	}
}

string GeneradorDestinoRandom(cParada* ParadaActual, cRecorrido* RecorridoA, cRecorrido* RecorridoB, cRecorrido* RecorridoC) {
	srand((unsigned int)time(NULL));
	for (int Pos = 0; Pos < CantidadTotalParadasRecorridoA; Pos++) {
		if (ParadaActual->GetIDParada() == (*RecorridoA->GetListaParadas())[Pos]->GetIDParada()) {
			unsigned int PosParadaRandom = rand() % (CantidadTotalParadasRecorridoA-Pos) + Pos;
			return (*RecorridoA->GetListaParadas())[PosParadaRandom]->GetNombreParada();
		}
	}
	for (int Pos = 0; Pos < CantidadTotalParadasRecorridoB; Pos++) {
		if (ParadaActual->GetIDParada() == (*RecorridoB->GetListaParadas())[Pos]->GetIDParada()) {
			unsigned int PosParadaRandom = rand() % (CantidadTotalParadasRecorridoB - Pos) + Pos;
			return (*RecorridoB->GetListaParadas())[PosParadaRandom]->GetNombreParada();
		}
	}
	for (int Pos = 0; Pos < CantidadTotalParadasRecorridoC; Pos++) {
		if (ParadaActual->GetIDParada() == (*RecorridoC->GetListaParadas())[Pos]->GetIDParada()) {
			unsigned int PosParadaRandom = rand() % (CantidadTotalParadasRecorridoC - Pos) + Pos;
			return (*RecorridoC->GetListaParadas())[PosParadaRandom]->GetNombreParada();
		}
	}
	return "Destino Invalido";
}

void ActualizarColectivosGPS(cListaColectivos* ListaGlobalColectivos) {

}

void ResumenDelDia(cListaColectivos* ListaGlobalColectivos) {
	
}