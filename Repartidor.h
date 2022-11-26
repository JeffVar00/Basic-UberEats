#ifndef REPARTIDOR_H
#define REPARTIDOR_H
#include <fstream>
#include <stdlib.h>
#include "Persona.h"

using namespace std;
class Repartidor : public Persona {
public:
	Repartidor();
	Repartidor(string *, string *, string *, string *, string *, int *, float *, float *, int *, string *);
	void setDistanciaP(float *DistanciaP);
	void setKRecorridos(float *KRecorridos);
	void setNumAmonestaciones(int *NumAmonestaciones);
	void setDisp(string *Disp);
	float getDistanciaP();
	float getKRecorridos();
	int getNumAmonestaciones();
	string getDisp();
	string toStringRepartidor();
	virtual ~Repartidor();
private:
	float *DistanciaP;
	float *KRecorridos;
	int *NumAmonestaciones;
	string *Disp;
};
#endif

