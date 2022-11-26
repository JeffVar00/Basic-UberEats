#include "ListaCliente.h"

ListaCliente::ListaCliente() {
	cabeza=actual=NULL;
}
bool ListaCliente::IsEmpty(){
	return cabeza==NULL;
}
void ListaCliente::InsertarCliente(Cliente *C){
	NodoCliente *aux = new NodoCliente(C);
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

	string ListaCliente::ConsultarCliente(string c){
		actual=cabeza;
		if(IsEmpty()){
			return "0";
		}else{
			bool n = true;
			while(actual!=NULL && n==true){
				if(actual->getInfo()->getCedula()==c){
					n = false;
					return actual->getInfo()->toStringCliente();
				}
				actual=actual->getSig();
			}
			if(actual==NULL){
				return "-1";
			}
		}
		return 0;
	}
    void ListaCliente::ActivarCliente(string c){
	actual=cabeza;
	bool *aux=new bool();
	*aux=true;
	
		bool n = true;
		while(actual!=NULL && n==true){
			if(actual->getInfo()->getCedula()==c){
				actual->getInfo()->setEstado(aux);
				n = false;
			}
			actual=actual->getSig();
		}
		
    }
string ListaCliente::ObtenerClienteDestacado(){
	int mayor=0;
	actual=cabeza;
	string aux;
	if(IsEmpty()){
		return "0";
	}else{
		while(actual!=NULL){
			if(actual->getInfo()->getNPedidos()>mayor){
				aux=actual->getInfo()->toStringCliente();
				mayor=actual->getInfo()->getNPedidos();
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
void ListaCliente::AumentarPedidos(string c){
	actual=cabeza;
	int *aux= new int();
	bool n=true;
	while(actual!=NULL && n==true){
		if(actual->getInfo()->getCedula()==c){
			*aux=actual->getInfo()->getNPedidos();
			*aux+=1;
			actual->getInfo()->setNPedidos(aux);
			n = false;
		}
		actual=actual->getSig();
	}
}
	string ListaCliente::ListarClienteActivo(){
		stringstream cadena;
		actual=cabeza;
		if(IsEmpty()){
			return "0";
		}else{
			while(actual!=NULL){
				if(actual->getInfo()->getEstado()==true){
				cadena<<actual->getInfo()->toStringCliente();
				}
				actual=actual->getSig();
			}
			return cadena.str();
		}
	}
string ListaCliente::ListarClienteInactivo(){
	stringstream cadena;
	actual=cabeza;
	if(IsEmpty()){
		return "0";
	}else{
		while(actual!=NULL){
			if(actual->getInfo()->getEstado()==false){
				cadena<<actual->getInfo()->toStringCliente();
			}
			actual=actual->getSig();
		}
		return cadena.str();
	}
}
void ListaCliente::Guardar(){
	
	if(IsEmpty()){
		return;
	} 
	ofstream Archivo("Clientes.txt");
	actual=cabeza;
	    while(actual!=NULL){
		Archivo<<actual->getInfo()->getNombre()<<","<<actual->getInfo()->getCedula()<<","<<actual->getInfo()->getCorreoE()<<","<<actual->getInfo()->getDireccionEx()<<","<<actual->getInfo()->getNumTarjeta()<<","<<actual->getInfo()->getEstado()<<" "<<actual->getInfo()->getTelefonoCel()<<" "<<actual->getInfo()->getNPedidos()<<endl;
		actual=actual->getSig();
	    }
		Archivo.close();
    }

void ListaCliente::Cargar(){
	ifstream Archivo;
	Archivo.open("Clientes.txt");
	if(Archivo){
		//string aux;
		while(!Archivo.eof()){
		string *NombreC = new string();
		string *Cedula = new string();
		string *CorreoE  = new string();
		string *DireccionEx  = new string();
		string *NumTarjeta = new string();
		int *TelefonoCel = new int;
		bool *Estado = new bool();
		int *NPedidos = new int();
		getline(Archivo,*NombreC,',');
		getline(Archivo,*Cedula,',');
		getline(Archivo,*CorreoE,',');
		getline(Archivo,*DireccionEx,',');
		getline(Archivo,*NumTarjeta,',');
		Archivo>>*Estado;
		Archivo>>*TelefonoCel;
		Archivo>>*NPedidos;
		string aux;
		getline(Archivo,aux);
		//int //Archivo>>*TelefonoCel;
		//enteros para el final y separa por espacio no por ","
		//getline(Archivo,aux);
	    //aux==" 1"?*Estado=true:*Estado=false;
		
		if(!Archivo.eof()){
			/*cout<<"Persona: "<<endl;
			cout<<"Nombre: "<<*NombreC<<endl;
			cout<<"Cedula: "<<*Cedula<<endl;
			cout<<"Correo: "<<*CorreoE<<endl;
			cout<<"Direccion: "<<*DireccionEx<<endl;
			cout<<"Num tarjeta: "<<*NumTarjeta<<endl;
			cout<<"Estado: "<<*Estado<<endl;
			cout<<"Telefono: "<<*TelefonoCel<<endl;
			cout<<"Numero de pedidos: "<<*NPedidos<<endl<<endl;*/
			Cliente *c= new Cliente(NombreC, Cedula, CorreoE, DireccionEx, NumTarjeta, TelefonoCel, Estado, NPedidos);
		    InsertarCliente(c);
		}
		
		}
	}
	Archivo.close();
    }
	ListaCliente::~ListaCliente() {
		while(cabeza!=NULL){
			this->actual=cabeza;
			cabeza=cabeza->getSig();
			delete actual;
		}
	}
