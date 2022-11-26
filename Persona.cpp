#include "Persona.h"

Persona::Persona() {
	this->Nombre=new string();
	this->Cedula=new string();
	this->CorreoE=new string();
	this->DireccionEx=new string();
	this->NumTarjeta=new string();
	this->TelefonoCel=new int;
}
Persona::Persona(string *Nombre, string *Cedula, string *CorreoE, string *DireccionEx, string *NumTarjeta, int *TelefonoCel){
	this->Nombre=Nombre;
	this->Cedula=Cedula;
	this->CorreoE=CorreoE;
	this->DireccionEx=DireccionEx;
	this->NumTarjeta=NumTarjeta;
	this->TelefonoCel=TelefonoCel;
}
void Persona::setNombre(string *Nombre){
	this->Nombre=Nombre;
}
void Persona::setCedula(string *Cedula){
	this->Cedula=Cedula;
}
void Persona::setCorreoE(string *CorreoE){
	this->CorreoE=CorreoE;
}
void Persona::setDireccionEx(string *DireccionEx){
	this->DireccionEx=DireccionEx;
}
void Persona::setNumTarjeta(string *NumTarjeta){
	this->NumTarjeta=NumTarjeta;
}
void Persona::setTelefonoCel(int *TelefonoCel){
	this->TelefonoCel=TelefonoCel;
}
string Persona::getNombre(){
	return *Nombre;
}
string Persona::getCedula(){
	return *Cedula;
}
string Persona::getCorreoE(){
	return *CorreoE;
}
string Persona::getDireccionEx(){
	return *DireccionEx;
}
string Persona::getNumTarjeta(){
	return *NumTarjeta;
}
int Persona::getTelefonoCel(){
	return *TelefonoCel;
}
string Persona::toString(){
	stringstream x;
	x<<"Nombre: "<<getNombre()<<endl;
	x<<"Cedula: "<<getCedula()<<endl;
	x<<"Correo Electronico: "<<getCorreoE()<<endl;
	x<<"Direccion Exacta: "<<getDireccionEx()<<endl;
	x<<"Numero de Tarjeta: "<<getNumTarjeta()<<endl;
	x<<"Telefono: "<<getTelefonoCel()<<endl;
	return x.str();
}
Persona::~Persona() {
	delete Nombre; delete Cedula; delete CorreoE; delete DireccionEx; delete NumTarjeta; delete TelefonoCel;
}

