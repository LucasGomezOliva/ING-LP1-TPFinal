#include "cSimulador.h"
cSimulador::cSimulador() {

}

cSimulador::~cSimulador() {

}

void cSimulador::GenerarParadas(cListaParadas* ListaGlobalParadas) {
	for (unsigned int Pos = 0; Pos < CantidadTotalParadas; Pos++) {
		try {
			ListaGlobalParadas->Agregar(new cParada(ParadasNombre[Pos], ParadasDireccion[Pos]));
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}
}

void cSimulador::AgregarParadasRecorrido(cRecorrido* RecorridoA, cRecorrido* RecorridoB, cRecorrido* RecorridoC, cListaParadas* ListaGlobalPardas) {
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

void cSimulador::GenerarColectiveros(cListaTemplate<cColectivero>* ListaColectiveros, cGenerador* GeneradorRandoms) {
	for (unsigned int Pos = 0; Pos < CantidadColectiveros; Pos++) {
		try {
		ListaColectiveros->Agregar(new cColectivero(*GeneradorRandoms->GenerarRandomNombre(), *GeneradorRandoms->GenerarRandomDNI()));
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}
}

void cSimulador::GenerarColectivos(cListaColectivos* ListaGlobalColectivos) {
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

void cSimulador::AsignarColectiveros(cListaColectivos* ListaGlobalColectivos, cListaTemplate<cColectivero>* ListaColectiveros) {
	//TODO : exception para la falta de colectiveros
	unsigned int PosColectiveros = 0;
	for (unsigned int Pos = 0; Pos < CantidadTotalColectivos; Pos++) {
		cColectivoAutonomo* ColectivoAutonomoAux = dynamic_cast<cColectivoAutonomo*>((*ListaGlobalColectivos)[Pos]);
		if (ColectivoAutonomoAux == NULL) {
			(*ListaGlobalColectivos)[Pos]->SetColectivero((*ListaColectiveros)[PosColectiveros]);
			PosColectiveros++;
		}
	}
}

void cSimulador::ActualizarObjetos(cListaColectivos* ListaGlobalColectivos, cListaParadas* ListaGlobalParadas, cRecorrido* RecorridoA, cRecorrido* RecorridoB, cRecorrido* RecorridoC, cGenerador* GeneradorRandoms) {
	ActualizarParadas(ListaGlobalParadas, RecorridoA, RecorridoB, RecorridoC, GeneradorRandoms);
	ActualizarColectivos(ListaGlobalColectivos);
}

void cSimulador::ActualizarColectivos(cListaColectivos* ListaGlobalColectivos) {
	for (unsigned int Pos = 0; Pos < CantidadTotalColectivos; Pos++) {
		//TODO: random para averia por colectivo
		if ((*ListaGlobalColectivos)[Pos]->GetRecorrido() != NULL) {
			(*ListaGlobalColectivos)[Pos]->AvanzarRecorrido(); //TODO: Revisar implementacion de AvanzarRecorrido
			//TODO: Cambiar de sentido del recorrido al llegar al final
		}
	}
}

void cSimulador::ActualizarParadas(cListaParadas* ListaGlobalParadas, cRecorrido* RecorridoA, cRecorrido* RecorridoB, cRecorrido* RecorridoC, cGenerador* GeneradorRandoms) {
	bool Generador = false; // true para agregar pasajeros //TODO: delete de pasajeros en paradas o en colectivos
	if (Generador) {
		for (unsigned int Pos = 0; Pos < CantidadTotalParadas; Pos++) {
			try {
				(*ListaGlobalParadas)[Pos]->GetListaPasajeros()->Agregar(new cPasajero(
					*GeneradorRandoms->GenerarRandomNombre(),
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

string cSimulador::GeneradorDestinoRandom(cParada* ParadaActual, cRecorrido* RecorridoA, cRecorrido* RecorridoB, cRecorrido* RecorridoC) {
	srand((unsigned int)time(NULL));
	for (unsigned int Pos = 0; Pos < CantidadTotalParadasRecorridoA; Pos++) {
		if (ParadaActual->GetIDParada() == (*RecorridoA->GetListaParadas())[Pos]->GetIDParada()) {
			unsigned int PosParadaRandom = Pos + rand() % (CantidadTotalParadasRecorridoA - Pos);
			return (*RecorridoA->GetListaParadas())[PosParadaRandom]->GetNombreParada();
		}
	}
	for (unsigned int Pos = 0; Pos < CantidadTotalParadasRecorridoB; Pos++) {
		if (ParadaActual->GetIDParada() == (*RecorridoB->GetListaParadas())[Pos]->GetIDParada()) {
			unsigned int PosParadaRandom = Pos + rand() % (CantidadTotalParadasRecorridoB - Pos);
			return (*RecorridoB->GetListaParadas())[PosParadaRandom]->GetNombreParada();
		}
	}
	for (unsigned int Pos = 0; Pos < CantidadTotalParadasRecorridoC; Pos++) {
		if (ParadaActual->GetIDParada() == (*RecorridoC->GetListaParadas())[Pos]->GetIDParada()) {
			unsigned int PosParadaRandom = Pos + rand() % (CantidadTotalParadasRecorridoC - Pos);
			return (*RecorridoC->GetListaParadas())[PosParadaRandom]->GetNombreParada();
		}
	}
	return "Destino Invalido";
}

string cSimulador::ActualizarColectivosGPS(cListaColectivos* ListaGlobalColectivos) {
	string aux = "";
	for (unsigned int Pos = 0; Pos < CantidadTotalColectivos; Pos++) {
		(*ListaGlobalColectivos)[Pos]->ActualizarGPS();
	}
	for (unsigned int Pos = 0; Pos < CantidadTotalColectivos; Pos++) {
		aux += (*ListaGlobalColectivos)[Pos]->GetGPS();
	}
	return aux;
}

string cSimulador::ResumenDelDia(cListaColectivos* ListaGlobalColectivos) {
	//TODO : Indicar el tipo de colectivo al listar los datos
	string aux;
	unsigned int CantidadPasajerosTotal = 0;
	float MontoTotal = 0;
	for (unsigned int Pos = 0; Pos < CantidadTotalColectivos; Pos++) {
		aux += (*ListaGlobalColectivos)[Pos]->ToStringColectivo();
		CantidadPasajerosTotal += (*ListaGlobalColectivos)[Pos]->GetSistemaDePagos()->GetCantidadDePasajeros();
		MontoTotal += (*ListaGlobalColectivos)[Pos]->GetSistemaDePagos()->GetColectaDelDia();
	}
	aux += 
		"\n\nCantidad Pasajeros Total:" + to_string(CantidadPasajerosTotal) +
		"\nMonto Total:" + to_string(MontoTotal);
	return aux;
}