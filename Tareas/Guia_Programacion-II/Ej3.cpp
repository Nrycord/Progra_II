//Creado por: Carlos Cordero. CL18030 
#include <iostream> //ingreso y salida de datos
using namespace std;
//eleva el numero deseado a un exponente que el usuario ingrese
float potencia(double n, int p);

int main(){ 
	double n;
	int p;
	cout << "Ingrese el numero a elevar: "; cin >> n;//ingresa el numero a elevar
	cout << "Ingrese la pontencia a emplear: "; cin >> p;//ingresa la potencia del numero
	cout << "El resultado es: " << potencia(n,p) << endl;
}

float potencia(double n, int p)
{
	int i = 1;
	double respuesta = 1;
	while(i <= p){//El ciclo se repite "p" veces
		respuesta = respuesta * n; //multiplica el numero repetidamente
		i++;
	}
	return respuesta;//retorna el valor resultante
}
