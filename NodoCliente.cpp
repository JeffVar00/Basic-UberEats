#include "NodoCliente.h"

NodoCliente::NodoCliente() {
	Info = new Cliente();
	Sig = new NodoCliente();
}
NodoCliente::NodoCliente(Cliente *C){
	this->setInfo(C);
	this->Sig=NULL;
}
void NodoCliente::setSig(NodoCliente *Sig){
	this->Sig=Sig;
}
NodoCliente *NodoCliente::getSig(){
	return this->Sig;
}
Cliente *NodoCliente::getInfo(){
	return this->Info;
}
void NodoCliente::setInfo(Cliente *C){
	this->Info=C;
}
NodoCliente::~NodoCliente() {
	delete Info;
	delete Sig;
}
