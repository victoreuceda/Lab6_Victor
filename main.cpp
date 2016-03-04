#include <iostream>
#include <string>
#include "game.h"
#include "user.h"
	
using std::vector;
using std::string;
using std::cout;
using std::cin;

bool eliminarUsuario(string,vector<User>&); 
void ingresarGame(int,vector<Game>&);
bool eliminarGame(int,vector<Game>&);

int main(int argc,char* argv[]){
	int opcion;
	bool continuar=true;
	vector<User> listado;
	vector<Game> inventario;
		
	do{
		cout<<"Bienvenido, ingrese una opcion"<<endl
		    <<"1: Agregar usuario"	      <<endl
		    <<"2: Modificar usuario"	      <<endl
		    <<"3: Eliminar Usuario"	      <<endl
		    <<"4: Agregar Juego"	      <<endl
		    <<"5: Eliminar juego"	      <<endl
		    <<"6: Listar juego" 	      <<endl
		    <<"7: Listar usuarios" 	      <<endl;
		cin >> opcion;
	
		if(opcion==1){
			bool ver=true;			
			do{
				string username,password;
				cout<<"Ingrese un username: ";
				cin >> username;
				cout<<"Ingrese un password: ";
				cin >> password;
				int contador=0;
				for(int i=0;i<listado.size();i++){
					if(listado[i].getUsername().compare(username)==0){
						contador++;
					}
				}	
				if(contador==0){
					ver=false;
					listado.push_back(User(username,password));
				}else{
					cout << "Username ya está en uso!!" <<endl;
				}
			}while(ver==true);
		}else if(opcion==2){

		}else if(opcion==3){
			string username,password;
			cout<<"Ingrese un username: ";
			cin >> username;
			bool elim=eliminarUsuario(username, listado);
			if(elim==true){
				cout << "Usuario eliminado" << endl;
			}else{
				cout << "Usuario no válido" << endl;
			}
		}else if(opcion==4){
			//Agregar juego
			bool ver=true;
			int id;
			do{
				int cont=0;
				cout <<  "Ingrese el id: ";
			 	cin >> id;
				for(int i=0;i<inventario.size();i++){
					if(inventario[i].getId()==id){
						cont++;
					}
				}
				if(cont==0){
					ingresarGame(id,inventario);
					cout << "Juego agregado" << endl;
					ver=false;
				}else{
					cout << "Id ingresado, no válido!!"<<endl;
				}
			}while(ver==true);			
		}else if(opcion==5){
			//Eliminar juego
			int id;
			cout << "Ingrese el Id: ";
			cin >> id; 	
			eliminarGame(id,inventario);
		}else if(opcion==6){
			cout << "Lista de juegos" << endl;
			cout << "ID	Nombre	  Año	  Developers   	Género" << endl;
			for(int i=0;i<inventario.size();i++){
				cout<<inventario[i].toString()<<endl;
			}
		}else if(opcion==7){
			cout << "Lista de Usuarios" <<endl;
			for(int i=0;i<listado.size();i++){
				cout<<listado[i].getUsername()<<endl;
			}
		}else{
			cout<<"Ingresaste algo mal"<<endl;
		}
		int bandera;
		cout<<"Desea continuar 1/0: ";
		cin >> bandera;
		if(bandera==1){
			continuar=true;	
		}else{
			continuar=false;
		}

	}while(continuar==true);


	return 0;
}

bool eliminarUsuario(string username,vector<User>& listado){
	for(int i=0;i<listado.size();i++){
		if(listado[i].getUsername().compare(username)==0){
			listado.erase(listado.begin() + i);
			return true;
		}
	}
	return false;
}
void ingresarGame(int id,vector<Game>& inventario){
	int year;
	string name,developers,genre;
	cout << "Nombre: ";
	cin >> name;
	cout << "Developers: ";
	cin >> developers;
	cout << "Género: ";
	cin >> genre;
	cout << "Año: ";
	cin >> year;
	inventario.push_back(Game(id,name,year,developers,genre)); 
}


bool eliminarGame(int id,vector<Game>& inventario){
	for(int i=0;i<inventario.size();i++){
		if(inventario[i].getId() == id){
			inventario.erase(inventario.begin() + i);
			return true;
		}
	}
	return false;
}