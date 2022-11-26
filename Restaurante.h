#ifndef RESTAURANTE_H
#define RESTAURANTE_H
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;
class Restaurante {
public:
	Restaurante();
	Restaurante(string *, string *, string *, string *, int *);
	void setNombre(string *);
	void setCedJud(string *);
	void setDireccion(string *);
	void setTipoComida(string *);
	void setNPedidosR(int *);
	string getNombre();
	string getCedJud();
	string getDireccion();
	string getTipoComida();
	int getNPedidosR();
	string toStringRestaurante();
	string toStringRestCliente();
	~Restaurante();
private:
	string *Nombre;
	string *CedJud;
	string *Direccion;
	string *TipoComida;
	int *NPedidosR;
};

#endif

