#ifndef LISTAPEDIDO_H
#define LISTAPEDIDO_H
#include "NodoPedido.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class ListaPedido {
public:
	ListaPedido();
	void InsertarPedido(Pedido *P);
	string ConsultarPedido(int p);
	string ListarPedido();
	string ListarCedula(string c);
	float TotalVentasRest(string r);
	float TotalVentas();
	int Contar();
	void Guardar();
	void Cargar();
	bool IsEmpty();
	virtual ~ListaPedido();
private:
	NodoPedido *cabeza;
	NodoPedido *actual;
};

#endif

