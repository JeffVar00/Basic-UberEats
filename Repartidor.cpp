#include "Repartidor.h"

Repartidor::Repartidor() {
	//Persona
	this->setNombre(new string(""));
	this->setCedula(new string(""));
	this->setCorreoE(new string(""));
	this->setDireccionEx(new string(""));
	this->setNumTarjeta(new string(""));
	this->setTelefonoCel(new int(0));
	//Repartidor
	this->DistanciaP = new float();
	this->KRecorridos = new float();
	this->NumAmonestaciones = new int();
	this->Disp= new string();
	*Disp="Disponible";
}
Repartidor::Repartidor(string *Nombre, string *Cedula, string *CorreoE, string *DireccionEx, string *NumTarjeta, int *TelefonoCel, float *DistanciaP, float *KRecorridos, int *NumAmonestaciones, string *Disp){
	//Persona
	this->setNombre(Nombre);
	this->setCedula(Cedula);
	this->setCorreoE(CorreoE);
	this->setDireccionEx(DireccionEx);
	this->setNumTarjeta(NumTarjeta);
	this->setTelefonoCel(TelefonoCel);
	//Repartidor
	this->DistanciaP=DistanciaP;
	this->KRecorridos=KRecorridos;
	this->NumAmonestaciones=NumAmonestaciones;
	this->Disp=Disp;
}
void Repartidor::setDistanciaP(float *DistanciaP){
	this->DistanciaP=DistanciaP;
}
void Repartidor::setKRecorridos(float *KRecorridos){
	this->KRecorridos=KRecorridos;
}
void Repartidor::setNumAmonestaciones(int *NumAmonestaciones){
	this->NumAmonestaciones=NumAmonestaciones;
}
void Repartidor::setDisp(string *Disp){
	this->Disp=Disp;
}
float Repartidor::getDistanciaP(){
	return *DistanciaP;
}
float Repartidor::getKRecorridos(){
	return *KRecorridos;
}
int Repartidor::getNumAmonestaciones(){
	return *NumAmonestaciones;
}
string Repartidor::getDisp(){
	return *Disp;
}
string Repartidor::toStringRepartidor(){
	stringstream r;
	r<<"------------------------------------------"<<endl;
	r<<"Info de Repartidor"<<endl;
	r<<toString();
	r<<"Kilometros Recorridos: "<<getKRecorridos()<<" km"<<endl;
	r<<"Num. de Amonestaciones: "<<getNumAmonestaciones()<<endl;
	r<<"Estado: "<<getDisp()<<endl;
	return r.str();
}
Repartidor::~Repartidor() {
	delete DistanciaP;
	delete KRecorridos;
	delete NumAmonestaciones;
	delete Disp;
}

