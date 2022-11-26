#ifndef NODORESTAURANTE_H
#define NODORESTAURANTE_H
#include <iostream>
#include "Restaurante.h"
using namespace std;
class NodoRestaurante {
public:
	NodoRestaurante();
	NodoRestaurante(Restaurante *R);
	void setInfo(Restaurante *R);
	Restaurante *getInfo();
	void setSig(NodoRestaurante *Sig);
	NodoRestaurante *getSig();
	virtual ~NodoRestaurante();
private:
	Restaurante *Info;
	NodoRestaurante *Sig;
};
#endif

