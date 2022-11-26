#include "NodoRestaurante.h"

NodoRestaurante::NodoRestaurante() {
	Info = new Restaurante();
	Sig = new NodoRestaurante();
}
NodoRestaurante::NodoRestaurante(Restaurante *R){
	this->setInfo(R);
	this->Sig=NULL;
}
void NodoRestaurante::setSig(NodoRestaurante *Sig){
	this->Sig=Sig;
}
NodoRestaurante *NodoRestaurante::getSig(){
	return this->Sig;
}
Restaurante *NodoRestaurante::getInfo(){
	return this->Info;
}
void NodoRestaurante::setInfo(Restaurante *R){
	this->Info=R;
}
NodoRestaurante::~NodoRestaurante() {
	delete Info;
	delete Sig;
}
