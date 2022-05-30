#include"DefinesSimulacion.h"

void GenerarParadas(cListaParadas* ListaGlobalParadas) {
	for (int Pos = 0; Pos < CantidadTotalParadas; Pos++) {
		try {
			ListaGlobalParadas->Agregar(new cParada(to_string(Pos), "123", ParadasDireccion[Pos]));
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}
}

void AgregarParadasRecorrido(cRecorrido* RecorridoA, cRecorrido* RecorridoB, cRecorrido* RecorridoC, cListaParadas* ListaGlobalPardas) {
	/*
	///////////////////////////////////////////////////////////////////////
	try {
		RecorridoA->AgregarParadasRecorrido((*ListaGlobalPardas)[0]);
		RecorridoA->AgregarParadasRecorrido((*ListaGlobalPardas)[1]);
		RecorridoA->AgregarParadasRecorrido((*ListaGlobalPardas)[2]);
		RecorridoA->AgregarParadasRecorrido((*ListaGlobalPardas)[3]);
		RecorridoA->AgregarParadasRecorrido((*ListaGlobalPardas)[4]);
		RecorridoA->AgregarParadasRecorrido((*ListaGlobalPardas)[5]);
		RecorridoA->AgregarParadasRecorrido((*ListaGlobalPardas)[6]);
		RecorridoA->AgregarParadasRecorrido((*ListaGlobalPardas)[7]);
		RecorridoA->AgregarParadasRecorrido((*ListaGlobalPardas)[8]);
		RecorridoA->AgregarParadasRecorrido((*ListaGlobalPardas)[9]);
		RecorridoA->AgregarParadasRecorrido((*ListaGlobalPardas)[10]);
		RecorridoA->AgregarParadasRecorrido((*ListaGlobalPardas)[11]);
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}

	///////////////////////////////////////////////////////////////////////
	try {
		RecorridoB->AgregarParadasRecorrido((*ListaGlobalPardas)[5]);
		RecorridoB->AgregarParadasRecorrido((*ListaGlobalPardas)[6]);
		RecorridoB->AgregarParadasRecorrido((*ListaGlobalPardas)[12]);
		RecorridoB->AgregarParadasRecorrido((*ListaGlobalPardas)[13]);
		RecorridoB->AgregarParadasRecorrido((*ListaGlobalPardas)[14]);
		RecorridoB->AgregarParadasRecorrido((*ListaGlobalPardas)[15]);
		RecorridoB->AgregarParadasRecorrido((*ListaGlobalPardas)[16]);
		RecorridoB->AgregarParadasRecorrido((*ListaGlobalPardas)[17]);
		RecorridoB->AgregarParadasRecorrido((*ListaGlobalPardas)[18]);
		RecorridoB->AgregarParadasRecorrido((*ListaGlobalPardas)[19]);
		RecorridoB->AgregarParadasRecorrido((*ListaGlobalPardas)[20]);
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}

	///////////////////////////////////////////////////////////////////////
	try {
		RecorridoC->AgregarParadasRecorrido((*ListaGlobalPardas)[5]);
		RecorridoC->AgregarParadasRecorrido((*ListaGlobalPardas)[6]);
		RecorridoC->AgregarParadasRecorrido((*ListaGlobalPardas)[12]);
		RecorridoC->AgregarParadasRecorrido((*ListaGlobalPardas)[13]);
		RecorridoC->AgregarParadasRecorrido((*ListaGlobalPardas)[14]);
		RecorridoC->AgregarParadasRecorrido((*ListaGlobalPardas)[15]);
		RecorridoC->AgregarParadasRecorrido((*ListaGlobalPardas)[16]);
		RecorridoC->AgregarParadasRecorrido((*ListaGlobalPardas)[17]);
		RecorridoC->AgregarParadasRecorrido((*ListaGlobalPardas)[18]);
		RecorridoC->AgregarParadasRecorrido((*ListaGlobalPardas)[21]);
		RecorridoC->AgregarParadasRecorrido((*ListaGlobalPardas)[22]);
		RecorridoC->AgregarParadasRecorrido((*ListaGlobalPardas)[23]);
		RecorridoC->AgregarParadasRecorrido((*ListaGlobalPardas)[24]);
		RecorridoC->AgregarParadasRecorrido((*ListaGlobalPardas)[25]);
		RecorridoC->AgregarParadasRecorrido((*ListaGlobalPardas)[26]);
		RecorridoC->AgregarParadasRecorrido((*ListaGlobalPardas)[27]);
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}
	///////////////////////////////////////////////////////////////////////
	*/
	
	///////////////////////////////////////////////////////////////////////

	for (unsigned int Pos = 0; Pos < CantidadTotalParadasRecorridoA; Pos++) {
		try {
		RecorridoA->AgregarParadasRecorrido((*ListaGlobalPardas)[ParadasRecorridoA[Pos]]);
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}

	///////////////////////////////////////////////////////////////////////

	for (unsigned int Pos = 0; Pos < CantidadTotalParadasRecorridoB; Pos++) {
		try {
			RecorridoB->AgregarParadasRecorrido((*ListaGlobalPardas)[ParadasRecorridoB[Pos]]);
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}

	///////////////////////////////////////////////////////////////////////

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

}

void ActualizarObjetos(cListaColectivos* ListaGlobalColectivos, cListaParadas* ListaGlobalParadas) {
	ActualizarParadas(ListaGlobalParadas);
	ActualizarColectivos(ListaGlobalColectivos);
}

void ActualizarColectivos(cListaColectivos* ListaGlobalColectivos) {

}

void ActualizarParadas(cListaParadas* ListaGlobalParadas) {

	//Agregar pasajeros a las paradas random

	for (int Pos = 0; Pos < CantidadTotalParadas; Pos++) {
		try {
			/*
			(*ListaGlobalParadas)[Pos]->GetListaPasajeros()->Agregar(new cPasajero(
				*GeneradorRandoms->GenerarRandomNombrePasajero(),
				*GeneradorRandoms->GenerarRandomDNI(),
				"DESTINO-RANDOM",
				GeneradorRandoms->GenerarRandomBool(),
				GeneradorRandoms->GenerarRandomSaldo());
			*/
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}
}

void ActualizarColectivosGPS(cListaColectivos* ListaGlobalColectivos) {

}

void ResumenDelDia(cListaColectivos* ListaGlobalColectivos) {

}