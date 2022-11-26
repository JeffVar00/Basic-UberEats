#ifndef LISTACLIENTE_H
#define LISTACLIENTE_H
#include "NodoCliente.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <windows.h> 

using namespace std;
class ListaCliente {
public:
	ListaCliente();
	void InsertarCliente(Cliente *C);
	string ConsultarCliente(string c);
	string ListarClienteActivo();
	string ListarClienteInactivo();
	string ObtenerClienteDestacado();
	void AumentarPedidos(string c);
	void ActivarCliente(string c);
	void Guardar();
	void Cargar();
	bool IsEmpty();
	virtual ~ListaCliente();
private:
	NodoCliente *cabeza;
	NodoCliente *actual;
};
#endif

