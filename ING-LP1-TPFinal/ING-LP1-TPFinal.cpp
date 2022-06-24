// ING-LP1-TPFinal.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include<time.h>
#include"cSimulador.h"

int main()
{
	///////////////////////////////////////////////////////////////////////

	//Generador de Randoms para la creacion de los distintos objetos

	cGenerador* GeneradorRandoms = new cGenerador();

	///////////////////////////////////////////////////////////////////////

	//Clase simulador

	cSimulador* Simulador = new cSimulador();

	///////////////////////////////////////////////////////////////////////
	
	//Inicializacion de los recorridos y paradas

	cRecorrido* RecorridoA = new cRecorrido(CodigoRecorridos[0], NombreRecorridos[0], TotalKilometrosRecorrido[0]);

	cRecorrido* RecorridoB = new cRecorrido(CodigoRecorridos[1], NombreRecorridos[1], TotalKilometrosRecorrido[1]);

	cRecorrido* RecorridoC = new cRecorrido(CodigoRecorridos[2], NombreRecorridos[2], TotalKilometrosRecorrido[2]);

	cListaParadas* ListaGlobalPardas = new cListaParadas(CantidadTotalParadas, true);

	Simulador->GenerarParadas(ListaGlobalPardas);

	Simulador->AgregarParadasRecorrido(RecorridoA, RecorridoB, RecorridoC, ListaGlobalPardas);

	RecorridoA->imprimir();
	cout << "\n\n/////////////////////////////////////" << endl;
	RecorridoB->imprimir();
	cout << "\n\n/////////////////////////////////////" << endl;
	RecorridoC->imprimir();
	cout << "\n\n/////////////////////////////////////" << endl;

	///////////////////////////////////////////////////////////////////////

	//Inicializacion de los colectiveros

	cListaTemplate<cColectivero>* ListaGlobalColectiveros = new cListaTemplate<cColectivero>(CantidadColectiveros, true);

	Simulador->GenerarColectiveros(ListaGlobalColectiveros,GeneradorRandoms);

	cout << "\n\n=========== Lista de colectiveros ===========" << endl;

	ListaGlobalColectiveros->Listar();

	///////////////////////////////////////////////////////////////////////
	
	//Inicializacion de los colectivos

	cListaColectivos* ListaGlobalColectivos = new cListaColectivos(CantidadTotalColectivos, true);

	Simulador->GenerarColectivos(ListaGlobalColectivos);

	Simulador->AsignarColectiveros(ListaGlobalColectivos, ListaGlobalColectiveros);

	//Asignacion de recorridos

		(*ListaGlobalColectivos)[0]->SetNuevoRecorrido(RecorridoA);
		(*ListaGlobalColectivos)[1]->SetNuevoRecorrido(RecorridoA);
		(*ListaGlobalColectivos)[2]->SetNuevoRecorrido(RecorridoA);

		(*ListaGlobalColectivos)[3]->SetNuevoRecorrido(RecorridoB);
		(*ListaGlobalColectivos)[4]->SetNuevoRecorrido(RecorridoB);
		(*ListaGlobalColectivos)[5]->SetNuevoRecorrido(RecorridoB);

		(*ListaGlobalColectivos)[6]->SetNuevoRecorrido(RecorridoC);
		(*ListaGlobalColectivos)[7]->SetNuevoRecorrido(RecorridoC);
		(*ListaGlobalColectivos)[8]->SetNuevoRecorrido(RecorridoC);

	///////////////////////////////////////////////////////////////////////
	
	//Manejo del "tick" para poder actualizar todos los objetos y el GPS

	unsigned int time_0;
	unsigned int time_1;
	unsigned int CantidadDeSegundos = 0;
	bool ciclo = true; //true para iniciar
	time_0 = clock();
	while (ciclo) {
		time_1 = clock();
		double diftime = (double(time_1 - time_0) / CLOCKS_PER_SEC);
		if (diftime >= 1) {
			cout << "\nPasaron: " << diftime << " s" << endl;
			//Actualiza los objetos
			Simulador->ActualizarObjetos(ListaGlobalColectivos, ListaGlobalPardas, RecorridoA, RecorridoB, RecorridoC, GeneradorRandoms);
			cout << "\tObjetos Actualizados";
			time_0 = clock();
			CantidadDeSegundos++;
			if (CantidadDeSegundos % 5 == 0) {
				//Actualizar GPS
				cout << Simulador->ActualizarColectivosGPS(ListaGlobalColectivos);
				cout << "\tGPS Actualizados";
			}
		}
		if (CantidadDeSegundos == 24) //Cantidad de segundos operativos
			ciclo = false;
	}

	///////////////////////////////////////////////////////////////////////

	//Resumen del dia

	cout << "\n\n/////////////////////////////////////" << endl;

	cout << "\n\nResumen del dia";

	cout << Simulador->ResumenDelDia(ListaGlobalColectivos) << endl;

	///////////////////////////////////////////////////////////////////////

	delete ListaGlobalColectivos;
	delete ListaGlobalPardas;
	delete RecorridoA;
	delete RecorridoB;
	delete RecorridoC;
	delete GeneradorRandoms;
	delete Simulador;
	delete ListaGlobalColectiveros;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
