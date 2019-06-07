#include<iostream>
using namespace std;


//relacion de herencia
/*Clase figura de la clase 10*/

//relacion de dependencia
/*Clase principal de la clase 10*/

//RELACION DE AGREGACION o "todo-partes"
/* Estudia un objeto como composicion de otro 
si la clase que queremos definir tiene un atributo de la otra clase es una relacion de agregacion, se reprecenta con un rombo
atributo = Clase;
            
Recordar que las clases van con Mayuscula en el primer digito, los tipos de dato y otras variables no.

Existe la RELACION DE COMPOSICION. 
(agregacion fuerte) - es cuando hay una dependencia fuerte. Es cuando una clase con 
relacion agregacion no tiene sentido fuera de la clase con  la que se concecta Se representa con el rombo relleno

RELACION DE ASOSIACION.
Cuando una requiera servicios de la otra (muchas empresas necesitan muchos empleados.
0..* significa cardinalidad, 0,1,2,3....
* significa que no se sabe cuantos obetos se necesitaran.

Si es mas importante reflejar las relaciones - asociacion, si no se cuantos objetos habran tambien

si se quiere reflejar las dependencias

si se quiere reflejar que un objeto esta compuesto por otros objetos - asociacion


TRABAJO CON PATRONES.

SIMPLE FACTORY, patron básico de diseño y programacion. consiste en que solo una clase debe crear objetos, se le llamara Factory(Fábrica) 
tener en el main la creacion de muchos objetos realentiza el programa, por ejemplo el utilizar la clase principal en la clase 10.

a-->b   a tiene relacion de dependencia con b

Fabric aFabric;
aFabric = new ConcreteCreator();
Product producto = aCreator.factoryMethod();
producto.operacion();


*/

class Dog{
	public:
	Dog(){
		cout << "Soy un perro\n";
	}
};

class Pug:public Dog{
	public:
	Pug(){
		cout << "Soy de raza pug\n";
	}
};

class Pitbull: public Dog{
	public:
	Pitbull(){
		cout << "Soy un pitbull\n";
	}
};

class Fabric{
	public:
		Dog* crearperro(int x){
			if(x==1){
				return new Pug();
			}
			
			if(x==2){
				return new Pitbull();		
			}
			
		}
};

int main(){
	Fabric *afabric = new Fabric();
	Dog *pug = afabric->crearperro(1);
	Dog *pitbull = afabric->crearperro(2);

}
