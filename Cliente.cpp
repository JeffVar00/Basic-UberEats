#include "Cliente.h"

Cliente::Cliente() {
	//Persona
	this->setNombre(new string(""));
	this->setCedula(new string(""));
	this->setCorreoE(new string(""));
	this->setDireccionEx(new string(""));
	this->setNumTarjeta(new string(""));
	this->setTelefonoCel(new int(0));
	//Cliente
	this->Estado = new bool();
	this->NPedidos = new int();
}
Cliente::Cliente(string *Nombre, string *Cedula, string *CorreoE, string *DireccionEx, string *NumTarjeta, int *TelefonoCel, bool *Estado, int *NPedidos){
	//Persona
	this->setNombre(Nombre);
	this->setCedula(Cedula);
	this->setCorreoE(CorreoE);
	this->setDireccionEx(DireccionEx);
	this->setNumTarjeta(NumTarjeta);
	this->setTelefonoCel(TelefonoCel);
	//Cliente
	this->Estado=Estado;
	this->NPedidos=NPedidos;
}
void Cliente::setEstado(bool *Estado){
	this->Estado=Estado;
}
bool Cliente::getEstado(){
	return *Estado;
}
void Cliente::setNPedidos(int *NPedidos){
	this->NPedidos=NPedidos;
}
int Cliente::getNPedidos(){
	return *NPedidos;
}
string Cliente::toStringCliente(){
	stringstream c;
	c<<"---------------------------------"<<endl;
	c<<"Info del Cliente"<<endl;
	c<<toString();
	if(getEstado()==true){
		c<<"Cliente Activo"<<endl;
	}else{
		c<<"Cliente Inactivo"<<endl;
	}
	c<<"Numero de pedidos: "<<*NPedidos<<endl;
	return c.str();
}
Cliente::~Cliente() {
	delete Estado;
	delete NPedidos;
}
