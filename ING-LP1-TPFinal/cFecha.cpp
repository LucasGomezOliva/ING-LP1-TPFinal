#include "cFecha.h"
cFecha::cFecha() {
	fecha.tm_hour = 0;
	fecha.tm_min = 0;
	fecha.tm_sec = 0;
	fecha.tm_mday = 0;
	fecha.tm_mon = 0;
	fecha.tm_year = 0;
	fecha.tm_wday = 0;
	fecha.tm_yday = 0;
	fecha.tm_isdst = 0;
}

cFecha::cFecha(unsigned int dia, unsigned int mes, unsigned int anio, unsigned int hora, unsigned int minutos) {
	fecha.tm_hour = hora;
	fecha.tm_min = minutos;
	fecha.tm_sec = 0;
	fecha.tm_mday = dia;
	fecha.tm_mon = mes - 1;
	fecha.tm_year = anio - 1900;
	fecha.tm_wday = 0;
	fecha.tm_yday = 0;
	fecha.tm_isdst = 0;
}

cFecha::~cFecha() {

}

unsigned int cFecha::getDia() const {
	return fecha.tm_mday; 
}

unsigned int cFecha::getMes() const { 
	return fecha.tm_mon; 
}

unsigned int cFecha::getAnio() const { 
	return fecha.tm_year; 
}

unsigned int cFecha::getHora() const { 
	return fecha.tm_hour; 
}

unsigned int cFecha::getMinutos() const { 
	return fecha.tm_min; 
}

bool cFecha::CompararFechas(cFecha* fecha) {
	double timedif = 0;
	time_t FechaActual = 0;
	time(&FechaActual);
	time_t fecha1 = mktime(&(fecha->fecha));
	timedif = difftime(FechaActual, fecha1);
	if (timedif < 72000)//Tiempo en segundos para la comparacion
		return true;
	else
		return false;
}

string cFecha::to_stringFecha() const {
	return "\tFecha: " + to_string(fecha.tm_mday) + "/" + to_string(fecha.tm_mon + 1) + "/" + to_string(fecha.tm_year + 1900) +
		"\t Hora:" + to_string(fecha.tm_hour) + ":" + to_string(fecha.tm_min);
}

void cFecha::imprimir() const {
	cout << to_stringFecha() << endl;
}