#ifndef NODOREPARTIDOR_H
#define NODOREPARTIDOR_H
#include <iostream>
#include "Repartidor.h"

using namespace std;
class NodoRepartidor {
public:
	NodoRepartidor();
	NodoRepartidor(Repartidor *R);
	void setInfo(Repartidor *R);
	Repartidor *getInfo();
	void setSig(NodoRepartidor *Sig);
	NodoRepartidor *getSig();
	virtual ~NodoRepartidor();
private:
	Repartidor *Info;
	NodoRepartidor *Sig;
};

#endif

