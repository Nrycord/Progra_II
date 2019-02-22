#include<iostream> //ingreso y salida de datos
using namespace  std;

int longitud(char *cadena); //Marca la longitud que tiene la cadena de texto
string invertir(char *cadena);//invierte el orden de los caracteres de la cadena recibida

void clear(char *cadena){ //limpia la variable que se acava de ingresar
		cin.clear();
		cin.ignore();
}

int main(){
	bool repetir = true; //maneja el ciclo que permite repetir la ejecucion del programa
	string a;//maneja el ingreso de la eleccion de si sera necesario repetir el ciclo
	string ingresar;//es el arreglo inicial que se ingresa (el que posteriormente sera invertido)
	char *array;//es el arreglo que se utilizara internamente en el programa
	
	do{//inicio del  ciclo
	cout << "Ingrese el texto a invertir: ";
	getline(cin,ingresar); //el usuario ingresa la cadena de texto
	cout << "Presione enter para continuar..." << endl;
	cin.ignore();//elimina caracteres adicionales.
	array = &ingresar[0]; //asigna el valor del arreglo ingresado por el usuario al que se utilizara en el programa
	cout<< "El resultado es: \n-->" << invertir(array) << endl; //manda a llamar la funcion que invierte el arreglo
	cout << "desea repetir el proceso? (s/n): ";
	cin >> a;//ingresa la opcion que determinara si se repite el proceso desde ingresar una cadena hasta invertirla
	(a == "N" or a == "n" ) ? repetir = false : repetir; //si ingresa ya sea n o N el proceso se finaliza al llegar al final del ciclo
	
	clear(array);//limpia la variable arreglo, de esa forma si se llega a reiniciar
	//el ciclo el usuario puede ingresar la cadena nuevamente
	system("cls");//limpia la pantalla
	}while(repetir);//fin del ciclo
	
	cout << "Pase un feliz dia" << endl;
}


int longitud(char *cadena){
	char *ptr = cadena;
	
	while(ptr[0] != '\0') {//mientras el puntero sea diferente de vacio
		ptr++;//ptr avanzara un espacio al valor que apunta en la direccion que tiene
	}
	return (int)(ptr-cadena); //ptr sera igual al ultimo espacio de la cadena, la resta con la cadena y lo multiplica con int para que se vuelva entero
}

string invertir(char *cadena){
	char *ptr2 = cadena;
	int i = (longitud(cadena));
	char inverso[50] = {0};
	
	while(ptr2[0] != '\0') {//mientras el puntero sea diferente de vacio
		inverso[i-1] = ptr2[0];
		ptr2++;//ptr avanzara un espacio al valor que apunta en la direccion que tiene
		i--;
	}
	return inverso; //ptr sera igual al ultimo espacio de la cadena, la resta con la cadena y lo multiploca con int para que se vuelva entero

}
