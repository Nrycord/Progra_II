#include <iostream>
#include <stack>
#include <conio.h>
using namespace std;

struct Llantas{
	int codigo;
	char marca[20];
};

int main(){
	Llantas arreglo_llantas[0];
	Llantas aux = {0};
	int n = 1;
	char resp;
	do{
		cout << "cod: "; cin >> aux.codigo;
		cout << "maraca: "; cin >> aux.marca;
		arreglo_llantas[n] = aux;
		n++;
		cout << n << endl;
		cout << "Quiere crear otro nodo?: (s,n) \t"; cin >> resp;
	}while(resp == 's' || resp == 'S');


	for(int i=1; i <= n-1; i++){ //n-1 porque termina con un numero mayor del correcto debio al n++ del ciclo anterior
		cout << "Cod " << i-1 << ":\t" << arreglo_llantas[i].codigo << endl;
		cout << "Marca " << i-1 << ":\t" << arreglo_llantas[i].marca << endl;
		
	}
	cin.get();
	return 0;
} //dar la opcion de agregar, eliminar y buscar, el valor de n esta dando problemas

