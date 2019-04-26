#include<string>               
#ifndef MISCLASES_H
#define MISCLASES_H
using namespace std;

class Empleado { //CLase de tipo abstracta
	// Private section
	int codigo;
	string tipo;
	float total;
	
	public:
		Empleado(){
		}
		~Empleado(){
		}
		void setCodigo(int cod){
			this->codigo = cod;
		}
		int getCodigo(){
			return this->codigo;
		}
		void setTipo(string tp){
			this->tipo = tp;
		}
		string getTipo(){
			return this->tipo;
		}
		void setTotal(float tot){
			this->total = tot;
		}
		float getTotal(){
			return this->total;			
		}
		
		//metodo virtual
		virtual void calculo(float salario)=0; //metodo abstracto
		
		// Public Declarations
};

class Interface{ //Clase de tipo interfaz
	public: 
		virtual float getCalculo(float salario)=0;
};

class ISSS:public Interface{
	public:
		float getCalculo(float salario){
			float isss = 0;
			
			if(salario > 600){
				isss = 600*0.03f; //f = flotante
			}
			else{
				isss = salario*0.03f; //f = flotante
			}
			return isss;
		}
};

class Iva:public Interface{
	public:
		float getCalculo(float salario){
			float iva = 0;
			
			if(salario > 600){
				iva = 600*0.15f; //f = flotante
			}
			else{
				iva = 0; //f = flotante
			}
			return iva;
		}
};
#endif


