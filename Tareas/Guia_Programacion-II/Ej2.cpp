#include <stdio.h> 
#include <conio.h> 
#include <iostream>
using namespace std;
//multiplica el numero ingresado por 10
float x10(float mult);

int main(){

	float mult;
	cout << "Ingrese un numero a multiplicar por 10: "; cin >> mult; //ingresa el numero a multiplicar
	cout << mult << " * " << 10 << " = " << x10(mult) << endl;
	
}

float x10(float mult){
	mult *= 10; //multiplica el valor por 10
	return mult;//retorna la respuesta
}
