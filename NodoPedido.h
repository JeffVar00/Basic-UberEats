#ifndef NODOPEDIDO_H
#define NODOPEDIDO_H
#include "Pedido.h"
#include <iostream>

using namespace std;
class NodoPedido {
public:
	NodoPedido();
	NodoPedido(Pedido *P);
	void setInfo(Pedido *P);
	Pedido *getInfo();
	void setSig(NodoPedido *Sig);
	NodoPedido *getSig();
	virtual ~NodoPedido();
private:
	Pedido *Info;
	NodoPedido *Sig;
};

#endif

