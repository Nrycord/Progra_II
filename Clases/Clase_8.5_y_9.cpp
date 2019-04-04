/*
/Jueves 21 de marzo 2019
//ARBOLES BINARIO
//NODO PADRE
//NODO  MAX 2 HIJOS NODOS
//NODO HOJA NO TIENE HIJOS NODOS

//UN NODO PUEDE APUNTAR A mas de dos NODOS



TIPOS DE ORDEN DE UN ARBOL
//PRE- ORDEN
ORDEN
POS- ORDEN

crear un arbol de ingresar undato saver que nodo esta a la izquierda y ala derecha
por eso se necesita dos punteros


Arbol:                      2
					7				5
				2     6                 9
					5	11					4



*/

#include <iostream>
#include <string.h>
using namespace std;


/* CLASE 8.5

struct nodo{
	int nro; //siempre es importante utilizar un orden numerico con los arboles binarios por facilidad de codigo, aunque se puede hacer con caracteres.
	
	struct nodo *izq,*der;
};

typedef struct nodo* ABB;

void insertar(ABB &arbol,int x){
	//1. ARBOL=1, x=2
	//2. arbol=008 x=7
	
	if(arbol==NULL){
	ABB nuevonodo= new(nodo);
	
	nuevonodo->nro=x;
	nuevonodo->izq=NULL;
	nuevonodo->der=NULL;
	arbol=nuevonodo;
}
	else if(x<arbol->nro){
		insertar(arbol->izq,x);
	}
	else if(x>arbol->nro,x){
		insertar(arbol->der,x);
	}
}

ABB unirABB(ABB izq, ABB der){
	if(izq == NULL) return der;
	if(der == NULL) return izq;
	
	ABB centro = unirABB(izq->der,der->izq);
	izq->der = centro;
	der->izq = izq;
	return der;
}

void eliminar(ABB &arbol, int x){
	if(arbol == NULL)
		return;
	else if(x < arbol->nro)
		eliminar(arbol->izq,x); //izquierdo los mas pequeños
	else if(x > arbol->nro)
		eliminar(arbol->der,x);//derecho los mas grandes
	else{
		ABB p = arbol;
		arbol = unirABB(arbol->izq,arbol->der);
		delete p;
	}
}

int nHojas(ABB arbol){
	if(arbol == NULL){
		return 0;
	}
	else if((arbol->der == NULL) && (arbol->izq == NULL))
		{
			return 1;
		}
	else{
		return ( nHojas(arbol->izq) + nHojas(arbol->der) );
		}
	
}

void verarbol(ABB arbol,int n){
	if(arbol==NULL)
		return;
	verarbol(arbol->der,n+1);
	for(int i=0;i<n;i++){
		cout<<"     ";
	}	
	
	cout<<arbol->nro<<endl;
	verarbol(arbol->izq,n+1);
}

void preOrden(ABB arbol){
	if(arbol!=NULL){
		cout<<arbol->nro<<"    ";//raiz
		preOrden(arbol->izq);//izquierdo
		preOrden(arbol->der);//derecho
	}
}

void posOrden(ABB arbol){
	if(arbol!=NULL){
		posOrden(arbol->der);//derecho
		posOrden(arbol->izq);//izquierdo
		cout<<arbol->nro<<"    ";//raiz
	}
}
	
void inOrden(ABB arbol){
	if(arbol!=NULL){
		inOrden(arbol->izq);//izquierdo
		cout<<arbol->nro<<"    ";//raiz
		inOrden(arbol->der);//derecho
	}
}

int main(){
	ABB arbol=NULL;
	int x;//dato a insertar en el nodo
	int n;//numero de nodos
	int elim;
	
	cout<<"ARBOL BINARIO: "<<endl;
	cout<<"Ingrese el numero de nodos del arbol: "<<endl;
	cin>>n;
	
	for(int i=0;i<n;i++){
		cout<<"Ingrese el valor del nodo: "<<endl;
		cin>>x;
		insertar(arbol,x);
	}
	
	cout<<"Mostrando el arbol en pre-orden"<<endl;
	preOrden(arbol);//funcion recursiva
	cout << endl;
	cout << "Mostrando el arbol en pos-orden\n";
	posOrden(arbol);
	cout << endl;
	cout << "Mostrando el arbol en in-orden\n";
	inOrden(arbol);
	cout << endl;
	verarbol(arbol,n); 
	cout << endl;
	cout << "Numero de nodos hoja: " << nHojas(arbol) << endl;
	cout << "Ingrese el nodo a eliminar: "; cin >> elim;
	eliminar(arbol,elim);
	verarbol(arbol,n);
	system("pause");
	return 0;
}
//Hacer menu de: llenar arbol, mostrar arbol(3 otras opciones (inorden, posorden, preorden) ), mostrar hojas, eliminar un nodo

CLASE 8.5*/




/*____________________________Copiar en clase 9____________________________

//Programacion estructurada-> Funciones en el main
//Programacion orientada a objetos-> Funciones por medio de clases
//Los objetos constan de diversas caracteristicas únicas (atributos) y de comportamientos (acciones).
//Una vez se establecen esos atributos se le denomia un objeto.

//Por ejemplo:
 
//Alumno seria la clase (la informacion basica que tendra un objeto
//Steven seria un objeto, porque ya tiene valores especificos

-----------------------------UN OBJETO ES UNA CLASE CON VALORES ASIGNADOS-----------------------------
-----------------------------UNA CLASE ES UNA BASE PARA AGREGAR DIVERSOS DATOS-----------------------------


0-CONSTRUIR UNA CLASE (ATRIBUTOS Y COMPORTAMIENTOS)
1-DECLARAR UN OBJETO
2-INSTANCIAR UN OBJETO (LA INSTANCIA ES LA ACCION DE CREAR UN OBJETO)
____________________________Copiar en clase 9____________________________

//TAREA: Hacer los recorridos de forma manual para la insersion de nodos de un arbol binario
//reflejar como cambia la memoria a partir de la direccion 008
//imprimir los elementos en cada nodo valor de las tres variables
/*
                4
           2        6
        1    3    5   7
*/



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//CLASE 9

class Dog{
	//atributos
	private:
		string nombre;
		string raza;
		string tamanio;
		float peso;
		float altura;
	
	//metodos
	public:
		Dog();
		~Dog();
		void ladrar();
		void comer();
		
		void setNombre(string nom);//this will set the dogs name.
		string getNombre(); //El puntero retorna la poscicion de memoria donde inicia el caracter, para el float no es necesario
		
		void setPeso(float ps);
		float getPeso();
		
		void setRaza(string rz);
		string getRaza();
		
		void setTamanio(string tmnio);
		string getTamanio();

};

void Dog::setNombre(string nom){
	nombre = nom;
}
string Dog::getNombre(){
	return nombre;
}

void Dog::setPeso(float ps){
	peso = ps;
}
float Dog::getPeso(){
	return peso;
}

void Dog::setRaza(string rz){
	raza = rz;
}
string Dog::getRaza(){
	return raza ;
}
//Herencia, polimorfismo
int main(){
	/*Encapsulamieto-> Ocultamiento del estado, es decir de los datos miembros 
	de un objeto de manera que se puede cambiar de manera que solo se pueda 
	cambiar mediante las operaciones que esten deinidas para ese proposito.
	
	Cada OBJETO esta AISLADO de el exterior de forma que esta protegido de accesos externos	
	Puede hasta haber dos datos del mismo tipo pero en clases distintas, evita que una variable afecte a otra.
	Si el atributo es privado, esta protegido de todas las demas funciones y clases.
	
	SET- ESTABLECEN VALORES A LAS PROPIEDADES DE LAS CLASES, NO RETORNAN NADA (VOID)...EJ: setNombre();
	GET- OBTENER LOS VALORES DE LAS PROPIEDADES DE LAS CLASES CUANDO ESTAS SON PRIVADAS, DE OTRA FORMA NO ES ENCAPSULAMIENTO
	//cada propiedad tendra un get y un set si llega a ser necesario
	
	*/
	
	
}
