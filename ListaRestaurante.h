#ifndef LISTARESTAURANTE_H
#define LISTARESTAURANTE_H
#include "NodoRestaurante.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
class ListaRestaurante {
public:
	ListaRestaurante();
	void InsertarRestaurante(Restaurante *R);
	string ConsultarRestaurante(string r);
	string ConsultarNombre(string r);
	string ObtenerRestauranteMayor();
	string ObtenerRestauranteMenor();
	void AumentarPedidos(string r);
	string ListarRestaurante();
	string ListarNombres();
	void Guardar();
	void Cargar();
	bool IsEmpty();
	virtual ~ListaRestaurante();
private:
	NodoRestaurante *cabeza;
	NodoRestaurante *actual;
};
#endif

