#include "NodoPedido.h"

NodoPedido::NodoPedido() {
	Info = new Pedido();
	Sig = new NodoPedido();
}
NodoPedido::NodoPedido(Pedido *P){
	this->setInfo(P);
	this->Sig=NULL;
}
void NodoPedido::setSig(NodoPedido *Sig){
	this->Sig=Sig;
}
NodoPedido *NodoPedido::getSig(){
	return this->Sig;
}
Pedido *NodoPedido::getInfo(){
	return this->Info;
}
void NodoPedido::setInfo(Pedido *P){
	this->Info=P;
}
NodoPedido::~NodoPedido() {
	delete Info;
	delete Sig;
}
