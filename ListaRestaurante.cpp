#include "ListaRestaurante.h"

ListaRestaurante::ListaRestaurante() {
	cabeza=actual=NULL;
}
bool ListaRestaurante::IsEmpty(){
	return cabeza==NULL;
}
void ListaRestaurante::InsertarRestaurante(Restaurante *R){
	NodoRestaurante *aux = new NodoRestaurante(R);
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
string ListaRestaurante::ObtenerRestauranteMayor(){
	int mayor=0;
	actual=cabeza;
	string aux;
	if(IsEmpty()){
		return "0";
	}else{
		while(actual!=NULL){
			if(actual->getInfo()->getNPedidosR()>mayor){
				aux=actual->getInfo()->toStringRestaurante();
				mayor=actual->getInfo()->getNPedidosR();
			}
			actual=actual->getSig();
		}
		if(mayor==0){
			return "-1";
		}
		return aux;
	}
	return 0;
	
}
string ListaRestaurante::ObtenerRestauranteMenor(){
	int menor=100000;
	actual=cabeza;
	string aux;
	if(IsEmpty()){
		return "0";
	}else{
		while(actual!=NULL){
			if(actual->getInfo()->getNPedidosR()<menor){
				aux=actual->getInfo()->toStringRestaurante();
				menor=actual->getInfo()->getNPedidosR();
			}
			actual=actual->getSig();
		}
		if(menor==0){
			return "-1";
		}
		return aux;
	}
	return 0;
	
}
void ListaRestaurante::AumentarPedidos(string r){
	actual=cabeza;
	int *aux= new int();
	bool n=true;
	while(actual!=NULL && n==true){
		if(actual->getInfo()->getNombre()==r){
			*aux=actual->getInfo()->getNPedidosR();
			*aux+=1;
			actual->getInfo()->setNPedidosR(aux);
			n = false;
		}
		actual=actual->getSig();
	}
}
string ListaRestaurante::ConsultarRestaurante(string r){
	actual=cabeza;
	if(IsEmpty()){
		return "0";
	}else{
		bool n = true;
		while(actual!=NULL && n==true){
			if(actual->getInfo()->getCedJud()==r){
				n = false;
				return actual->getInfo()->toStringRestaurante();
			}
			actual=actual->getSig();
		}
		if(actual==NULL){
			return "-1";
		}
	}
	return 0;
}
string ListaRestaurante::ConsultarNombre(string r){
	actual=cabeza;
	if(IsEmpty()){
		return "0";
	}else{
		bool n = true;
		while(actual!=NULL && n==true){
			if(actual->getInfo()->getNombre()==r){
				n = false;
				return actual->getInfo()->toStringRestaurante();
			}
			actual=actual->getSig();
		}
		if(actual==NULL){
			return "-1";
		}
	}
	return 0;
}
string ListaRestaurante::ListarRestaurante(){
	stringstream cadena;
	actual=cabeza;
	if(IsEmpty()){
		return "0";
	}else{
		while(actual!=NULL){
			cadena<<actual->getInfo()->toStringRestaurante();
			actual=actual->getSig();
		}
		return cadena.str();
	}
}
string ListaRestaurante::ListarNombres(){
	stringstream cadena;
	actual=cabeza;
	if(IsEmpty()){
		return "0";
	}else{
		while(actual!=NULL){
			cadena<<actual->getInfo()->toStringRestCliente(); //Datos utiles para el cliente
			actual=actual->getSig();
		}
		return cadena.str();
	}
}
void ListaRestaurante::Guardar(){
	
	if(IsEmpty()){
		return;
	} 
	ofstream Archivo("Restaurantes.txt");
	actual=cabeza;
	while(actual!=NULL){
		Archivo<<actual->getInfo()->getNombre()<<","<<actual->getInfo()->getCedJud()<<","<<actual->getInfo()->getDireccion()<<","<<actual->getInfo()->getTipoComida()<<","<<actual->getInfo()->getNPedidosR()<<endl;
		actual=actual->getSig();
	}
	Archivo.close();
}

void ListaRestaurante::Cargar(){
	ifstream Archivo;
	Archivo.open("Restaurantes.txt");
	if(Archivo){
		
		while(!Archivo.eof()){
			string *Nombre = new string();
			string *CedJud = new string();
			string *Direccion = new string();
			string *TipoComida = new string();	
			int *NPedidosR= new int();
			getline(Archivo,*Nombre,',');
			getline(Archivo,*CedJud,',');
			getline(Archivo,*Direccion,',');
			getline(Archivo,*TipoComida,',');
			Archivo>>*NPedidosR;
			string aux;
			getline(Archivo,aux);
			if(!Archivo.eof()){
				/*cout<<"Restaurante: "<<endl;
				cout<<"Nombre: "<<*Nombre<<endl;
				cout<<"Cedula: "<<*CedJud<<endl;
				cout<<"Direccion: "<<*Direccion<<endl;
				cout<<"Tipo de Comida: "<<*TipoComida<<endl;
				cout<<"Numero de pedidos: "<<*NPedidos<<endl<<endl;*/
				Restaurante *r= new Restaurante(Nombre, CedJud, Direccion, TipoComida, NPedidosR);
				InsertarRestaurante(r);
			}
		}
	}
	Archivo.close();
}
ListaRestaurante::~ListaRestaurante() {
	while(cabeza!=NULL){
		this->actual=cabeza;
		cabeza=cabeza->getSig();
		delete actual;
	}
}
