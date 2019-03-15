#include<iostream>
#include<stack> //cuando una pila esta vacia, apunta a un valor nulo, el primer dato de la pila siempre sera nulo
using namespace std;

//Estructuras dinamicas en c++ %20 Listas tipo pila

class Pila { //las clases inician con mayuscula
	private: //a la estructura se le considera como un objeto cuando entra con pilas
		//Los datos de una clase son obligatoiamente privados
		//Todos los atributos deberian ser privados por motivos de seguridad.
		class Nodo{
			public: //modificador de acceso
				int info;
				Nodo *sig; //aparta el espacio para la siguiente espacio para el nodo
		};
		Nodo *raiz;//Hara el papel del tope de la pila, se puede asignar un valor inicial
		//por defecto de pone como NULL
	
	public://modificador de acceso
		
		/*--------------------Obligatorios------------------------------------*/
Pila(); /*constructor de la clase. Desde que se crea una variable de tipo pila, 
ejecuta la funcion. Puede llegar a asignar valores por defecto*/

~Pila(); //Es el destructor, vacia la clase y la elimina cada vez que no sea necesaria
		
		/*--------------------Obligatorios------------------------------------*/
		
		void insertar(int x);
		int extraer();
		void imprimir();
		
};
//"Nombre de la clase" :: "Funcion que se realizara"
Pila::Pila(){//constructor
	raiz = NULL; //Aqui se puede asignar un valor por defecto para la clase
	//TOMAR RAIZ COMO UN TOPE
}

void Pila::insertar(int x){
	Nodo *nuevo; //deja un espacio para un entero y para un nodo
	nuevo = new Nodo(); //alojamos el espacio necesario
	nuevo->info = x; //el entero de nuevo sera igual al dato ingresado
	if(raiz == NULL){ //si es el primer dato, raiz = NULL
		raiz = nuevo; //la raiz ahora apunta al valor de nuevo
		nuevo->sig = NULL; //Deja el siguiente valor de nuevo como NULL
	}
	else{ //capitulo 5 de depper
		nuevo->sig = raiz; //El valor del tope ahora apunta a el espacio en nodo
		//el dato sig de nuevo se le asigna la direccion de raiz,
		
		raiz = nuevo; //el tope se actualiza (raiz se mueve), dejando la direccion de el dato
		//ingresado como un nuevo tope siempre bajo el mismo nombre de raiz.
		
		//de esta forma el valor de raiz es absorvido por nuevo, y nuevo se convierte en la nueva raiz (nuevo tope)
	}
}

int Pila::extraer(){
	if(raiz != NULL){
		int informacion = raiz->info; //almacena el valor que tiene el valor del tope
		Nodo *bor = raiz; //almacena la direccion del tope actual
		raiz = raiz->sig; //reduce el tope en un "Nodo" (un espacio o cadena del nodo)
		delete bor;//borra los datos de el tope, elimina la direccion de memoria a la que apunta
		return informacion;//retorna el dato eliminado
		delete &bor; //borra los datos almacenados en la posicion bor
	}
	else{
		return -1;
	}
}

void Pila::imprimir(){
	Nodo *reco = raiz;
	cout << "Lista de datos almacenados en la pila: \n";
	while(reco != NULL){
		cout << reco->info << "-";
		reco = reco->sig;
	}
	cout << "\n";
	
}

Pila::~Pila(){
	Nodo *reco = raiz; //asigna reco a la posicion del tope de la pila
	Nodo *bor; //variable Nodo con la que apuntaremos al dato a borrar en reco
	
	while(reco != NULL){
		bor = reco; //asigna bor a la posicion de reco actual
		reco = reco->sig;//reco retrocede en un espacio en la pila
		delete bor;//borra la direccion que esta apuntando (el dato reco del tope de la pila)
	}
}




int main(){
	Pila *pila1;
	pila1 = new Pila(); //el new gestiona y aparta el espacio para el objeto. Pila() llama al constructor
	//new divide y aparta el espacio 
	
	pila1->insertar(10); //ingresa un dato al objeto
	pila1->insertar(40);
	pila1->insertar(3);
	pila1->imprimir(); //imprime todos los datos
	pila1->extraer();
	pila1->~Pila();//destruye la pila
	
}


//crear menu a esta aplicacion. y crear el metodo buscar, es como el de mostrar, solo que agregar un if
