#include <iostream>
#include <stack>
#include <conio.h>
using namespace std;

struct Llantas{
	int codigo;
	char modelo[20];
	char marca[20];
	char tamanio[20];
};

void menu()
{
    cout<<"\n\t Pila de estudiantes\n\n";
    cout<<" 1. Agregar                             "<<endl;
    cout<<" 2. Eliminar                            "<<endl;
    cout<<" 3. Mostrar lista                       "<<endl;
    cout<<" 4. Eliminar lista                      "<<endl;
    cout<<" 5. SALIR                               "<<endl;

}

void ingresar(Llantas &pila_aux){
	
}

void mostrar(){
	
}

int main(){
	stack<Llantas> pila_llantas;
	Llantas pila_aux; 
	Llantas *puntero;
	int opcion;	
	char resp;	
	
	do{

	menu(); 
    cout<<"\n Ingrese opcion: "; cin >> opcion;
			
	switch(opcion){
		case 1:
		do{
			//cout << &pila_llantas << endl << &ar_llantas << endl; Marca la posicion de la pila y del arreglo
			cout << "Cod:\t";
			cin >> pila_aux.codigo;
			cout << "Modelo:\t";
			cin >> pila_aux.modelo;
			cout << "Marca:\t";
			cin >> pila_aux.marca;
			cout << "Tamanio:\t";
			cin >> pila_aux.tamanio;
			
			pila_llantas.push(pila_aux);
			
			cout << "Desea agregar otra llanta? (s,n)" << endl;
			cin >> resp;
			system("cls");
			menu();
			
			}while(resp == 's' || resp == 'S');puntero = &pila_llantas.top(); //el puntero apunta al tope de la pila
				
			break;
		case 2:			
			pila_llantas.pop();
			cout << "Llanta eliminada...\n";
			break;
		case 3:		
			puntero = &pila_llantas.top();	
			for (int i=1; i <= pila_llantas.size();i++){
				pila_aux = *puntero;
				cout << "Cod:" << pila_aux.codigo << "\t\t";
				cout << "Modelo:" << pila_aux.modelo << "\t";
				cout << "Marca:" << pila_aux.marca << "\t\t";
				cout << "Tamanio:" << pila_aux.tamanio << endl << endl;	
				puntero--;
			}
			break;
		case 4:
			do{
			pila_llantas.pop();
			}while(!pila_llantas.empty());
			break;		
	}
	getch();
	system("cls");
	}while(opcion != 5);
}

