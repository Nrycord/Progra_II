#include<cstdlib>
#include<iostream>
#include<stack>
using namespace std;

int main(void){

//pila que almacena el abecedario.

	//tipo de dato que va a tener la pila
	stack<char> p; //Aparta cierto espacio en la memoria.
	char *puntero;
	int cont;
	//p.push('A');
	
	/////////////////////////////////LLenado de pila
	for(int i = 'A'; i <= 'Z'; i++){ //recordar que las letras son tomadas como entero y luego son transformadas a binario. Ej: 'A' = 65, 'B' = 66, etc
		p.push(i);//agrega la letra a la pila

	}
	/////////////////////////////////LLenado de pila
	puntero = &p.top();
	
	//	while( !p.empty() ) si la pila no esta vacia
	while( cont < p.size() ){ //mientras el contador sea menor a el tamaño de la pila
	char aux;
	aux = *puntero;//asigna el valor de la ubicacion a un auxiliar
	cout << aux << " ";//imprime el valor
	puntero--;//reduce su posicion en 1
	cont++;//aumenta el conteo de posiciones recorridas
	
	
		
	/*cout << p.top() << " "; //Imprime el valor del tope
	p.pop(); //elimina el ultimo elemento*/
		
	}
	cout << endl;
	system("pause");
	return 0;
}

//crear un programa que permita crear una pila para almacenar los datos de los estudiantes de programacion 2, se debe de almacenar el due, nombre, apellido y la edad. //insertar y mostrar lo datos

