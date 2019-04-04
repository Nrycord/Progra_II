//Hacer que ahora funcione con las coodenadas x, y y z
#include<iostream>
using namespace std;

/*+-+-+-+-+-+-+-+-+-+-+CLASE+-+-+-+-+-+-+-+-+-+-+*/
class Cola{
	
	/*Atrributo*/
	class Nodo{ /*Estructura o tipo de dato Nodo de la clase*/
		public:
			int info;
			Nodo *sig;
	};
	/*------------------------------*/
	Nodo *raiz; //El primer elemento de la cola (el que fue ingresado primero y el primero en salir)
	Nodo *fondo; //El ultimo elemento de la cola(el que acaba de ser ingresado, el ultimo en salir)
//fondo(el que se acaba de ingresar)	 raiz(primero ingresado de toda la cola)
	//+-------------------------------------------------+ -> 
	public:
		Cola(); //Constructor
		~Cola(); //Destructor
		void insertar(int x); //Ingreso de datos
		int extraer(); //Elimina un elemento de la cola
		void imprimir(); //Muestra los elementos de la cola
		bool vacia(); //Verifica si la cola esta vacia
			
};
/*+-+-+-+-+-+-+-+-+-+-+CLASE+-+-+-+-+-+-+-+-+-+-+*/

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
void Cola::insertar(int x){
	Nodo *nuevo;
	nuevo = new Nodo();
	nuevo->info = x;
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
int Cola::extraer(){
	if(!vacia()){
		int informacion = raiz->info;
		Nodo *bor = raiz;
		if(raiz == fondo){ //Cuando solo hay un elemento
			raiz = NULL;
			fondo = NULL;
		}
		else
			raiz = raiz->sig;
		
		delete bor;
		return informacion;
	}
	else
		return -1;
	}
/*+-+-+-+-+-+-+-+-+-+-+Extractor+-+-+-+-+-+-+-+-+-+-+*/

/*+-+-+-+-+-+-+-+-+-+-+Imprimir+-+-+-+-+-+-+-+-+-+-+*/
void Cola::imprimir(){
	Nodo *reco = raiz;
	while(reco != NULL){
		cout << reco->info << "\n";
		reco = reco->sig;
	}
	cout << endl;
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

/*+-+-+-+-+-+-+-+-+-+-+MAIN+-+-+-+-+-+-+-+-+-+-+*/
int main(){
	
	Cola *cola1 = new Cola();
	
	for(int i=0;i<10;i++){
		cola1->insertar(i);	
		cola1->imprimir();
		cout << endl;
	}

	cola1->extraer();
	cola1->imprimir();
	cola1->extraer();
	cola1->imprimir();
	delete cola1;
	cin.get();
	return 0;
}
/*+-+-+-+-+-+-+-+-+-+-+MAIN+-+-+-+-+-+-+-+-+-+-+*/
