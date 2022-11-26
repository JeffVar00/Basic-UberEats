#ifndef PEDIDO_H
#define PEDIDO_H
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;
class Pedido {
public:
	Pedido();
	Pedido(int *, int *, int *, int *, int *, string *, float *, float *, string *, string *, string *);
	void setID(int *);
	void setHoraPedido(int *);
	void setMinutoPedido(int *);
	void setHoraEntregado(int *);
	void setMinutoEntregado(int *);
	void setEstado(string *);
	void setSubTotal(float *);
	void setTotal(float *);
	void setFeriado(bool *);
	void setNRest(string *);
	void setCedR(string *);
	void setCedP(string *);
	int getID();
	int getHoraPedido();
	int getMinutoPedido();
	int getHoraEntregado();
	int getMinutoEntregado();
	bool getFeriado();
	string getNRest(); //nombre del restaurante
	string getCedR();
	string getCedP();
	string getEstado();
	float getSubTotal();
	float getTotal();
	string toStringPedido();
	~Pedido();
private:
	int *ID;
	int *HoraPedido;
	int *MinutoPedido;
	int *HoraEntregado;
	int *MinutoEntregado;
	string *Estado;
	float *SubTotal;
	float *Total;
	bool *Feriado;
	string *NRest; //Cedula del Restaurante elegido
    string *CedP; //Cedula de la persona que mando a realizar el Pedido
	string *CedR; //Cedula del Repartidor Asignado
};

#endif

