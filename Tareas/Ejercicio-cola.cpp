#include<iostream> //ingreso y salida de datos
#include<queue> //se encarga del funcionamiento de la cola
#include<windows.h> //se encarga de los colores de la consola el programa
using namespace std;

/* Hecho por carlos enrique cordero linares CL18030*/


//Hacer una cola de datos, para almacenar el numero de tickets(4 dijitos) el numero de cuenta y la edad de un ahorrante Ponerle agregar ahorrante y eliminar de la cola un ahorrante

struct Ahorrante{ //Estructura que marca que informacion se requiere para cada cliente
	char ticket[5];
	int nCuenta;
	int edad;
};


	/*-----------------------Limpiar ingresos de datos erroneos--------------------*/
void clear(bool &rep){ //Limpia la variable en caso de que el tipo de dato sea el incorrecto

	
	if(cin.fail()) //si al ingresar el dato da error
	{
		system("color 84");
		rep = true;
		cin.clear(); //limpia la variable para que pueda ser ingresada nuevamente
		cin.ignore();
		cout << "Ingrese un valor valido\n\n";
	}
	else{
		rep = false; //el dato no es erroneo
		system("color 80"); //cambia el color del texto a rojo, para simbolizar un error
	}
}
	/*-----------------------Limpiar ingresos de datos erroneos--------------------*/


	/*-----------------------Ingresar ahorrante--------------------*/
void ingresar(Ahorrante *aux){
	bool rep = false; //indica si un dato fue ingresado erroneamente
	do{
	cout << "Ingrese el codigo del ticket:\n-->"; cin >> aux->ticket;
	clear(rep);
	}while(rep); //mientras el dato sea erroneo, seguira pidiendo un valor valido
	
	do{
	cout << "Ingrese su numero de cuenta:\n-->"; cin >> aux->nCuenta;
	clear(rep);
	}while(rep); //mientras el dato sea erroneo, seguira pidiendo un valor valido
	
	do{
	cout << "Ingrese su edad:\n-->"; cin >> aux->edad;
	clear(rep);
	}while(rep); //mientras el dato sea erroneo, seguira pidiendo un valor valido
}
	/*-----------------------Ingresar ahorrante--------------------*/


	/*-----------------------Imprimir ahorrante--------------------*/
void imprimir(Ahorrante *ptrfront, int longitud){
	
	while(longitud>0){
		system("color 85");//cambia el colo por razones esteticas
		cout << "Su numero de ticket es: " << ptrfront->ticket << "\t";
		cout << "Su numero de cuenta es: " << ptrfront->nCuenta << "\t";
		cout << "Usted tiene " << ptrfront->edad << " anios.\n\n";
		ptrfront++; //aumenta la posicion del puntero
		longitud--; //disminuye en uno la cantidad de espacios que faltan por recorrer
	}
}
	/*-----------------------Imprimir ahorrante--------------------*/


int main(){
	
	queue<Ahorrante> cola; //se crea la cola
	Ahorrante aux; //creamos un auxiliar con el que se ingresaran los datos
	Ahorrante *ptrfront; //creamos un puntero con el que vamos a acceder a los datos.
	int longitud; //marca la longitud de la cola
	int op; //es la opcion que el usuario desee ingresar
	
	do{
	system("color 80");
	cout << "Que opcion desea realizar:\n1-agregar\n2-Mostrar\n3-Eliminar\n4-salir\n-->";		
	cin >> op;
	
	switch(op) {
		case 1:
			ingresar(&aux);
			cola.push(aux); //agrega el ahorrante ingresado a la cola
			ptrfront = &cola.front();//apunta al inicio de la cola
			break;
			
		case 2:
			if(!cola.empty()){
			longitud = cola.size();
			imprimir(ptrfront,longitud);
			}
			else
				cout << "La cola esta vacia\n";
			break;
			
		case 3:
			if(!cola.empty())
			{
				cola.pop();//elimina el primer valor de la fila
				cout << "El cliente ha sido eliminado\n";
				ptrfront = &cola.front();//apunta al inicio de la cola	
			}
			else
				cout << "La cola esta vacia\n";	
			break;
		
		case 4:
			break;
				
		default:
			cout << "Ingrese un valor dentro del rango\n";
		}
		
		cout << "Presione cualquier tecla para continuar...";
		cin.get();cin.get();//Pausa el sistema
		system("cls");//limpia la pantalla
		
	}while(op != 4);
}
