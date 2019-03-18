//Insertar, eliminar, mostrar, mostrar promedio, etc
#include<iostream>
#include <string.h>
using namespace std;

/*+-+-+-+-+-+-+-+-+-+-+CLASE+-+-+-+-+-+-+-+-+-+-+*/
class Cola{
	
	/*Atrributo*/
	class Nodo{ /*Estructura o tipo de dato Nodo de la clase*/
		public:
			float x;
			float y;
			float z;
			Nodo *sig;
	};
	/*------------------------------*/
	Nodo *raiz; //El ultimo elemento
	Nodo *fondo; //El primer elemento de la cola

	public:
		Cola(); //Constructor
		~Cola(); //Destructor
		void insertar(float x,float y,float z); //Ingreso de datos
		float extraer(); //Elimina un elemento de la cola
		void imprimir(); //Muestra los elementos de la cola
		bool vacia(); //Verifica si la cola esta vacia
		void promedio();		
};
/*+-+-+-+-+-+-+-+-+-+-+CLASE+-+-+-+-+-+-+-+-+-+-+*/

/*+-+-+-+-+-+-+-+-+-+-+Centrar texto+-+-+-+-+-+-+-+-+-+-+*/
void centerstring(string s)
{ //codigo obtenido de: https://www.dreamincode.net/forums/topic/13749-center-text-with-cout/
   int l=strlen(s.c_str());
   int pos=(int)((115-l)/2);
   for(int i=0;i<=pos;i++)
    cout<<" ";
   
   cout<<s;
}
/*+-+-+-+-+-+-+-+-+-+-+Centrar texto+-+-+-+-+-+-+-+-+-+-+*/

/*+-+-+-+-+-+-+-+-+-+-+Limpiar variable+-+-+-+-+-+-+-+-+-+-+*/
void clear(bool &rep){ //Limpia la variable en caso de que el tipo de dato sea el incorrecto	
	if(cin.fail()) //si al ingresar el dato da error
	{
		rep = true;
		cin.clear(); //limpia la variable para que pueda ser ingresada nuevamente
		cin.ignore();
		cout << "Ingrese un valor valido\n\n";
	}
	else
		rep = false; //el dato no es erroneo
}
/*+-+-+-+-+-+-+-+-+-+-+Limpiar variable+-+-+-+-+-+-+-+-+-+-+*/

/*+-+-+-+-+-+-+-+-+-+-+Constructor+-+-+-+-+-+-+-+-+-+-+*/
Cola::Cola(){
	raiz = NULL;
	fondo = NULL;
}
/*+-+-+-+-+-+-+-+-+-+-+Constructor+-+-+-+-+-+-+-+-+-+-+*/

/*+-+-+-+-+-+-+-+-+-+-+Destructor+-+-+-+-+-+-+-+-+-+-+*/
Cola::~Cola(){ //En este caso se va eliminando como si fuera pila, al final no da problemas si se utiliza fondo o pila
	Nodo *reco = raiz; //reco apunta al ultimo valor de la cola
	Nodo *bor; //Puntero auxiliar que toma el ultimo nodo de la cola para eliminarlo
	while(reco != NULL){ //si reco no esta vacío
		bor = reco; //se le asigna el valor de reco a bor
		reco = reco->sig; //reco adquiere el valor de un dato anterior
		delete bor; //Se borra el ultimo elemento de la cola
	}
}
/*+-+-+-+-+-+-+-+-+-+-+Destructor+-+-+-+-+-+-+-+-+-+-+*/

//Raiz y fondo tienen la misma direccion

/*+-+-+-+-+-+-+-+-+-+-+Insertar+-+-+-+-+-+-+-+-+-+-+*/
void Cola::insertar(float x,float y,float z){
	Nodo *nuevo;
	nuevo = new Nodo();
	nuevo->x = x;
	nuevo->y = y;
	nuevo->z = z;
	nuevo->sig = NULL;
	if(vacia()){
		raiz = nuevo;
		fondo = nuevo;
	}
	else{
		fondo->sig = nuevo;
		fondo = nuevo;
	}
}
/*+-+-+-+-+-+-+-+-+-+-+Insertar+-+-+-+-+-+-+-+-+-+-+*/

/*+-+-+-+-+-+-+-+-+-+-+Extractor+-+-+-+-+-+-+-+-+-+-+*/
float Cola::extraer(){
	if(!vacia()){
		float xeliminado = raiz->x;
		float yeliminado = raiz->y;
		float zeliminado = raiz->z;
		
		Nodo *bor = raiz;
		if(raiz == fondo){ //Cuando solo hay un elemento
			raiz = NULL;
			fondo = NULL;
		}
		else
			raiz = raiz->sig;
		
		delete bor;
		return xeliminado,yeliminado,zeliminado;
	}
	else
		centerstring("La cola esta vacia\n");
	}
/*+-+-+-+-+-+-+-+-+-+-+Extractor+-+-+-+-+-+-+-+-+-+-+*/

/*+-+-+-+-+-+-+-+-+-+-+Imprimir+-+-+-+-+-+-+-+-+-+-+*/
void Cola::imprimir(){
	if(!vacia()){
		Nodo *reco = raiz;
		int i=1;
		while(reco != NULL){
			centerstring("El valor x");
			cout << i << ": " << reco->x << "\n";
			centerstring("El valor y");
			cout << i << ": " << reco->y << "\n";
			centerstring("El valor z");
			cout << i << ": " << reco->z << "\n\n\n";
			reco = reco->sig;
			i++;
		}
	cout << endl;

	}else
		centerstring("La cola esta vacia\n");
}
/*+-+-+-+-+-+-+-+-+-+-+Imprimir+-+-+-+-+-+-+-+-+-+-+*/

/*+-+-+-+-+-+-+-+-+-+-+Vacio+-+-+-+-+-+-+-+-+-+-+*/
bool Cola::vacia(){
	if(raiz == NULL)
		return true;
	else
		return false;
}
/*+-+-+-+-+-+-+-+-+-+-+Vacio+-+-+-+-+-+-+-+-+-+-+*/

/*+-+-+-+-+-+-+-+-+-+-+Promedio+-+-+-+-+-+-+-+-+-+-+*/
void Cola::promedio(){
	Nodo *aux = raiz; //maneja las direcciones, pasara por todos los datos de la cola
	Nodo *prom = new Nodo(); //almacenara la sumatoria y luego el promedio de cada coordenada
	int i = 0;
		if(!vacia()){
			while(aux != NULL){ //verificar y cambiar la condicion
				prom->x += aux->x;
				prom->y += aux->y;
				prom->z += aux->z;
				aux = aux->sig;
				i++;
			}
		prom->x = prom->x/i;	
		prom->y = prom->y/i;
		prom->z = prom->z/i;
		centerstring("El promedio de x es de: "); cout << prom->x << endl;
		centerstring("El promedio de y es de: "); cout << prom->y << endl;
		centerstring("El promedio de z es de: "); cout << prom->z << endl;
		
		}else
			centerstring("La cola esta vacia\n");
}
/*+-+-+-+-+-+-+-+-+-+-+Promedio+-+-+-+-+-+-+-+-+-+-+*/

void menu(){
	centerstring("----------------------------------------------\n");
	centerstring("Que accion desea realizar:\n");
	centerstring("1-Insertar coordenada\n");
	centerstring("2-Mostrar coordenadas\n");
	centerstring("3-Mostrar promedios\n");
	centerstring("4-Eliminar coordenada\n");
	centerstring("5-Eliminar cola\n");
	centerstring("6-Salir\n");
	centerstring("----------------------------------------------\n");
	cout << "-->";
}
/*+-+-+-+-+-+-+-+-+-+-+MAIN+-+-+-+-+-+-+-+-+-+-+*/
int main(){
	/*Instanciando el objeto*/
	Cola *cola1 /*aparta el espacio que necesitara el nodo cola1*/ = new Cola(); /*Divide ese espacio en cuantas partes sean necesarias*/
	/*Instanciando el objeto*/
	bool rep = false;
	float x;
	float y;
	float z;
	int op;
	
	system("color 70");
	do{
	menu();
	cin >> op;
	switch(op) {
		case 1:
			do{
				cout << "Insertar valor x "; cin >> x;
				clear(rep);	}while(rep);
			do{
				cout << "Insertar valor y "; cin >> y;
				clear(rep);	}while(rep);
			do{
				cout << "Insertar valor z "; cin >> z;
				clear(rep);	}while(rep);	
			cola1->insertar(x,y,z);
			break;
		case 2:
			cola1->imprimir();
			break;
		case 3:
			cola1->promedio();
			break;
		case 4:
			cola1->extraer();
			break;
		case 5:
			delete cola1;
			centerstring("La cola ha sido eliminada...\n");
			cola1 = new Cola(); //Limpia (elimina) todos los datos de la cola, y crea uno nueva vacia
			/*o tambien ---->cola1->~Cola(); */
			break;
		case 6:
			return 0;
		default:
			centerstring("Ingrese un valor dentro del rango\n");
			cin.clear();
			cin.ignore();
	}
		
		cout << "\nPresione cualquier tecla para continuar...";
		cin.get();cin.get();
		system("cls");

	}while(true);
}
/*+-+-+-+-+-+-+-+-+-+-+MAIN+-+-+-+-+-+-+-+-+-+-+*/


//cap 24, leer deitel
