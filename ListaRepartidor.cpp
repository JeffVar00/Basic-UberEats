#include "ListaRepartidor.h"

ListaRepartidor::ListaRepartidor() {
	cabeza=actual=NULL;
}
bool ListaRepartidor::IsEmpty(){
	return cabeza==NULL;
}
void ListaRepartidor::InsertarRepartidor(Repartidor *R){
	NodoRepartidor *aux = new NodoRepartidor(R);
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

	string ListaRepartidor::ConsultarRepartidor(string r){
		actual=cabeza;
		if(IsEmpty()){
			return "0";
		}else{
			bool n = true;
			while(actual!=NULL && n==true){
				if(actual->getInfo()->getCedula()==r){
					n = false;
					return actual->getInfo()->toStringRepartidor();
				}
				actual=actual->getSig();
			}
			if(actual==NULL){
				return "-1";
			}
		}
		return 0;
	}
    string ListaRepartidor::AsignarCedula(){
	    string *aux=new string();
		*aux="Ocupado";
	    actual=cabeza;
	    if(IsEmpty()){
	 	    return "0";
	    }else{
		    bool n = true;
		    while(actual!=NULL && n==true){
			    if(actual->getInfo()->getNumAmonestaciones()<4 && actual->getInfo()->getDisp()=="Disponible"){
					actual->getInfo()->setDisp(aux);
			    	n = false;
					cout<<"Se le ha asignado un repartidor"<<endl;
			    	return actual->getInfo()->getCedula();
			    }
			actual=actual->getSig();
		    }
		    if(actual==NULL){
		    	return "-1";
		    }
	    }
	    return 0;
    }
	string ListaRepartidor::ListarRepartidor(){
		stringstream cadena;
		actual=cabeza;
		if(IsEmpty()){
			return "0";
		}else{
			while(actual!=NULL){
				cadena<<actual->getInfo()->toStringRepartidor();
				actual=actual->getSig();
			}
			return cadena.str();
		}
	}
void ListaRepartidor::AumentarKM(float k, string r){
	actual=cabeza;
	float *aux= new float();
	bool n=true;
	while(actual!=NULL && n==true){
		if(actual->getInfo()->getCedula()==r){
			*aux=actual->getInfo()->getKRecorridos();
			*aux+=k;
			actual->getInfo()->setKRecorridos(aux);
			n = false;
		}
		actual=actual->getSig();
	}
}
void ListaRepartidor::AumentarAmonestaciones(string r){
	actual=cabeza;
	int *aux= new int();
	bool n=true;
	while(actual!=NULL && n==true){
		if(actual->getInfo()->getCedula()==r){
			*aux=actual->getInfo()->getNumAmonestaciones();
			*aux+=1;
			actual->getInfo()->setNumAmonestaciones(aux);
			n = false;
		}
		actual=actual->getSig();
	}
}
int ListaRepartidor::ConsultarAmonestaciones(string r){
	
	actual=cabeza;
		bool n = true;
		while(actual!=NULL && n==true){
			if(actual->getInfo()->getCedula()==r){
				n = false;
				return actual->getInfo()->getNumAmonestaciones();
			}
			actual=actual->getSig();
		}
	return 0;

}
void ListaRepartidor::SuspenderRepartidor(string r){
	actual=cabeza;
	string *aux= new string();
    *aux="Repartidor Suspendido";
	bool n=true;
	while(actual!=NULL && n==true){
		if(actual->getInfo()->getCedula()==r){
			actual->getInfo()->setDisp(aux);
			n = false;
		}
		actual=actual->getSig();
	}
}
void ListaRepartidor::Guardar(){
	
	if(IsEmpty()){
		return;
	} 
	ofstream Archivo("Repartidores.txt");
	actual=cabeza;
	while(actual!=NULL){
		Archivo<<actual->getInfo()->getNombre()<<","<<actual->getInfo()->getCedula()<<","<<actual->getInfo()->getCorreoE()<<","<<actual->getInfo()->getDireccionEx()<<","<<actual->getInfo()->getNumTarjeta()<<","<<actual->getInfo()->getDisp()<<","<<actual->getInfo()->getDistanciaP()<<" "<<actual->getInfo()->getKRecorridos()<<" "<<actual->getInfo()->getNumAmonestaciones()<<" "<<actual->getInfo()->getTelefonoCel()<<endl;
		actual=actual->getSig();
	}
	Archivo.close();
}

void ListaRepartidor::Cargar(){
	ifstream Archivo;
	Archivo.open("Repartidores.txt");
	if(Archivo){
		while(!Archivo.eof()){
			string *NombreR = new string();
			string *Cedula = new string();
			string *CorreoE  = new string();
			string *DireccionEx  = new string();
			string *NumTarjeta = new string();
			string *Disp= new string();
			float *KRecorridos= new float();
			float *DistanciaP= new float();
			int *TelefonoCel = new int;
			int *NumAmonestaciones= new int;
			getline(Archivo,*NombreR,',');
			getline(Archivo,*Cedula,',');
			getline(Archivo,*CorreoE,',');
			getline(Archivo,*DireccionEx,',');
			getline(Archivo,*NumTarjeta,',');
			getline(Archivo,*Disp,',');
			Archivo>>*DistanciaP;
			Archivo>>*KRecorridos;
			Archivo>>*NumAmonestaciones;
			Archivo>>*TelefonoCel;
			string aux;
			getline(Archivo,aux);
			//int //Archivo>>*TelefonoCel;
			//enteros para el final y separa por espacio no por ","
			//getline(Archivo,aux);
			//aux==" 1"?*Estado=true:*Estado=false;
			
			if(!Archivo.eof()){
				/*cout<<"Repartidor: "<<endl;
				cout<<"Nombre: "<<*NombreR<<endl;
				cout<<"Cedula: "<<*Cedula<<endl;
				cout<<"Correo: "<<*CorreoE<<endl;
				cout<<"Direccion: "<<*DireccionEx<<endl;
				cout<<"Num tarjeta: "<<*NumTarjeta<<endl;
				cout<<"Disponibilidad: "<<*Disp<<endl;
				cout<<"Distancia Del Pedido: "<<*DistanciaP<<endl;
				cout<<"Kilometros recorridos: "<<*KRecorridos<<endl;
				cout<<"Amonestaciones: "<<*NumAmonestaciones<<endl;
				cout<<"Telefono: "<<*TelefonoCel<<endl<<endl;*/
				Repartidor *r= new Repartidor(NombreR, Cedula, CorreoE, DireccionEx, NumTarjeta, TelefonoCel, DistanciaP, KRecorridos, NumAmonestaciones, Disp );
				InsertarRepartidor(r);
			}
		}
	}
	Archivo.close();
}
	
	ListaRepartidor::~ListaRepartidor() {
		while(cabeza!=NULL){
			this->actual=cabeza;
			cabeza=cabeza->getSig();
			delete actual;
		}
	}
