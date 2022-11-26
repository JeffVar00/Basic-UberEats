#ifndef LISTAREPARTIDOR_H
#define LISTAREPARTIDOR_H
#include "NodoRepartidor.h"
#include <iostream>
#include <fstream>
#include <sstream>
 
using namespace std;
class ListaRepartidor {
public:
	ListaRepartidor();
	void InsertarRepartidor(Repartidor *R);
	string ConsultarRepartidor(string r);
	string ListarRepartidor();
	string AsignarCedula();
	void AumentarKM(float k, string r);
	int ConsultarAmonestaciones(string r);
	void AumentarAmonestaciones(string r);
	void SuspenderRepartidor(string r);
	void Guardar();
	void Cargar();
	bool IsEmpty();
	virtual ~ListaRepartidor();
private:
	NodoRepartidor *cabeza;
	NodoRepartidor *actual;
};

#endif

