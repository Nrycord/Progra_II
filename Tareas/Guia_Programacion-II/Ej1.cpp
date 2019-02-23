//Creado por: Carlos Cordero. CL18030
#include <iostream> //ingreso y salida de datos
using namespace std;
//Si el primer numero es mayor, intercambia el valor de las variables
int mayor(int*, int*);

int main(){
 
	int x, y;
	cout << "Ingrese el valor de x:"; cin >> x;
	cout << "Ingrese el valor de y:"; cin >> y;
	mayor(&x,&y);
	cout << "Los valores ahora son: x=" << x << " y  y=" << y << endl;

}
	
int mayor(int *a, int *b){//evalua cual variable es la mayor
	int aux;
	if(*a > *b){ //si a es mayor que b, entonces intercambia los valores
	aux = *a;
	*a=*b;
	*b=aux;
	cout << "x es el numero mayor." << endl;
	}
	else if(*a == *b){//de otra forma no realiza nada mas
		cout << "Los valores son iguales." << endl;
	}
	else{
		cout << "y es el manor numero" << endl;
	}
}
