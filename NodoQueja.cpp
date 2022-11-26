#include "NodoQueja.h"

NodoQueja::NodoQueja() {
	Info = new Queja();
	Sig = new NodoQueja();
}
NodoQueja::NodoQueja(Queja *Q){
	this->setInfo(Q);
	this->Sig=NULL;
}
void NodoQueja::setSig(NodoQueja *Sig){
	this->Sig=Sig;
}
NodoQueja *NodoQueja::getSig(){
	return this->Sig;
}
Queja *NodoQueja::getInfo(){
	return this->Info;
}
void NodoQueja::setInfo(Queja *Q){
	this->Info=Q;
}
NodoQueja::~NodoQueja() {
	delete Info;
	delete Sig;
}
