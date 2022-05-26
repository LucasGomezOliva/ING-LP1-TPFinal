#include "cListaParadas.h"
cListaParadas::cListaParadas() :cListaTemplate<cParada>() {

}

cListaParadas::cListaParadas(unsigned int TamMax, bool borrar) : cListaTemplate<cParada>(TamMax, borrar) {

}

cListaParadas::~cListaParadas() {

}