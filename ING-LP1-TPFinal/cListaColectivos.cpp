#include "cListaColectivos.h"

cListaColectivos::cListaColectivos() : cListaTemplate<cColectivo>() {

}

cListaColectivos::cListaColectivos(unsigned int TamMax, bool borrar):cListaTemplate<cColectivo>(TamMax, borrar) {

}

cListaColectivos::~cListaColectivos(){

}
