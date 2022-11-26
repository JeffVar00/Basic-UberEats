#ifndef LISTAQUEJA_H
#define LISTAQUEJA_H
#include "NodoQueja.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <windows.h> 

using namespace std;
class ListaQueja {
public:
	ListaQueja();
	void InsertarQueja(Queja *Q);
	string ListarQuejas(string c);
	string EliminarQueja(string c);
	void Guardar();
	void Cargar();
	bool IsEmpty();
	virtual ~ListaQueja();
private:
	NodoQueja *cabeza;
	NodoQueja *actual;
};
#endif

