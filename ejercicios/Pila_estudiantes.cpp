//crear un programa que permita crear una pila para almacenar los datos de los estudiantes de programacion 2, 
//se debe de almacenar el due, nombre, apellido y la edad. 
//insertar y mostrar lo datos

#include<cstdlib>
#include<iostream>
#include<stack>
using namespace std;

struct estudiantes{
	int due;
	char nombre[10];
	char apellido[10];
	int edad;
};

void clear(bool *rep){ //limpia la variable que se acava de ingresar

	if(cin.fail()) { 
		cin.clear();
		cin.ignore();
		cout << "Ingreso un dato invalido, ingreselo nuevamente \n";
		*rep = false;
		system("pause"); system("cls");
		}
		
	else { *rep = true; }	
}

void crear(bool &rep, estudiantes &est){
	char op;
	do{
	
	do{
	cout << "Ingrese el due del estudiante: "; cin >> est.due;
	clear(&rep);
	}while(!rep);
	
	do{
	cout << "Ingrese el nombre del estudiante: "; cin >> est.nombre;
	clear(&rep);
	}while(!rep);
	
	do{
	cout << "Ingrese el apellido del estudiante: "; cin >> est.apellido;
	clear(&rep);	
	}while(!rep);
	
	do{
	cout << "Ingrese la edad del estudiante: "; cin >> est.edad;
	clear(&rep);	
	}while(!rep);
	
	cout << "Estudiante ingresado..." << endl;
	
	cout << "Desea ingresar otro estudiante? (s,n) \n ->";
	cin >> op;
	op == 's' or op == 'S'? rep = true : rep = false; 
	system("cls");
	} while(rep);
	rep = true;
}

void mostrar(estudiantes *puntero,int &size){
	
	
}

void menu()
{
    cout<<"\n\t Pila de estudiantes\n\n";
    cout<<" 1. Agregar                             "<<endl;
    cout<<" 2. Eliminar                            "<<endl;
    cout<<" 3. Mostrar lista                       "<<endl;
    cout<<" 4. Eliminar lista                      "<<endl;
    cout<<" 5. SALIR                               "<<endl;
 
    cout<<"\n Ingrese opcion: ";
}

int main(){
	system("color 0b");
	stack<estudiantes>pila; //la pila en si
	estudiantes est; // estructura para el ingreso de datos
	estudiantes *puntero; //apunta a la pila
	int accion;
	int cont; //marca el limite de la pila
	bool rep = true;
	
	do{
		
	menu();
	cin >> accion;
	
	switch(accion){
		
		case 1:
			crear(rep, est);
			pila.push(est);
			break;
			
		case 2:
			pila.pop();
			cout << "Estudiante eliminado...\n";
			break;
			
		case 3:
			puntero = &pila.top();
			while(cont < pila.size()){
				cout << "Due: " << puntero->due << "\t";//imprime el valor
				cout << "Nombre: " << puntero->nombre << "\t";//imprime el valor
				cout << "Apellido: " << puntero->apellido << "\t";//imprime el valor
				cout << "Edad: " << puntero->edad << endl;//imprime el valor
				puntero--;//reduce su posicion en 1
				cont++;//aumenta el conteo de posiciones recorridas
			}
			break;
		
		case 4:
			pila.empty();
			break;
				
		case 5: 
			rep = false;
			break;
	}
	system("pause"); system("cls");
	}while(rep);
}

//hacer menu que permita eliminar, mostrar y agregar alumnos
