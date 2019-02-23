//Creado por: Carlos Cordero. CL18030
#include <iostream> //ingreso y salida de datos
using namespace std;
//evalua cual de los numeros es el menos de dos opciones, asigna el valor de 0 al menor
int menorACero(int&,int&);
void cl(int &);

int main(){ 
	int a,b;
	cout << "Ingrese el primer numero: "; cin >> a;
	cl(a);
	cout << "Ingrese el segundo numero: "; cin >> b;
	cl(b);
	menorACero(a,b);
	cout << "El valor a = " << a << "\nEl valor b = " << b << endl;
}

int menorACero(int &a,int &b){
	if(b > a){
		a = 0;
		cout << "El primer numero es el menor" << endl;
	}
	else if(a > b){
		b = 0;
		cout << "El segundo numero es el menor" << endl;
	} 
	else{
		cout << "Ambos numeros son iguales" << endl;
	}
}

void cl(int &a){
	if(cin.fail()){
		cin.clear();
		cin.ignore();
		a = 0;
		cout << "ingrese un numero entero." << endl;
		system("pause");
		exit(1);
	}
}
