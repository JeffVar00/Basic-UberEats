#ifndef NODOCLIENTE_H
#define NODOCLIENTE_H
#include "Cliente.h"

using namespace std;
class NodoCliente {
public:
	NodoCliente();
	NodoCliente(Cliente *C);
	void setInfo(Cliente *C);
	Cliente *getInfo();
	void setSig(NodoCliente *Sig);
	NodoCliente *getSig();
	virtual ~NodoCliente();
private:
	Cliente *Info;
	NodoCliente *Sig;
};

#endif
