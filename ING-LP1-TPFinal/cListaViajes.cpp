#include "cListaViajes.h"

cListaViajes::cListaViajes():cListaTemplate<cViaje>() {
}

cListaViajes::cListaViajes(unsigned int TamMax, bool borrar):cListaTemplate<cViaje>(TamMax, borrar) {
}

cListaViajes::~cListaViajes()
{
}
