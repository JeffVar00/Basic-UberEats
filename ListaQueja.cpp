#include "ListaQueja.h"

ListaQueja::ListaQueja() {
	cabeza=actual=NULL;
}
bool ListaQueja::IsEmpty(){
	return cabeza==NULL;
}
void ListaQueja::InsertarQueja(Queja *Q){
	NodoQueja *aux = new NodoQueja(Q);
	if(IsEmpty()){
		cabeza=aux;
	}else{
		actual=cabeza;
		while(actual->getSig()!=NULL){
			actual=actual->getSig();
		}
		actual->setSig(aux);
	}
}
string ListaQueja::EliminarQueja(string c){
	if(IsEmpty()){
		return "0";
	}else{
		actual=cabeza;
		NodoQueja *aux = cabeza;
		if(cabeza->getInfo()->getCed()==c){
			cabeza=cabeza->getSig();
			delete actual;
			return "1";
		}else{
			while(actual->getSig()!=NULL){
				if(actual->getInfo()->getCed()==c){
					aux=actual->getSig();
					actual->setSig(aux->getSig());
				}else{
					actual=actual->getSig();
				}
			}
			if(actual->getSig()==NULL){
				return "-1";
			}else{
				return "1";
			}
		}
		delete aux;
	}
}

string ListaQueja::ListarQuejas(string c){
	stringstream cadena;
	actual=cabeza;
	if(IsEmpty()){
		return "0";
	}else{
		while(actual!=NULL){
			if(actual->getInfo()->getCed()==c){
				cadena<<actual->getInfo()->toStringQueja();
			}
			actual=actual->getSig();
		}
		return cadena.str();
	}
}
void ListaQueja::Guardar(){
	
	if(IsEmpty()){
		return;
	} 
	ofstream Archivo("Quejas.txt");
	actual=cabeza;
	while(actual!=NULL){
		Archivo<<actual->getInfo()->getDescrip()<<","<<actual->getInfo()->getCed()<<endl;
		actual=actual->getSig();
	}
	Archivo.close();
}

void ListaQueja::Cargar(){
	ifstream Archivo;
	Archivo.open("Quejas.txt");
	if(Archivo){
		while(!Archivo.eof()){
			string *Descrip = new string();
			string *Ced = new string();
			getline(Archivo,*Descrip,',');
			getline(Archivo,*Ced);
			
			if(!Archivo.eof()){
				/*cout<<"Queja: "<<endl;
				cout<<"Descripcion"<<endl;
				cout<<*Descrip<<endl;
				cout<<"Cedula: "<<*Ced<<endl<<endl;*/
				Queja *c= new Queja(Ced, Descrip);
				InsertarQueja(c);
			}
			
		}
	}
	Archivo.close();
}
ListaQueja::~ListaQueja() {
	while(cabeza!=NULL){
		this->actual=cabeza;
		cabeza=cabeza->getSig();
		delete actual;
	}
}


