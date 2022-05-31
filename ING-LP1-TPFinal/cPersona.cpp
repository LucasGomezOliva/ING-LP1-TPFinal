#include "cPersona.h"

cPersona::cPersona(){
	this->Nombre = "";
	this->DNI = "";
}

cPersona::cPersona(string Nombre, string DNI){
	this->Nombre = Nombre;
	this->DNI = DNI;
}

cPersona::~cPersona(){

}
