#include<iostream>
using namespace  std;
int longitud(char *cadena);

int main(){
	/*
	int *notas;
	int array[4];
	notas = array;
	for(int i=0;i<4;i++){
		cout << "Ingrese el valor " << i+1 << ": ";
		cin >> *(notas+i);
	}//ingresa las notas de una forma lineal, osea hace la funcion de un arreglo
	for(int i=0;i<4;i++){
		cout << "El valor ingresado en el espacio " << i+1 << " es: " << *(notas+i) << endl;
		cout << "El espacio de la memoria que ocupa en el array es: " << (notas + i) << endl;
		cout << "El espacio de la memoria que ocupa en notas es: " << &notas + i << endl << endl;
		
	}//muestra las notas las cuales estan de forma adyacente a las demas en los espacios de memoria
	*/
	char *texto = "hi kittie";
	cout << longitud(texto) << endl; //a la funcion se le estan mandando la direccion de la cadena
}

int longitud(char *cadena){
	char *ptr = cadena;
	while(ptr[0] != '\0') {//mientras el puntero sea diferente de vacio
		ptr++;//ptr avanzara un espacio al valor que apunta en la direccion que tiene
	}
	return (int)(ptr - cadena); //ptr sera igual al ultimo espacio de la cadena, la resta con la cadena y lo multiploca con int para que se vuelva entero
} //(ptr - cadena) == resta de direcciones, (int)() == multiplicar por un int (convertirlo en entero)
