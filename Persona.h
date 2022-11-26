#ifndef PERSONA_H
#define PERSONA_H
#include <sstream>
#include <iostream>

using namespace std;
class Persona {
public:
	Persona();
	Persona(string *, string *, string *, string *, string *, int *);
	void setNombre(string *);
	void setCedula(string *);
	void setCorreoE(string *);
	void setDireccionEx(string *);
	void setNumTarjeta(string *);
	void setTelefonoCel(int *);
	string getNombre();
	string getCedula();
	string getCorreoE();
	string getDireccionEx();
	string getNumTarjeta();
	int getTelefonoCel();
	string toString();
	virtual ~Persona();
private:
	string *Nombre;
	string *Cedula;
	string *CorreoE;
	string *DireccionEx;
	string *NumTarjeta;
	int *TelefonoCel;
};

#endif

