#include "cColectivoSinAire.h"
cColectivoSinAire::cColectivoSinAire():cColectivo() {

}

cColectivoSinAire::cColectivoSinAire(string IDColectivo,cRecorrido* RecorridoAsignado):cColectivo(IDColectivo,RecorridoAsignado) {

}
cColectivoSinAire::~cColectivoSinAire() {

}

string cColectivoSinAire::ToStringColectivoSinAire() {
	return ToStringColectivo();
}
void cColectivoSinAire::Imprimir() {

}