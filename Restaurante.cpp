#include "Restaurante.h"

Restaurante::Restaurante() {
	Nombre=new string();
	CedJud=new string();
	Direccion=new string();
	TipoComida=new string();
	NPedidosR= new int();
}
Restaurante::Restaurante(string *Nombre, string *CedJud, string *Direccion, string *TipoComida, int *NPedidosR){
	this->Nombre=Nombre;
	this->CedJud=CedJud;
	this->Direccion=Direccion;
	this->TipoComida=TipoComida;
	this->NPedidosR=NPedidosR;
}
void Restaurante::setNombre(string *Nombre){
	this->Nombre=Nombre;
}
string Restaurante::getNombre(){
	return *Nombre;
}

void Restaurante::setCedJud(string *CedJud){
	this->CedJud=CedJud;
}
string Restaurante::getCedJud(){
	return *CedJud;
}

void Restaurante::setDireccion(string *Direccion){
	this->Direccion=Direccion;
}
string Restaurante::getDireccion(){
	return *Direccion;
}

void Restaurante::setTipoComida(string *TipoComida){
	this->TipoComida=TipoComida;
}
string Restaurante::getTipoComida(){
	return *TipoComida;
}
void Restaurante::setNPedidosR(int *NPedidosR){
	this->NPedidosR=NPedidosR;
}
int Restaurante::getNPedidosR(){
	return *NPedidosR;
}
string Restaurante::toStringRestaurante(){
	stringstream r;
	r<<"------------------------------------------"<<endl;
	r<<"Info del Restaurante"<<endl;
	r<<"Nombre: "<<getNombre()<<endl;
	r<<"Cedula Juridica: "<<getCedJud()<<endl;
	r<<"Direccion: "<<getDireccion()<<endl;
	r<<"Tipo de comida: "<<getTipoComida()<<endl;
    r<<"Numero de pedidos realizados en este restaurante: "<<getNPedidosR()<<endl;
	return r.str();
}
string Restaurante::toStringRestCliente(){
	stringstream r;
	r<<"------------------------------------------"<<endl;
	r<<"Nombre: "<<getNombre()<<", Tipo de comida: "<<getTipoComida()<<endl;
	return r.str();
}
Restaurante::~Restaurante() {
	delete Nombre;
	delete CedJud;
	delete Direccion;
	delete TipoComida;
}

