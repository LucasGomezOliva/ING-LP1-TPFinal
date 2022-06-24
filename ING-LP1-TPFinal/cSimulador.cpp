#include "cSimulador.h"
cSimulador::cSimulador() {
	CantidadColectiverosCreados = 0;
	CantidadPasajerosCreados = 0;
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
		CantidadColectiverosCreados++;
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}
}

void cSimulador::GenerarColectivos(cListaColectivos* ListaGlobalColectivos) {
	//TODO : simplificar este metodo
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
	
	for (unsigned int PosColectivos = 0; PosColectivos < CantidadTotalColectivos; PosColectivos++) {

	///////////////////////////////////////////////////////////////////////

	//Random para averia por colectivo

		unsigned int RandomAveria = rand() % 21;

		if (RandomAveria == 7) {
			//(*ListaGlobalColectivos)[PosColectivos]->Averia(); //TODO : Hacer el metodo Averia y reparar colectivo
		}

	///////////////////////////////////////////////////////////////////////

	//Reviso que el colectivo funcione y que tenga un recorirdo asignado

		if ((*ListaGlobalColectivos)[PosColectivos]->GetRecorrido() != NULL && (*ListaGlobalColectivos)[PosColectivos]->GetEstadoOperativo() == true) {

			//(*ListaGlobalColectivos)[PosColectivos]->AvanzarRecorrido(); //TODO: Revisar implementacion de AvanzarRecorrido

			(*ListaGlobalColectivos)[PosColectivos]->operator++();

	//Si el Colectivo llego al final de su recorrido debe empezar a recorrerlo en sendido contrario

			if ((*ListaGlobalColectivos)[PosColectivos]->GetRecorrido()->GetCantidadParadas() == (*ListaGlobalColectivos)[PosColectivos]->GetPosicionRecorrido()) { //TODO : Revisar condicion del if por las posiciones
				
				(*ListaGlobalColectivos)[PosColectivos]->CambioDeSentidoRecorrido();
			}
		}
	}

	///////////////////////////////////////////////////////////////////////
}

void cSimulador::ActualizarParadas(cListaParadas* ListaGlobalParadas, cRecorrido* RecorridoA, cRecorrido* RecorridoB, cRecorrido* RecorridoC, cGenerador* GeneradorRandoms) {
	bool Generador = true; // true para agregar pasajeros //TODO: delete de pasajeros en paradas o en colectivos

	if (Generador) {

		for (unsigned int PosParadas = 0; PosParadas < CantidadTotalParadas; PosParadas++) {

			string DestinoPasajero = GeneradorDestinoRandom((*ListaGlobalParadas)[PosParadas], RecorridoA, RecorridoB, RecorridoC);

			cParada* Aux = (*ListaGlobalParadas)[PosParadas];

			if (DestinoPasajero != "Destino Invalido") {

				string* NombrePasajero = GeneradorRandoms->GenerarRandomNombre();
				string* DNIPasajero = GeneradorRandoms->GenerarRandomDNI();

				if (NombrePasajero != NULL && DNIPasajero != NULL) {
					try {
						(*ListaGlobalParadas)[PosParadas]->GetListaPasajeros()->Agregar(new cPasajero(
							*NombrePasajero,
							*DNIPasajero,
							DestinoPasajero,
							GeneradorRandoms->GenerarRandomBool(),
							GeneradorRandoms->GenerarRandomSaldo()));
						CantidadPasajerosCreados++;
					}
					catch (exception& e) {
						cout << e.what() << endl;
					}
				}
			}
		}
	}
}

string cSimulador::GeneradorDestinoRandom(cParada* ParadaActual, cRecorrido* RecorridoA, cRecorrido* RecorridoB, cRecorrido* RecorridoC) {
	//TODO : Revisar correcto funcionamiento
	//TODO : Tener en cuenta los dos sentidos de recorrido del colectivo
	srand((unsigned int)time(NULL));
	for (unsigned int Pos = 0; Pos < CantidadTotalParadasRecorridoA; Pos++) {
		if (ParadaActual->GetIDParada() == (*RecorridoA->GetListaParadas())[Pos]->GetIDParada()) {
			unsigned int PosParadaRandom = rand() % CantidadTotalParadasRecorridoA;
			//unsigned int PosParadaRandom = Pos + rand() % (CantidadTotalParadasRecorridoA - Pos);

			if ((*RecorridoA->GetListaParadas())[PosParadaRandom]->GetNombreParada() == ParadaActual->GetNombreParada()) {
				if ((PosParadaRandom + 1) >= CantidadTotalParadasRecorridoA) {
					PosParadaRandom = PosParadaRandom - 2;
				}
				else{
					PosParadaRandom = PosParadaRandom + 1;
				}
			}

			return (*RecorridoA->GetListaParadas())[PosParadaRandom]->GetNombreParada();
		}
	}
	/*
	for (unsigned int Pos = 0; Pos < CantidadTotalParadasRecorridoB; Pos++) {
		if (ParadaActual->GetIDParada() == (*RecorridoB->GetListaParadas())[Pos]->GetIDParada()) {
			unsigned int PosParadaRandom = rand() % CantidadTotalParadasRecorridoB;
			//unsigned int PosParadaRandom = Pos + rand() % (CantidadTotalParadasRecorridoB - Pos);
			return (*RecorridoB->GetListaParadas())[PosParadaRandom]->GetNombreParada();
		}
	}
	for (unsigned int Pos = 0; Pos < CantidadTotalParadasRecorridoC; Pos++) {
		if (ParadaActual->GetIDParada() == (*RecorridoC->GetListaParadas())[Pos]->GetIDParada()) {
			unsigned int PosParadaRandom = rand() % CantidadTotalParadasRecorridoC;
			//unsigned int PosParadaRandom = Pos + rand() % (CantidadTotalParadasRecorridoC - Pos);
			return (*RecorridoC->GetListaParadas())[PosParadaRandom]->GetNombreParada();
		}
	}
	*/
	return "Destino Invalido"; //TODO : Destino invalido exception
}

string cSimulador::ActualizarColectivosGPS(cListaColectivos* ListaGlobalColectivos) {
	string aux = "";
	for (unsigned int PosColectivos = 0; PosColectivos < CantidadTotalColectivos; PosColectivos++) {
		(*ListaGlobalColectivos)[PosColectivos]->ActualizarGPS();
	}
	for (unsigned int PosColectivos = 0; PosColectivos < CantidadTotalColectivos; PosColectivos++) {
		if((*ListaGlobalColectivos)[PosColectivos]->GetGPS()!="")
			aux += (*ListaGlobalColectivos)[PosColectivos]->GetGPS() + " \n";
	}
	return aux;
}

string cSimulador::ResumenDelDia(cListaColectivos* ListaGlobalColectivos) {
	//TODO : Indicar el tipo de colectivo al listar los datos
	string aux;
	unsigned int CantidadPasajerosTotal = 0;
	float MontoTotal = 0;
	for (unsigned int PosColectivos = 0; PosColectivos < CantidadTotalColectivos; PosColectivos++) {
		aux += (*ListaGlobalColectivos)[PosColectivos]->ToStringColectivo();
		CantidadPasajerosTotal += (*ListaGlobalColectivos)[PosColectivos]->GetSistemaDePagos()->GetCantidadDePasajeros();
		MontoTotal += (*ListaGlobalColectivos)[PosColectivos]->GetSistemaDePagos()->GetColectaDelDia();
	}
	aux += 
		"\n\nCantidad Pasajeros Total:" + to_string(CantidadPasajerosTotal) +
		"\nMonto Total:" + to_string(MontoTotal);
	return aux;
}