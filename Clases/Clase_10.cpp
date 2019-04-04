#include<iostream>
#include <math.h>
using namespace std;

class Figura{
	private:
		float base;
		float altura;
	
	public:
		//Pueden haber varios constructores gracias al polimorfismo
		Figura(){ //inicializa todas las variables en 0
			this->base = 0;
			this->altura = 0;
		}
		
		Figura(float b, float h){ //inicializa las variables en un valor espeficico
			this->base = b;
			this->altura = h;
		}
		
		//No se puede tener dos constructores que reciban la misma cantidad de argumentos y el mismo tipo de dato (de los argumentos que pide)
		~Figura(){
			
		}
		
		//se necesita crear un set y get para cada propiedad, ademas de las funciones area y perimetro
		void setBase(float b){
			this->base = b;
		}
		float getBase(){
			return this->base;
		}
		
		void setAltura(float h){
			this->altura = h;
		}
		float getAltura(){
			return this->altura;
		}
		
		virtual float area() = 0;//se iguala a 0 para definir la funcion
		//virtual significa que luego se puede sobreescribir/redefinir sobre la funcion.
		virtual float perimetro() = 0;
			
};

class Color{
	public:
		void colorear(){
			cout << "Estoy pintando\n\n\n\n";
		}
};

class Rectangulo:public Figura, public Color{
	public:
		float area(){
			return getAltura()*getBase();
		}
		
		float perimetro(){
			return ((2*getAltura())+(2*getBase()));
		}
		
		void imprimirR(){ //imprimira el rectangulo
			cout << endl;
			for(int i = 0; i < getAltura(); i++){
				
				for(int j = 0; j < getBase(); j++){
						if(i == 0 or j == 0 or j == getAltura()+1 or i == getAltura()-1){
							cout << " * ";	
						}else{
							cout << "   ";
						}
							
				}
				cout << endl;
			}
			cout << endl;
		}
		
};

class Cuadro:public Figura, public Color{
	public:
		float area(){
			return getAltura()*getBase();
		}
		
		float perimetro(){
			return ((2*getAltura())+(2*getBase()));
		}
		
		void imprimirR(){ //imprimira el cuadrado
			cout << endl;
			for(int i = 0; i < getAltura(); i++){
				
				for(int j = 0; j < getBase(); j++){
						if(i == 0 or j == 0 or j == getAltura()-1 or i == getAltura()-1){
							cout << "* ";	
						}else{
							cout << "  ";
						}
							
				}
				cout << endl;
			}
			cout << endl;
		}
		
};

class Triangulo:public Figura, public Color{ //sera la base de los otros dos tipos de triangulos que estan en el codigo
	private:
		float lado1;
		float lado2;
	public:
		
		void setLado1(float l){
			this->lado1 = l;
		}
		float getLado1(){
			return this->lado1;
		}
		
		void setLado2(float l){
			this->lado2 = l;
		}
		float getLado2(){
			return this->lado2;
		}
		
		float area(){
			float semi = (getBase() + getLado1() + getLado2())/2;
			float area = sqrt(semi*(semi-lado1)*(semi-lado2)*(semi-getBase()));
			return area;
		}
		
		float perimetro(){
			return (getLado1()+getBase()+getLado2());
		}

		virtual void imprimirR()=0;
};

class Isoseles:public Triangulo{
	
	public:
		void imprimirR(){ //imprimira el triangulo isoseles representativo
			cout << endl;
			
			for(int i = 0; i < getBase(); i++){
				int x = getBase()-i;
				for(int j = 0; i >= j; j++){
					
						while(x != 0){
							cout << " ";
							x--;
						}
						cout << "* ";				
				}
				cout << endl;
			}
			cout << endl;
		}
};

class TriRect:public Triangulo{ 
	
	public:
		void imprimirR(){ //Imprime un triangulo rectangulo representativo
			cout << endl;
			
			for(int i = 0; i < getBase(); i++){
				int x = getBase()-i;
				for(int j = 0; i >= j; j++){

						cout << "* ";				
				}
				cout << endl;
			}
			cout << endl;
		}
};

class Principal{ //mantiene la "coneccion" de el main con todos los demas objetos 
	public:
		Principal(){
			/*--------------------------Creamos e instanciamos los objetos--------------------------*/
			Rectangulo *r = new Rectangulo();
			Cuadro *c = new Cuadro();
			Isoseles *t = new Isoseles();
			TriRect *tr = new TriRect();
			/*--------------------------Creamos e instanciamos los objetos--------------------------*/
			
			//Rectangulo
			r->setAltura(4);
			r->setBase(6);		
			cout << "base: " << r->getBase() << "\naltura: " << r->getAltura() << endl;//cout << "___" << r->imprimirR();
			cout << "area: " <<  r->area() << endl << "perimetro: " << r->perimetro() << endl; 
			r->imprimirR();
			r->colorear();//Proviene desde colorear 
			//Rectangulo
			
			//Cuadrado	
			c->setBase(6);
			c->setAltura(6);
			cout << "base: " << c->getBase() << "\naltura: " << c->getAltura() << endl;
			cout << "area: " <<  c->area() << endl << "perimetro: " << c->perimetro() << endl; 
			c->imprimirR();
			c->colorear();
			//Cuadrado
			
			//Triangulo isoseles
			t->setBase(5);
			t->setLado1(5);
			t->setLado2(5);
			cout << "base: " << t->getBase() << "\nlado 1: " << t->getLado1() << "\nlado 2: " << t->getLado2() << endl;
			cout << "area: " <<  t->area() << endl << "perimetro: " << t ->perimetro() << endl; 
			t->imprimirR();
			t->colorear();
			//Triangulo isoseles
			
			//Triangulo equilatero
			tr->setBase(5);
			tr->setLado1(3);
			tr->setLado2(7);
			cout << "base: " << tr->getBase() << "\nlado 1: " << tr->getLado1() << "\nlado 2: " << tr->getLado2() << endl;
			cout << "area: " <<  tr->area() << endl << "perimetro: " << tr ->perimetro() << endl; 
			tr->imprimirR();
			tr->colorear();
			//Triangulo equilatero
			}
};

int main(){

/*	Figura *t = new Figura(); //instanciar a 0
	Figura *d = new Figura(2,3);//instanciar a 2 y 3
	
	t->setBase(4); //solo puede acceder a los metodos publicos, no puede acceder directamente a los datos altura y base.
	t->setAltura(2);
	
	cout << t->getBase() << "--" << t->getAltura() << endl;
	cout << d->getBase() << "--" << d->getAltura() << endl << endl << endl;
*/	
	
	
	/*Rectangulo *r = new Rectangulo();
	
	r->setAltura(4);
	r->setBase(6);
	
	cout << "base: " << r->getBase() << "\naltura: " << r->getAltura() << endl;//cout << "___" << r->imprimirR();
	
	cout << "area: " <<  r->area() << endl << "perimetro: " << r->perimetro() << endl; 
	
	r->imprimirR();*/
	
	
	Principal *pro = new Principal(); //es una relacion de dependencia
	
	cout << "Presione cualquier tecla para continuar...";
	cin.get();
	return 0;
}

/*AGREGAR UNA CLASE PARA UN CUADRADO Y UN TRIANGULO Y ENVIAR A GITHUB*/
