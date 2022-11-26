#include "Pedido.h"

Pedido::Pedido() {
	ID= new int();
	HoraPedido=new int();
	MinutoPedido=new int();
	HoraEntregado=new int();
	MinutoEntregado=new int();
	Estado=new string();
	SubTotal=new float();
	Total= new float();
	Feriado= new bool;
	*Feriado=false;
	CedR= new string();
	NRest= new string();
	//*NRest=" ";
	CedP= new string();
}
Pedido::Pedido(int *ID, int *HoraPedido, int *MinutoPedido, int *HoraEntregado, int *MinutoEntregado, string *Estado, float *SubTotal, float *Total, string *CedP, string *CedR, string *NRest){
	this->ID=ID;
	this->HoraPedido=HoraPedido;
	this->MinutoPedido=MinutoPedido;
	this->HoraEntregado=HoraEntregado;
	this->MinutoEntregado=MinutoEntregado;
	this->Estado=Estado;
	this->SubTotal=SubTotal;
	this->Total=Total;
	this->CedR=CedR;
	this->CedP=CedP;
	this->NRest=NRest;
}
void Pedido::setID(int *ID){
	this->ID=ID;
}
int Pedido::getID(){
	return *ID;
}

void Pedido::setHoraPedido(int *HoraPedido){
	this->HoraPedido=HoraPedido;
}
int Pedido::getHoraPedido(){
	return *HoraPedido;
}

void Pedido::setMinutoPedido(int *MinutoPedido){
	this->MinutoPedido=MinutoPedido;
}
int Pedido::getMinutoPedido(){
	return *MinutoPedido;
}

void Pedido::setHoraEntregado(int *HoraEntregado){
	this->HoraEntregado=HoraEntregado;
}
int Pedido::getHoraEntregado(){
	return *HoraEntregado;
}

void Pedido::setMinutoEntregado(int *MinutoEntregado){
	this->MinutoEntregado=MinutoEntregado;
}
int Pedido::getMinutoEntregado(){
	return *MinutoEntregado;
}

void Pedido::setEstado(string *Estado){
	this->Estado=Estado;
}
string Pedido::getEstado(){
	return *Estado;
}

void Pedido::setSubTotal(float *SubTotal){
	this->SubTotal=SubTotal;
}
float Pedido::getSubTotal(){
	return *SubTotal;
}

void Pedido::setTotal(float *Total){
	this->Total=Total;
}
float Pedido::getTotal(){
	return *Total;
}
void Pedido::setFeriado(bool *Feriado){
	this->Feriado=Feriado;
}
bool Pedido::getFeriado(){
	return *Feriado;
}
void Pedido::setCedP(string *CedP){
	this->CedP=CedP;
}
string Pedido::getCedP(){
	return *CedP;
}
void Pedido::setCedR(string *CedR){
	this->CedR=CedR;
}
string Pedido::getCedR(){
	return *CedR;
}
void Pedido::setNRest(string *NRest){
	this->NRest=NRest;
}
string Pedido::getNRest(){
	return *NRest;
}

string Pedido::toStringPedido(){
	stringstream p;
	p<<"--------------------------------------"<<endl;
	p<<"Info del Pedido"<<endl;
	p<<"ID: "<<getID()<<endl;
	p<<"Estado: "<<getEstado()<<endl;
	p<<"Hora Pedido: "<<getHoraPedido()<<endl;
	p<<"Minuto Pedido: "<<getMinutoPedido()<<endl;
	p<<"Hora Entregado: "<<getHoraEntregado()<<endl;
	p<<"Minuto Entregado: "<<getMinutoEntregado()<<endl;
	p<<"SubTotal: "<<getSubTotal()<<" Colones"<<endl;
	p<<"Total: "<<getTotal()<<" Colones"<<endl;
	p<<"Restaurante: "<<getNRest()<<endl;
	p<<"Cedula del repartidor asignado: "<<getCedR()<<endl; //por si desea realizar alguna queja
	return p.str();
}
Pedido::~Pedido() {
	delete HoraPedido;
	delete MinutoPedido;
	delete MinutoEntregado;
	delete HoraEntregado;
	delete Estado;
	delete SubTotal;
	delete Total;
	delete CedR;
	delete NRest;
	delete CedP;
}

