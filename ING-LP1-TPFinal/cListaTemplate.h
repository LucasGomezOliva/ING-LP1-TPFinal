#pragma once
#include <exception>
#include <string>
#include <iostream>
using namespace std;
#define SIZE 100
template <class T>
class cListaTemplate
{
protected:

	T** Array;
	unsigned int CantidadActual;
	unsigned int TamMax;
	bool borrar;
	bool duplicados;

public:

#pragma region Constructores y destructores

	/// <summary>
	/// Constructor de la clase ListaTemplate.
	/// </summary>
	/// <param name="TamMax"></param>
	/// <param name="borrar"></param>
	cListaTemplate(unsigned int TamMax = SIZE, bool borrar = false);

	/// <summary>
	/// Destructor de la clase ListaTemplate
	/// </summary>
	~cListaTemplate();

#pragma endregion

#pragma region Metodos

	/// <summary>
	/// Agrega un objeto a la lista.
	/// </summary>
	/// <param name="objeto"></param>
	void Agregar(T* objeto);

	/// <summary>
	/// Quita un objeto a la lista.
	/// </summary>
	/// <param name="objeto"></param>
	T* Quitar(T* objeto);

	/// <summary>
	/// Retorna la pos de un objeto
	/// </summary>
	/// <param name="objeto"></param>
	/// <returns>int</returns>
	int getPos(T* objeto);

	/// <summary>
	/// Imprime los objetos a la lista.
	/// </summary>
	void Listar();

#pragma endregion

#pragma region Sobrecarga Operadores

	/// <summary>
	/// Agrega un objeto a la lista.
	/// </summary>
	/// <param name="objeto"></param>
	void operator+(T* objeto);

	/// <summary>
	/// Quita un objeto a la lista.
	/// </summary>
	/// <param name="objeto"></param>
	void operator-(T* objeto);

	/// <summary>
	/// Busca un objeto en la Lista.
	/// </summary>
	/// <param name="pos"></param>
	/// <returns>Objeto</returns>
	T* operator[](unsigned int pos);

#pragma endregion

};

template <class T>
inline cListaTemplate <T>::cListaTemplate(unsigned int TamMax, bool borrar) {
	this->TamMax = TamMax;
	CantidadActual = 0;
	Array = new T * [TamMax];
	for (unsigned int i = 0; i < TamMax; i++){
		Array[i] = NULL;
	}
	this->borrar = borrar;
	this->duplicados = false;
}

template <class T>
inline cListaTemplate <T>::~cListaTemplate() {
	if (Array != NULL) {
		if (borrar) {
			for (unsigned int i = 0; i < CantidadActual; i++) {
				if (Array[i] != NULL)
					delete Array[i];
			}
		}
		delete[] Array;
	}
	Array = NULL;
}

template <class T>
inline void cListaTemplate <T>::Agregar(T* objeto) {

	int pos = getPos(objeto);
	bool hay_lugar = CantidadActual < TamMax;
	if (!hay_lugar)
		throw exception("No Hay Lugar");
	if (pos >= 0 && !duplicados)
		throw exception("ya esta en la lista");
	Array[CantidadActual++] = objeto;
}

template <class T>
inline T*cListaTemplate <T>::Quitar(T* objeto) {
	int pos = getPos(objeto);
	if (pos < 0)
		return NULL;
	T* aux = Array[pos];
	for (unsigned int i = pos; i < CantidadActual - 1; i++) {
		Array[i] = Array[i + 1];
	}
	CantidadActual--;
	Array[CantidadActual] = NULL;
	return aux;
}

template <class T>
inline int cListaTemplate <T>::getPos(T* objeto) {
	for (unsigned int i = 0; i < CantidadActual; i++) {
		if (*objeto == *(Array[i]))
			return i;
	}
	return -1;
}

template <class T>
inline void cListaTemplate <T>::Listar() {
	for (unsigned int i = 0; i < CantidadActual; i++) {
		cout << Array[i] << endl;
	}
}

template <class T>
inline void cListaTemplate <T>::operator+(T* objeto) {
	Agregar(objeto);
}

template <class T>
inline void cListaTemplate <T>::operator-(T* objeto) {
	Quitar(objeto);
}

template <class T>
inline T* cListaTemplate <T>::operator[](unsigned int pos) {
	if (pos < CantidadActual)
		return Array[pos];
	else
		return NULL;
}
