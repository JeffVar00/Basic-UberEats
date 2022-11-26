#include <iostream>
#include <string>
#include "time.h"
#include "Cliente.h"
#include "Repartidor.h"
#include "Restaurante.h"
#include "Pedido.h"
#include "Queja.h"
#include "ListaCliente.h"
#include "ListaRepartidor.h"
#include "ListaRestaurante.h"
#include "ListaPedido.h"
#include "ListaQueja.h"

using namespace std;

int main () {
	//Objetos
	Pedido *P = new Pedido();
	Queja *Q= new Queja();
	//Ciente y Repartidor
	string *Nombre = new string();
	string *Cedula = new string();
	string *CorreoE  = new string();
	string *DireccionEx  = new string();
	string *NumTarjeta = new string();
	int *TelefonoCel = new int();
	//Repartidor
	float *DistanciaP = new float();
	float *KRecorridos = new float();
	int *NumAmonestaciones = new int();;
	string *Disp= new string();
	//Cliente
	int *NPedidos = new int();
	bool *Estado = new bool();
	//Restaurante
	string *NombreR = new string();
	string *CedJud = new string();
	string *Direccion = new string();
	string *TipoComida = new string();	
	int *NPedidosR = new int();
	//Pedido
	int *ID = new int();
	int *HoraPedido = new int();
	int *MinutoPedido = new int();
	int *HoraEntregado = new int();
	int *MinutoEntregado = new int();
	string *EstadoP = new string();
	float *SubTotal = new float();
	float *Total = new float();
	//Queja
	string *Ced=new string();
	string *Descrip=new string();
	
	string opc = " " ;
    string ux = " " ;
	bool n=true;
	
	//Listas
	ListaCliente *Clientes= new ListaCliente();
	ListaRepartidor *Repartidores= new ListaRepartidor;
	ListaRestaurante *Restaurantes= new ListaRestaurante();
	ListaPedido *Pedidos= new ListaPedido;
	ListaQueja *Quejas= new ListaQueja;
	//Archivos
	Clientes->Cargar();
	Repartidores->Cargar();
	Restaurantes->Cargar();
	Pedidos->Cargar();
	Quejas->Cargar();
	
	//system("pause"); //Verificar
	
	do{
		try{
			//Ciente y Repartidor
			string *Nombre = new string();
			string *Cedula = new string();
			string *CorreoE  = new string();
			string *DireccionEx  = new string();
			string *NumTarjeta = new string();
			int *TelefonoCel = new int();
			//Repartidor
			float *DistanciaP = new float();
			float *KRecorridos = new float();
			int *NumAmonestaciones = new int();
			string *Disp= new string();
			//Cliente
			int *NPedidos = new int();
			bool *Estado = new bool();
			//Restaurante
			string *NombreR = new string();
			string *CedJud = new string();
			string *Direccion = new string();
			string *TipoComida = new string();	
			int *NPedidosR = new int();
			//Pedido
			int *ID = new int();
			int *HoraPedido = new int();
			int *MinutoPedido = new int();
			int *HoraEntregado = new int();
			int *MinutoEntregado = new int();
			string *EstadoP = new string();
			float *SubTotal = new float();
			float *Total = new float();
			//Queja
			string *Ced=new string();
			string *Descrip=new string();
			
			system("cls");
			cout<<"\tCletaEats"<<endl<<endl;
			
			cout<<"1. Menu de Clientes"<<endl; 
			cout<<"2. Registrarse como Repartidor"<<endl;
			cout<<"3. Registrarse como Restaurante"<<endl;
			cout<<"4. Nuestro clientes, restaurantes y repartidores!!"<<endl;
			cout<<"5. Realizar una Queja o Consultarlas"<<endl; 
			cout<<"6. Cliente mas destacado de nuestro sistema"<<endl;
			cout<<"7. Informacion financiera de nuestros restaurantes"<<endl;
			cout<<"0. Guardar y Salir"<<endl<<endl;
			
			getline(cin, opc);
			
			cout<<endl;
			
			if(opc=="1"){
				cout<<"\tMenu de Clientes"<<endl;
				cout<<"Digite su numero de cedula para ingresar"<<endl;
				getline(cin,*Cedula);
				cin.get();
				ux=Clientes->ConsultarCliente(*Cedula);
				if(ux=="0"||ux=="-1"){
					system("cls");
					//menu registro
					cout<<"Bienvenido a CletaEats!!"<<endl<<endl; 
					cout<<"\tMenu de Registro"<<endl; 
					cout<<"Por favor digite la siguiente informacion"<<endl<<endl; 
					cout<<"Nombre: "; getline(cin,*Nombre); 
					cout<<"Cedula: "; getline(cin,*Cedula); 
					cout<<"Correo electronico: "; getline(cin, *CorreoE); 
					cout<<"Direccion exacta: "; getline(cin, *DireccionEx); 
					cout<<"Numero de tarjeta: "; getline(cin, *NumTarjeta); 
					cout<<"Telefono celular: "; cin>>*TelefonoCel; 
					while (cin.fail() >> *TelefonoCel) { cin.clear(); cin.ignore(1000, '\n'); cout << "Se espera un valor numerico: "; cin >> *TelefonoCel; }
					*Estado=false; 
					*NPedidos=0;
					ux=Clientes->ConsultarCliente(*Cedula); 
					if(ux=="0"||ux=="-1"){ 
						Cliente *C = new Cliente(Nombre, Cedula, CorreoE, DireccionEx, NumTarjeta, TelefonoCel, Estado, NPedidos); 
						Clientes->InsertarCliente(C); 
					}else{
						cout<<"Lo sentimos, este numero de cedula ya esta regristado"<<endl;
					}
					cout<<endl;
					cout<<"Gracias por descargarnos!"<<endl;
					system("pause");
				}else{
					system("cls");
					//menu cliente registrado
					cout<<"\tMenu de Clientes"<<endl;
					cout<<"Bienvenido de nuevo a CletaEats!"<<endl;
					cout<<"Que desea hacer hoy?"<<endl<<endl;
					cout<<"1. Realizar un pedido"<<endl;
					cout<<"2. Mis pedidos"<<endl<<endl;
					cin>>opc;
					if(opc=="1"){
						*Total=0;
						*SubTotal=0;
						int f;
						bool F;
						string *opcR= new string();
						string *Repart= new string();
						cout<<"Ingrese la informacion de su pedido"<<endl;
					    srand(time(0));
						*ID = rand() % 5000;
						cout<<"Digite la hora estimada de la solicitud del pedido"<<endl;
						cin>>*HoraPedido;
						cout<<"Digite los minutos estimados de la solicitud del pedido"<<endl;
						cin>>*MinutoPedido;
						cout<<"Digite la hora estimada de entrega del pedido"<<endl;
						cin>>*MinutoEntregado;
						cout<<"Digite los minutos estimados de la entrega del pedido"<<endl;
						cin>>*MinutoEntregado;
						cout<<"Distancia del pedido"<<endl;
						cin>>*DistanciaP;
						*EstadoP = "En Preparacion" ;
						system("cls");
						//metodo consultar restaurantes pero solo con nombre y tipo de comida
						ux=Restaurantes->ListarNombres();
						if(ux=="0"){
							cout <<"No tenemos restaurantes disponibles, lo sentimos"<< endl;
							system("pause");
						}else{
						cout<<"Por favor digite el nombre de uno de nuestros restaurantes, igual a como se observa"<<endl;
						cout << ux << endl;
						cin.get();
						getline(cin, *opcR);
						cout<<endl;
						ux=Restaurantes->ConsultarNombre(*opcR);
						if(ux=="0"||ux=="-1"){
							cout<<"El nombre ingresado no esta registrado"<<endl;
							system("pause");
						}else{
						cout<<"Es dia Feriado? (1-Si 2-No)"<<endl;
						cin>>f;
						while (cin.fail() >> f) { cin.clear(); cin.ignore(1000, '\n'); cout << "Se espera un valor numerico: "; cin >> f; }
						if(f==1){
							F = true;
						}else{
							F = false;
						}
						bool n = true;
						do{
							system("cls");
							cout<<"Se a enviado el Menu a su Correo Electronico"<<endl;
							cout<<"Ingrese los combos que desea añadir a su carrito"<<endl;
							cout<<"Combo 1: $4000"<<endl;
							cout<<"Combo 2: $5000"<<endl;
							cout<<"Combo 3: $6000"<<endl;
							cout<<"Combo 4: $7000"<<endl;
							cout<<"Combo 5: $8000"<<endl;
							cout<<"Combo 6: $9000"<<endl;
							cout<<"Combo 7: $10000"<<endl;
							cout<<"Combo 8: $11000"<<endl;
							cout<<"Combo 9: $12000"<<endl;
							cout<<"Digite 0 para confirmar"<<endl;
							getline(cin, opc);
							if(opc=="1"){
								float IVA;
								float SubTotalAux=4000;
								*SubTotal += 4000;
								IVA = SubTotalAux * 0.13;
								*Total += SubTotalAux + IVA;
								system("pause");
						    }else if(opc=="2"){
								float IVA;
								float SubTotalAux=5000;
								*SubTotal += 5000;
								IVA = SubTotalAux * 0.13;
								*Total += SubTotalAux + IVA;
								system("pause");
						    }else if(opc=="3"){
								float IVA;
								float SubTotalAux=6000;
								*SubTotal += 6000;
								IVA = SubTotalAux * 0.13;
								*Total += SubTotalAux + IVA;
								system("pause");
							}else if(opc=="4"){
								float IVA;
								float SubTotalAux=7000;
								*SubTotal += 7000;
								IVA = SubTotalAux * 0.13;
								*Total += SubTotalAux + IVA;
								system("pause");
							}else if(opc=="5"){
								float IVA;
								float SubTotalAux=8000;
								*SubTotal += 8000;
								IVA = SubTotalAux * 0.13;
								*Total += SubTotalAux + IVA;
								system("pause");
							}else if(opc=="6"){
								float IVA;
								float SubTotalAux=9000;
								*SubTotal += 9000;
								IVA = SubTotalAux * 0.13;
								*Total += SubTotalAux + IVA;
								system("pause");
							}else if(opc=="7"){
								float IVA;
								float SubTotalAux=10000;
								*SubTotal += 10000;
								IVA = SubTotalAux * 0.13;
								*Total += SubTotalAux + IVA;
								system("pause");
							}else if(opc=="8"){
								float IVA;
								float SubTotalAux=11000;
								*SubTotal += 11000;
								IVA = SubTotalAux * 0.13;
								*Total += SubTotalAux + IVA;
								system("pause");
							}else if(opc=="9"){
								float IVA;
								float SubTotalAux=12000;
								*SubTotal += 12000;
								IVA = SubTotalAux * 0.13;
								*Total += SubTotalAux + IVA;
								system("pause");
							}else if(opc=="0"){
								if(F==true){
								*Total+= *DistanciaP * 1500;
								}else{
								*Total+= *DistanciaP * 1000;	
								}
								*Repart=Repartidores->AsignarCedula();
								if(*Repart=="0"||*Repart=="-1"){
									cout<<"Lo sentimos no tenemos repartidores disponibles, intentelo mas tarde"<<endl;
									n=false;
									system("pause");
								}else{
								Clientes->AumentarPedidos(*Cedula);
								Clientes->ActivarCliente(*Cedula);
								Restaurantes->AumentarPedidos(*opcR);
								Repartidores->AumentarKM(*DistanciaP, *Repart);
								P = new Pedido(ID, HoraPedido, MinutoPedido, HoraEntregado, MinutoEntregado, EstadoP, SubTotal, Total, Cedula, Repart, opcR); //PRIMERO PERSONA, LUEGO REPARTIDOR, LUEGO RESTAURANTE
								Pedidos->InsertarPedido(P);
								cout<<Pedidos->ConsultarPedido(*ID);
								cout<<"Gracias por su compra, Buen provecho!!!"<<endl;
								n=false;
								system("pause");
								}
							}else{
								cout<<"Opcion invalida"<<endl;
								system("pause");
							}
						}while(n==true);
						}
						}
					}else if(opc=="2"){
						system("cls");
						ux=Pedidos->ListarCedula(*Cedula);
						if(ux=="0"){
							cout<<"No ha realizado pedidos recientemente"<<endl;
							system("pause");
						}else{
							cout<<"Mis Pedidos"<<endl;
							cout<<ux<<endl;
							system("pause");
						}
					}else{
						cout<<"Opcion invalida"<<endl;
						system("pause");
					}
					//Lista de Pedidos
				}
			}else if(opc=="2"){
					system("cls");
					//menu registro
					cout<<"Bienvenido a CletaEats!!"<<endl<<endl;
					cout<<"\tMenu de Registro de repartidores"<<endl;
					cout<<"Por favor digite la siguiente informacion"<<endl<<endl;
					cout<<"Nombre: "; getline(cin,*Nombre); 
					cout<<"Cedula: "; getline(cin,*Cedula); 
					cout<<"Correo electronico: "; getline(cin, *CorreoE); 
					cout<<"Direccion exacta: "; getline(cin, *DireccionEx); 
					cout<<"Numero de tarjeta: "; getline(cin, *NumTarjeta); 
					cout<<"Telefono celular: "; cin>>*TelefonoCel;
					while (cin.fail() >> *TelefonoCel) { cin.clear(); cin.ignore(1000, '\n'); cout << "Se espera un valor numerico: "; cin >> *TelefonoCel; }
					*DistanciaP=0.0;
					*KRecorridos=0.0;
					*NumAmonestaciones=0;
					*Disp="Disponible";
					ux=Repartidores->ConsultarRepartidor(*Cedula);
					if(ux=="0"||ux=="-1"){
						Repartidor *R = new Repartidor(Nombre, Cedula, CorreoE, DireccionEx, NumTarjeta, TelefonoCel, DistanciaP, KRecorridos, NumAmonestaciones, Disp);
						Repartidores->InsertarRepartidor(R);
					}else{
						cout<<"Lo sentimos, este numero de cedula ya esta regristado"<<endl;
					}
					cout<<endl;
					cout<<"Gracias por descargarnos!"<<endl;
					system("pause");
			}else if(opc=="3"){
					system("cls");
					//menu registro
					cout<<"Bienvenido a CletaEats!!"<<endl<<endl;
					cout<<"\tMenu de Registro de restaurantes"<<endl;
					cout<<"Por favor digite la siguiente informacion"<<endl<<endl;
					cout<<"Nombre del restaurante: "; getline(cin,*NombreR);
					cout<<"Cedula Juridica: "; getline(cin, *CedJud); 
					cout<<"Direccion del restaurante: "; getline(cin, *Direccion); 
					cout<<"Tipo de comida: "; getline(cin, *TipoComida);
					*NPedidosR=0;
					ux=Restaurantes->ConsultarRestaurante(*CedJud);
					if(ux=="0"||ux=="-1"){
						Restaurante *RR = new Restaurante(NombreR, CedJud, Direccion, TipoComida, NPedidosR);
						Restaurantes->InsertarRestaurante(RR);
					}else{
						cout<<"Lo sentimos, esta cedula juridica ya esta regristado"<<endl;
					}
					cout<<endl;
					cout<<"Gracias por descargarnos!"<<endl;
					system("pause");
			}else if(opc=="4"){
				cout<<"\tNuestros Clientes, Restaurantes y Repartidores"<<endl;
				cout<<"1. Nuestros Clientes (Activos)"<<endl;
				cout<<"2. Nuestros Clientes (Inactivos)"<<endl;
				cout<<"3. Nuestros Repartidores"<<endl;
				cout<<"4. Restaurantes afiliados"<<endl;
				cin>>opc;
				if(opc=="1"){
					system("cls");
					ux=Clientes->ListarClienteActivo();
					if(ux=="0"||ux=="-1"){
						cout<<"No hay clientes registrados o activos"<<endl;
					}else{
						cout<<ux<<endl;
					}
					system("pause");
				}else if(opc=="2"){
					system("cls");
					ux=Clientes->ListarClienteInactivo();
					if(ux=="0"||ux=="-1"){
						cout<<"No hay clientes registrados o inactivos"<<endl;
					}else{
						cout<<ux<<endl;
					}
					system("pause");
			    }else if(opc=="3"){
					system("cls");
					ux=Repartidores->ListarRepartidor();
					if(ux=="0"){
						cout<<"No hay repartidores registrados"<<endl;
					}else{
						cout << ux << endl;
					} 
					system("pause");
				}else if(opc=="4"){
					system("cls");
					ux=Restaurantes->ListarRestaurante();
					if(ux=="0"){
						cout <<"No hay restaurantes registrados"<< endl;
					}else{
						cout << ux << endl;
					} 
					system("pause");
				}
			}else if(opc=="5"){
				system("cls");
				cout<<"\tMenu Quejas"<<endl<<endl;
				cout<<"1-Dejar una queja"<<endl;
				cout<<"2-Consultar Quejas (solo repartidores)"<<endl<<endl;
				getline(cin,opc);
				cout<<endl;
				if(opc=="1"){
					cout<<"Digite la cedula del repartidor"<<endl;
					getline(cin,*Ced);
					ux=Repartidores->ConsultarRepartidor(*Ced);
					if(ux=="0"||ux=="-1"){
					cout<<"Lo sentimos, No existe un repartidor con esta cedula"<<endl;
					system("pause");
					}else{
					cout<<"Digite su queja"<<endl<<endl;
					getline(cin,*Descrip);
					Q = new Queja(Ced, Descrip);
					Quejas->InsertarQueja(Q);
					Repartidores->AumentarAmonestaciones(*Ced);
					cout<<endl;
					cout<<"Gracias por informarnos!!"<<endl;
					system("pause");
					}
				}else if(opc=="2"){
					cout<<"Digite su numero de cedula"<<endl;
					getline(cin,*Ced);
					ux=Repartidores->ConsultarRepartidor(*Ced);
					if(ux=="0"||ux=="-1"){
						cout<<"Cedula no registrada"<<endl;
						system("pause");
					}else{
						ux=Quejas->ListarQuejas(*Ced);
						if(ux=="0"){
							cout<<"No hay tiene niguna queja"<<endl;
							system("pause");
						}else{
							int ux2;
							ux2=Repartidores->ConsultarAmonestaciones(*Ced);
							cout<<"<\tQuejas"<<endl;
							cout<<ux<<endl;
							if(ux2>=4){
								Repartidores->SuspenderRepartidor(*Ced);
								cout<<"Cuenta suspendida debido al numero de amonestaciones presentes"<<endl;
							}
						}
						system("pause");
					}
				}
				
			}else if(opc=="6"){
			ux=Clientes->ObtenerClienteDestacado();
		    if(ux=="0"||ux=="-1"){
			    cout<<"Aun no se establece un cliente destacado"<<endl;
				system("pause");
			}else{
			    cout<<"Informacion del cliente con mas pedidos"<<endl;
				cout<<ux<<endl;
				cout<<"\tPROMO!!!!"<<endl;
				cout<<"A los 5 pedidos realizados te entregamos una sorpresa via email"<<endl;
				cout<<"Gracias por usar nuestro aplicacion!!!!!"<<endl;
				system("pause");
		    }
				
			}else if(opc=="7"){
				system("cls");
				cout<<"\tMenu Financiero"<<endl<<endl;
				cout<<"1-Consultar un restaurante en especifico"<<endl;
				cout<<"2-Monto total vendido por nuestros restaurantes"<<endl;
				cout<<"3-Restaurante mas popular"<<endl;
				cout<<"4-Restaurante menos popular"<<endl<<endl;
				getline(cin,opc);
				cout<<endl;
				if(opc=="1"){
					float ux2;
					ux=Restaurantes->ListarNombres();
					if(ux=="0"){
						cout <<"No tenemos restaurantes disponibles, lo sentimos"<< endl;
						system("pause");
					}else{
						cout<<"Por favor digite el nombre de uno de nuestros restaurantes, igual a como se observa"<<endl;
						cout << ux << endl;
					    cout<<"Digite el nombre del restaurante"<<endl;
					    getline(cin, opc);
						ux=Restaurantes->ConsultarNombre(opc);
						if(ux=="0"||ux=="-1"){
							cout<<"El nombre ingresado no esta registrado"<<endl;
							system("pause");
						}else{
						ux2=Pedidos->TotalVentasRest(opc);
						if(ux2==0 || ux2==-1){
					        cout<<"Este restaurante aun no genera ningun ingreso o no esta registrado"<<endl;
					        system("pause");
						}else{
							cout<<"Ventas totales: "<<ux2<<" colones"<<endl;
							system("pause");
						}
						}
					}
				}else if(opc=="2"){
					float ux2;
					ux2=Pedidos->TotalVentas();
					if(ux2==0 || ux2==-1){
						cout<<"Ningun restaurante ha generado ingresos"<<endl;
						system("pause");
					}else{
						cout<<"Ventas totales: "<<ux2<<" colones"<<endl;
						system("pause");
					}
				}else if(opc=="3"){
					ux=Restaurantes->ObtenerRestauranteMayor();
					if(ux=="0"||ux=="-1"){
						cout<<"Ningun restaurante ha tomado la delantera"<<endl;
						system("pause");
					}else{
						cout<<"Informacion de nuestro restaurante mas destacado!"<<endl;
						cout<<ux<<endl;
						system("pause");
					}
				}else if(opc=="4"){
					ux=Restaurantes->ObtenerRestauranteMenor();
					if(ux=="0"||ux=="-1"){
						cout<<"Ningun restaurante ha entrado en zona de peligro"<<endl;
						system("pause");
					}else{
						cout<<"Informacion de nuestro restaurante menos popular"<<endl;
						cout<<ux<<endl;
						cout<<"\tADVERTENCIA!!!!"<<endl;
						cout<<"Despues de varios dias se eliminara de nuestro sistema si no sube en ventas"<<endl;
						system("pause");
					}
				}else{
					cout<<"Opcion invalida"<<endl;
					system("pause");
				}
			}else if(opc=="0"){
				
				cout<<"Provecho!!"<<endl;
				Clientes->Guardar();
				Repartidores->Guardar();
				Restaurantes->Guardar();
				Pedidos->Guardar();
				Quejas->Guardar();
				n=false;
				system("pause");
				
			}else{
				cout<<"Opcion no valida"<<endl;
				system("pause");
			}
		}catch(string opc){
			system("cls");
			cout<<"Error, Opcion no valida\n";
			system("pause");
		}
	}while(n==true);

	delete Restaurantes;
	delete Clientes;
	delete Pedidos;
	delete Repartidores;
	delete Quejas;
	delete Nombre; delete Cedula; delete CorreoE; delete DireccionEx; delete NumTarjeta; delete TelefonoCel, delete Estado; delete NPedidos;
	delete DistanciaP; delete KRecorridos; delete NumAmonestaciones; delete Disp;
	delete NombreR; delete CedJud; delete Direccion; delete TipoComida; delete NPedidosR;
	delete ID; delete HoraPedido; delete MinutoPedido; delete HoraEntregado; delete MinutoEntregado; delete EstadoP; delete SubTotal; delete Total;
	delete Ced; delete Descrip;
	
	return 0;
}
