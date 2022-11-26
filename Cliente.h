#ifndef CLIENTE_H
#define CLIENTE_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "Persona.h"

using namespace std;
class Cliente : public Persona {
public:
	Cliente();
	Cliente(string *, string *, string *, string *, string *, int *, bool *, int *);
	void setNPedidos(int *NPedidos);
	int getNPedidos();
	void setEstado(bool *Estado);
	bool getEstado();
	string toStringCliente();
	~Cliente();
private:
	int *NPedidos;
	bool *Estado;
	
};

#endif

