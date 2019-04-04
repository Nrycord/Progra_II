#include<iostream>
using namespace std;



struct nodo{
	int nro;
	nodo *izq,*der;
};
			//objeto 	//nuevo nombre
typedef 	struct nodo 	*ABB; //buscar que es lo que hace
//le pone un alias a un tipo de dato, 


void insertar(ABB &arbol, int x){
	//1- arbol = NULL; x = 2
	//2- arbol = 001; x = 7		arbol = 001->der =NULL
	if(arbol == NULL){
		ABB nuevoNodo = new(nodo);
	nuevoNodo->nro = x;
	nuevoNodo->izq = NULL;
	nuevoNodo->der = NULL;
	arbol = nuevoNodo;	
	}
	else if(x < arbol->nro)
		insertar(arbol->izq,x);
		
	else if(x > arbol->nro)
		insertar(arbol->der,x);
}

void verArbol(ABB arbol,int n){
	if(arbol == NULL)
		return;
	verArbol(arbol->der,n+1);
	for(int i = 0; i < n; i++){
		cout << "     ";
	}
		cout << arbol->nro << endl;
		verArbol(arbol->izq, n+1);
}

void preorden(ABB arbol){
	if(arbol!=NULL){
		cout << arbol->nro << " ";
			preorden(arbol->izq);
			preorden(arbol->der);
	}
}


int main(){
	
	ABB arbol = NULL;
	int x;// dato a insertar
	int n;// numero de nodos
	cout << "ARBOL BINARIO\n";
	cout << "Ingrese el numero de nodos del arbol\n->";
	cin >> n;
	
	for(int i = 0; i <= n; i++){
		cout << "Ingrese el valor de nodo:\n->";
		cin >> x;
		insertar(arbol,x); //toma una direccion e memoria y pone un valor
		//cada vez que se llama a insertar se mueve el nodo primcipal
		//la primera vez se situa en la raiz, la segunda baja a uno de los hijos y lo vuelve padre
	}
	
	cout << "Mostrando el arbol:\n";
	verArbol(arbol,n); //se llama a ella misma bajando por cada nodo padre.
	
	cout << "Mostrando el arbol en preorden\n";
	preorden(arbol);
	
	
	cout << "Presione cualquier tecla para continuar...";
	cin.get();cin.get();
	return 0;
}
//Tarea: hacer los recorridos de forma manual para la insercion de nodos de un arbol binario usando el de la clase, ete de aqui).
//reflejar como cambia la memoria a partir de la direccion primera (mostrar en que posiciones se encuentra al introducir un nuevo nodo (en cuadritos por ejemplo))

/* Utilizando este arbol, se puede usar size para ver el tamaño del nodo.
Un dibujo de la memoria por cada incersion (en un rectangulo, se escribe cada recuadro

				4
		2				6
	1		3		5		7



					<-(2)->
		  <-(7)->						(5)->
	(2)->				(6)->					<-(9)
		(5)				(11)			(4)
*/
