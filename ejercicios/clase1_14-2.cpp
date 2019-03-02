#include<iostream>
using namespace std;
/*
int main()
{
	int x = 0;
	int y = 1;
	int z = 2;
	int *ip = &x;
	*ip = *ip+1; //el valor al que apunta ip (x) sera igual al valor al que apunta ip + 1 (x = 1)
	ip = ip+1; //la posicion al que apunta ip (x) sera movido +1 espacios, ahora apuntara a y
	
	*ip = *ip+1; //el valor al que apunta ip (y) sera igual al valor al que apunta ip + 1 (y = 2)
	ip = ip+1; //la posicion al que apunta ip (y) sera movido +1 espacios, ahora apuntara a z
	
	*ip = *ip+1; //el valor al que apunta ip (z) sera igual al valor al que apunta ip + 1 (z = 3)

	int arreglo[] = {3, 2, 1, 0};
	int *puntero;
	puntero = arreglo; //adquiere la direccion del primer valor del arreglo (3)
	cout << puntero[0] << endl;	
	cout << puntero[1] << endl;	
	cout << puntero[2] << endl;
	cout << puntero[3] << endl << endl;
	//se puede concluir que un arreglo fue hecho a partir de los punteros		
	cout << *puntero << endl;
	puntero = puntero + 1; //adquiere el siguiente valor del arreglo (2)
	cout << *puntero << endl;
	puntero = puntero + 1; //adquiere el siguiente valor del arreglo (1)
	cout << *puntero << endl;
	puntero = puntero + 1; //adquiere el ultimo valor del arreglo al que apunta (0)
	cout << *puntero << endl;	
	
	char *cadena = "UES-FMO";
	cout << cadena << endl; //en el caso de los char imprime todos de una vez de forma predeterminada
	
	cout << cadena[0] << endl;
	cout << *(cadena+1) << endl; //para evitar eso solo es necesario especificar que elemento 
	
}*/


/*int main(){

int x = 2;
int y = 1;

int *p = &x; //p apuntara a x (Tomara el valor de la direccion de x)
y = *p;//y sera igual al valor al que apunta p
*p = 0; //el valor al que apunta p sera igual a 0
cout << x << endl << y << endl; //y = 2, x = 0
////////////////////////////////////////////////////////////////////////////////

float *z;
for(int i = 1; i<5;i++)
{
cout << z << endl;
z += i; //avanza dos espacios en la memoria, se desplaza
cout << z << endl;
}
}*/
