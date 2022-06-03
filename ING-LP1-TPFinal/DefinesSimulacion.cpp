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
	unsigned int CantidadSinAire = 0;
	unsigned int CantidadAcordeon = 0;
	unsigned int CantidadAutonomos = 0;
	for (unsigned int i = 0; i < CantidadTotalColectivos; i++) {
		if (CantidadColectivosSinAire > CantidadSinAire) {
			try {
				ListaGlobalColectivos->Agregar(new cColectivoSinAire());
			}
			catch (exception& e) {
				cout << e.what() << endl;
			}
			CantidadSinAire++;
		}
		if (CantidadColectivosAcordeon > CantidadAcordeon) {
			try {
				ListaGlobalColectivos->Agregar(new cColectivoAcordeon());
			}
			catch (exception& e) {
				cout << e.what() << endl;
			}
			CantidadAcordeon++;
		}
		if (CantidadColectivosAutonomos > CantidadAutonomos) {
			try {
				ListaGlobalColectivos->Agregar(new cColectivoAutonomo());
			}
			catch (exception& e) {
				cout << e.what() << endl;
			}
			CantidadAutonomos++;
		}
	}
}

void GenerarAsignarColectiveros(cListaColectivos* ListaGlobalColectivos, cGenerador* GeneradorRandoms) {
	for (unsigned int Pos = 0; Pos < CantidadTotalColectivos; Pos++) {
		cColectivoAutonomo* ColectivoAutonomoAux = dynamic_cast<cColectivoAutonomo*>((*ListaGlobalColectivos)[Pos]);
		if (ColectivoAutonomoAux == NULL) {
			(*ListaGlobalColectivos)[Pos]->SetColectivero(new cColectivero(*GeneradorRandoms->GenerarRandomNombrePasajero(), *GeneradorRandoms->GenerarRandomDNI()));
		}
	}
}

void ActualizarObjetos(cListaColectivos* ListaGlobalColectivos, cListaParadas* ListaGlobalParadas, cRecorrido* RecorridoA, cRecorrido* RecorridoB, cRecorrido* RecorridoC, cGenerador* GeneradorRandoms) {
	ActualizarParadas(ListaGlobalParadas, RecorridoA, RecorridoB, RecorridoC, GeneradorRandoms);
	ActualizarColectivos(ListaGlobalColectivos);
}

void ActualizarColectivos(cListaColectivos* ListaGlobalColectivos) {
	for (unsigned int Pos = 0; Pos < CantidadTotalColectivos; Pos++) {
		//TODO: random para averia por colectivo
		if ((*ListaGlobalColectivos)[Pos]->GetRecorrido() != NULL) {
			(*ListaGlobalColectivos)[Pos]->AvanzarRecorrido(); //TODO: Revisar implementacion de AvanzarRecorrido
			//TODO: Cambiar de sentido del recorrido al llegar al final
		}
	}
}

void ActualizarParadas(cListaParadas* ListaGlobalParadas, cRecorrido* RecorridoA, cRecorrido* RecorridoB, cRecorrido* RecorridoC, cGenerador* GeneradorRandoms) {
	bool Generador = false; // true para agregar pasajeros //TODO: delete de pasajeros en paradas o en colectivos
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
			unsigned int PosParadaRandom = Pos + rand() % (CantidadTotalParadasRecorridoA-Pos);
			return (*RecorridoA->GetListaParadas())[PosParadaRandom]->GetNombreParada();
		}
	}
	for (int Pos = 0; Pos < CantidadTotalParadasRecorridoB; Pos++) {
		if (ParadaActual->GetIDParada() == (*RecorridoB->GetListaParadas())[Pos]->GetIDParada()) {
			unsigned int PosParadaRandom = Pos + rand() % (CantidadTotalParadasRecorridoB - Pos);
			return (*RecorridoB->GetListaParadas())[PosParadaRandom]->GetNombreParada();
		}
	}
	for (int Pos = 0; Pos < CantidadTotalParadasRecorridoC; Pos++) {
		if (ParadaActual->GetIDParada() == (*RecorridoC->GetListaParadas())[Pos]->GetIDParada()) {
			unsigned int PosParadaRandom = Pos + rand() % (CantidadTotalParadasRecorridoC - Pos);
			return (*RecorridoC->GetListaParadas())[PosParadaRandom]->GetNombreParada();
		}
	}
	return "Destino Invalido";
}

void ActualizarColectivosGPS(cListaColectivos* ListaGlobalColectivos) {
	//TODO: Implementacion de gps todos colectivos
}

void ResumenDelDia(cListaColectivos* ListaGlobalColectivos) {
	//TODO: Implementacion del resumen
}