// ING-LP1-TPFinal.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include<time.h>
#include"../GenerardorRandoms/cGenerador.h"

//borrar
#include"cRecorrido.h"
//borrar

const string NombresParadasRecorrido_A[] = {
	"Recorrido A - Parada 1",
	"Recorrido A - Parada 2",
	"Recorrido A - Parada 3",
	"Recorrido A - Parada 4",
	"Recorrido A - Parada 5",
};

const string NombresParadasRecorrido_B[] = {
	"Recorrido B - Parada 1",
	"Recorrido B - Parada 2",
	"Recorrido B - Parada 3",
	"Recorrido B - Parada 4",
	"Recorrido B - Parada 5",
};


int main()
{
	//Generador de Randoms para la creacion de los distintos objetos

    cGenerador* GeneradorRandoms = new cGenerador();

	///////////////////////////////////////////////////////////////////////

	cRecorrido* Recorrido_A = new cRecorrido("Recorrido A");

	cParada* ParadaAux = new cParada(
		to_string(Recorrido_A->GetCantidadParadas()),
		NombresParadasRecorrido_A[Recorrido_A->GetCantidadParadas()],
		*GeneradorRandoms->GenerarRandomDireccion());

	try {
		Recorrido_A->AgregarParadasRecorrido(ParadaAux);
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}

	ParadaAux = new cParada(
		to_string(Recorrido_A->GetCantidadParadas()),
		NombresParadasRecorrido_A[Recorrido_A->GetCantidadParadas()],
		*GeneradorRandoms->GenerarRandomDireccion());

	try {
		Recorrido_A->AgregarParadasRecorrido(ParadaAux);
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}
	cout << "\n\n/////////////////////////////////////" << endl;

	Recorrido_A->imprimir();


	///////////////////////////////////////////////////////////////////////

	cout << "\n\n/////////////////////////////////////" << endl;

	cPasajero* Pasajero1 = new cPasajero(
		*GeneradorRandoms->GenerarRandomNombrePasajero(), 
		*GeneradorRandoms->GenerarRandomDNI(),
		"DESTINO-1",
		GeneradorRandoms->GenerarRandomBool(),
		GeneradorRandoms->GenerarRandomSaldo());

	cPasajero* Pasajero2 = new cPasajero(
		*GeneradorRandoms->GenerarRandomNombrePasajero(),
		*GeneradorRandoms->GenerarRandomDNI(),
		"DESTINO-2",
		GeneradorRandoms->GenerarRandomBool(),
		GeneradorRandoms->GenerarRandomSaldo());

	Pasajero1->imprimir();

	cout << "\n\n/////////////////////////////////////" << endl;

	Pasajero2->imprimir();

	cout << "\n\n/////////////////////////////////////" << endl;

	///////////////////////////////////////////////////////////////////////
	
	//Manejo del "tick" para poder actualizar todos los objetos y el GPS

	unsigned int time_0;
	unsigned int time_1;
	unsigned int CantidadDeSegundos = 0;
	bool ciclo = false; //true para iniciar
	time_0 = clock();
	while (ciclo) {
		time_1 = clock();
		double diftime = (double(time_1 - time_0) / CLOCKS_PER_SEC);
		if (diftime >= 1) {
			cout << "\nPasaron: " << diftime << " s" << endl;
			//Actualiza los objetos
			cout << "\tObjetos Actualizados";
			time_0 = clock();
			CantidadDeSegundos++;
			if (CantidadDeSegundos % 5 == 0) {
				//Actualizar GPS
				cout << "\tGPS Actualizados";
			}
		}
		if (CantidadDeSegundos == 15)
			ciclo = false;
	}
	///////////////////////////////////////////////////////////////////////

	delete Pasajero1;
	delete Pasajero2;
	delete Recorrido_A;
    delete GeneradorRandoms;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
