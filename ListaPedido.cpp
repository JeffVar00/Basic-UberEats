#include "ListaPedido.h"

ListaPedido::ListaPedido() {
	cabeza=actual=NULL;
}

bool ListaPedido::IsEmpty(){
	return cabeza==NULL;
}

void ListaPedido::InsertarPedido(Pedido *P){
	NodoPedido *aux = new NodoPedido(P);
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


string ListaPedido::ConsultarPedido(int p){
	actual=cabeza;
	if(IsEmpty()){
		return "0";
	}else{
		bool n = true;
		while(actual!=NULL && n==true){
			if(actual->getInfo()->getID()==p){
				n = false;
				return actual->getInfo()->toStringPedido();
			}
			actual=actual->getSig();
		}
		if(actual==NULL){
			return "-1";
		}
	}
	return 0;
}
string ListaPedido::ListarCedula(string c){
	stringstream cadena;
	actual=cabeza;
	if(IsEmpty()){
		return "0";
	}else{
		while(actual!=NULL){ 
			if(actual->getInfo()->getCedP()==c){
			cadena<<actual->getInfo()->toStringPedido();
			}
			actual=actual->getSig();
		}
		return cadena.str();
	}
}
string ListaPedido::ListarPedido(){
	stringstream cadena;
	actual=cabeza;
	if(IsEmpty()){
		return "0";
	}else{
		while(actual!=NULL){
			cadena<<actual->getInfo()->toStringPedido();
			actual=actual->getSig();
		}
		return cadena.str();
	}
}

float ListaPedido::TotalVentasRest(string r){
	actual=cabeza;
	float *contador=new float();
	float IVA;
	*contador=0;
	if(IsEmpty()){
		return 0;
	}else{
		while(actual!=NULL){
			if(actual->getInfo()->getNRest()==r){
				IVA=actual->getInfo()->getSubTotal();
				*contador+= actual->getInfo()->getSubTotal();
				*contador+= IVA * 0.13;
			}
			actual=actual->getSig();
		}
		return *contador;

		if(actual==NULL){
			return -1;
		}
	}
	return 0;
}
int ListaPedido::Contar(){
	actual = cabeza;
	int cont=0;
	while(actual !=NULL){
		actual=actual->getSig();
		cont++;
	}
	return cont;
}
float ListaPedido::TotalVentas(){
	actual=cabeza;
	float *contador=new float();
	float IVA;
	*contador=0;
	if(IsEmpty()){
		return 0;
	}else{
		while(actual!=NULL){
			IVA=actual->getInfo()->getSubTotal();
			*contador+= actual->getInfo()->getSubTotal();
			*contador+= IVA * 0.13;
			actual=actual->getSig();
		}
		return *contador;
		
		if(actual==NULL){
			return -1;
		}
	}
	return 0;
}

void ListaPedido::Guardar(){
	
	if(IsEmpty()){
		return;
	} 
	ofstream Archivo("Pedidos.txt");
	actual=cabeza;
	while(actual!=NULL){
		Archivo<<actual->getInfo()->getEstado()<<","<<actual->getInfo()->getCedR()<<","<<actual->getInfo()->getNRest()<<","<<actual->getInfo()->getCedP()<<","<<actual->getInfo()->getTotal()<<" "<<actual->getInfo()->getID()<<" "<<actual->getInfo()->getHoraPedido()<<" "<<actual->getInfo()->getMinutoPedido()<<" "<<actual->getInfo()->getHoraEntregado()<<" "<<actual->getInfo()->getMinutoEntregado()<<" "<<actual->getInfo()->getSubTotal()<<" "<<endl;
		actual=actual->getSig();
	}
	Archivo.close();
}

void ListaPedido::Cargar(){
	ifstream Archivo;
	Archivo.open("Pedidos.txt");
	if(Archivo){
		while(!Archivo.eof()){
			int *ID = new int();
			int *HoraPedido = new int();
			int *MinutoPedido = new int();
			int *HoraEntregado = new int();
			int *MinutoEntregado = new int();
			string *EstadoP = new string();
			float *SubTotal = new float();
			float *Total = new float();
			string *CedR= new string();
			string *NRest= new string();
			string *CedP= new string();
			getline(Archivo,*EstadoP,','); 
			getline(Archivo,*CedR,',');
			getline(Archivo,*NRest,',');
			getline(Archivo,*CedP,',');
			Archivo>>*Total;
			Archivo>>*ID;
			Archivo>>*HoraPedido;
			Archivo>>*MinutoPedido;
			Archivo>>*HoraEntregado;
			Archivo>>*MinutoEntregado;
			Archivo>>*SubTotal;
			string aux;
			getline(Archivo,aux);
			//int //Archivo>>*TelefonoCel;
			//enteros para el final y separa por espacio no por ","
			//getline(Archivo,aux);
			//aux==" 1"?*Estado=true:*Estado=false;
			
			if(!Archivo.eof()){
				/*cout<<"Pedido: "<<endl;
				cout<<"ID: "<<*ID<<endl;
				cout<<"Estado: "<<*EstadoP<<endl;
				cout<<"Hora Pedido: "<<*HoraPedido<<endl;
				cout<<"Minuto Pedido: "<<*MinutoPedido<<endl;
				cout<<"Hora Entregado: "<<*HoraEntregado<<endl;
				cout<<"Minuto Entregado: "<<*MinutoEntregado<<endl;
				cout<<"SubTotal: "<<*SubTotal<<endl;
				cout<<"Total: "<<*Total<<endl;
				cout<<"Cedula: "<<*CedP<<endl;
				cout<<"Nombre rest: "<<*NRest<<endl;
				cout<<"Cedula del repartidor asignado: "<<*CedR<<endl<<endl;*/
				Pedido *p= new Pedido(ID, HoraPedido, MinutoPedido, HoraEntregado, MinutoEntregado, EstadoP, SubTotal, Total, CedP, CedR, NRest);
				InsertarPedido(p);
			}
		}
	}
	Archivo.close();
}

ListaPedido::~ListaPedido() {
	while(cabeza!=NULL){
		this->actual=cabeza;
		cabeza=cabeza->getSig();
		delete actual;
	}
}

