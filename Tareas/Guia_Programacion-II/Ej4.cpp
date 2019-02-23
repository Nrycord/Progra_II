//Creado por: Carlos Cordero. CL18030
#include <iostream> //ingreso y salida de dtos
using namespace std;
//obtiene el area de un cuadrado o de un cubo
void area();

int main(){ 

	area();

}

void area(){
	bool rep = true;
	do{ //el ciclo se repetira hasta que el usuario desea finalizarlo
	float L;
	float resultado;
	int op;
	cout << "De que figura desea encontrar el area, Cuadrado(1) o Cubo(2): "; cin >> op;
	switch(op){
	
	case 1://si es un cuadrado multiplica Lado * Lado
		cout << "Ingrese la logitud de la figura: "; cin >> L;
		resultado = L*L;
		break;
	case 2://si es un cubonultiplica Lado * Lado * Lado
		cout << "Ingrese la logitud de la figura: "; cin >> L;
		resultado = L*L*6;
		break;
	default://si ingresa un dato fuera del rango
		cout << "Ingrese un numero dentro del rango" << endl;
		cin.clear();
		cin.ignore();
		exit(1);
	}
	}
	cout << "El resultado es: " << resultado << endl;//muestra el resultado
	system("pause");
	system("cls");
	}while(rep);//fin del ciclo
}
