#include "NodoRepartidor.h"

NodoRepartidor::NodoRepartidor() {
	Info = new Repartidor();
	Sig = new NodoRepartidor();
}
NodoRepartidor::NodoRepartidor(Repartidor *R){
	this->setInfo(R);
	this->Sig=NULL;
}
void NodoRepartidor::setSig(NodoRepartidor *Sig){
	this->Sig=Sig;
}
NodoRepartidor *NodoRepartidor::getSig(){
	return this->Sig;
}
Repartidor *NodoRepartidor::getInfo(){
	return this->Info;
}
void NodoRepartidor::setInfo(Repartidor *R){
	this->Info=R;
}
NodoRepartidor::~NodoRepartidor() {
	delete Info;
	delete Sig;
}
