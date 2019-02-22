#include<iostream>
using namespace std;

struct nodo{//cada ubicacion de la pila
	int nro;
	//char nombre;
	//char apellido; //pueden insertarse cualquier tipo de datos que se van a necesitar

	//se utiliza como "nodo", porque debe apartar cuantos bit sean necesarios independientemente de cuantos datos hayan
	nodo *sgte;/*un puntero de tipo nodo, apunta a la misma estructura
	ayuda a crear el espacio para el siguiente elemento de la pila
	nro crea la espacio en negro, *sgte crea el espacio azul*/
};

typedef nodo *ptrPila; //creando nodo tipo puntero (tipo de dato), crea un alias del tipo de dato

/* Ej: typedef int Entero; //ahora el tipo de datos int es como poner Entero en vez de poner int */

void push(ptrPila &p, int valor){
	//p tiene el valor de la pila
	//aux almacena momentariamente un valor
	ptrPila aux; 
	aux = new(struct nodo) //apuntamos al nuevo nodo creado, creamos otra estructura en aux (espacio para valor y para el siguiente)
	
	
	//a->x ---> hace que la varaible apunte a cierto dato;
	
	//esta parte manda a llamar a la estructura creada para aux
	//el valor de nro de aux sera igual al valor
	aux->nro = valor; //asigna al tope de la pila el valor a anexar
	//crea el espacio siguiente
	aux->sgte = p; //aux estara apuntando a p
	//como sgte es una estructura tipo nodo, todo el valor de p se almacena en la estructura de sgte 	
	p = aux; //le pasa el valor que se quiere ingresar a la pila en su ultimo valor
}



