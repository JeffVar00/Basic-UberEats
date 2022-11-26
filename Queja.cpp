#include "Queja.h"

Queja::Queja() {
	Ced= new string();
	Descrip= new string();
}
Queja::Queja(string *Ced, string *Descrip){
	this->Ced=Ced;
	this->Descrip=Descrip;
}
void Queja::setCed(string *Ced){
	this->Ced=Ced;
}
void Queja::setDescrip(string *Descrip){
	this->Descrip=Descrip;
}
string Queja::getCed(){
	return *Ced;
}
string Queja::getDescrip(){
	return *Descrip;
}
string Queja::toStringQueja(){
	stringstream p;
	p<<"--------------------------------------"<<endl;
	p<<"Descripcion: "<<endl;
	p<<*Descrip<<endl;
	return p.str();
}
Queja::~Queja() {
	delete Ced;
	delete Descrip;
}

