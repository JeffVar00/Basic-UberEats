#ifndef NODOQUEJA_H
#define NODOQUEJA_H
#include "Queja.h"
#include <iostream>

using namespace std;
class NodoQueja {
public:
	NodoQueja();
	NodoQueja(Queja *Q);
	void setInfo(Queja *Q);
	Queja *getInfo();
	void setSig(NodoQueja *Sig);
	NodoQueja *getSig();
	virtual ~NodoQueja();
private:
	Queja *Info;
	NodoQueja *Sig;
};

#endif
