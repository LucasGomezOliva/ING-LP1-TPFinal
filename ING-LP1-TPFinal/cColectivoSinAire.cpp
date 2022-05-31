#include "cColectivoSinAire.h"
cColectivoSinAire::cColectivoSinAire():cColectivo() {

}

cColectivoSinAire::cColectivoSinAire(cRecorrido* RecorridoAsignado):cColectivo(RecorridoAsignado) {

}
cColectivoSinAire::~cColectivoSinAire() {

}

string cColectivoSinAire::ToStringColectivoSinAire() {
	return ToStringColectivo();
}
void cColectivoSinAire::Imprimir() {
	cout << "Imprimir";
}