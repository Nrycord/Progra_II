#include<iostream> //ingreso y salida de datos
#include<queue> //se encarga del funcionamiento de la cola
#include<windows.h> //se encarga de los colores de la consola el programa
using namespace std;

/* Hecho por carlos enrique cordero linares CL18030*/
//almacenar coordenadas, mostrarlas y ademas mostrar un promedio de todas las coordenadas
struct coord{
	float x;
	float y;
	float z;
};


void clear(bool &rep){ //Limpia la variable en caso de que el tipo de dato sea el incorrecto

	
	if(cin.fail()) //si al ingresar el dato da error
	{
		rep = true;
		cin.clear(); //limpia la variable para que pueda ser ingresada nuevamente
		cin.ignore();
		cout << "Ingrese un valor valido\n\n";
	}
	else{
		rep = false; //el dato no es erroneo
	}
}

void agregar(coord &aux){
	bool rep = false; //indica si un dato fue ingresado erroneamente
	do{
	cout << "Ingrese la coordenada x:\n-->"; cin >> aux.x;
	clear(rep);
	}while(rep); //mientras el dato sea erroneo, seguira pidiendo un valor valido
	
	do{
	cout << "Ingrese la coordenada y:\n-->"; cin >> aux.y;
	clear(rep);
	}while(rep); //mientras el dato sea erroneo, seguira pidiendo un valor valido
	
	do{
	cout << "Ingrese la coordenada z:\n-->"; cin >> aux.z;
	clear(rep);
	}while(rep); //mientras el dato sea erroneo, seguira pidiendo un valor valido
}

void mostrar(int lng, coord *inicio){
	int i=1;
	while(lng>0){
		cout << "--------------------------------------------------------------------\n";
		cout << "La coordenada x"<<i<<" es: " << inicio->x << "\n";
		cout << "La coordenada y"<<i<<" es: " << inicio->y << "\n";
		cout << "La coordenada z"<<i<<" es: " << inicio->z << endl;
		cout << "--------------------------------------------------------------------\n\n";
		inicio++; //aumenta la posicion del puntero
		lng--; //disminuye en uno la cantidad de espacios que faltan por recorrer
		i++;
	}
}

void promedio(int lng, coord *inicio){
	coord promedio;
	int i = 0;
	while(lng>0){
		
		promedio.x += inicio->x;
		promedio.y += inicio->y;
		promedio.z += inicio->z;
		inicio++; //aumenta la posicion del puntero
		lng--; //disminuye en uno la cantidad de espacios que faltan por recorrer
		i++;
	}
	
	promedio.x = (promedio.x/i);
	promedio.y = (promedio.y/i);
	promedio.z = (promedio.z/i);
	cout << "--------------------------------------------------------------------\n\n";
	cout << "El promedio de la coordenada x es: " << promedio.x << "\n";
	cout << "El promedio de la coordenada y es: " << promedio.y << "\n";
	cout << "El promedio de la coordenada z es: " << promedio.z << "\n\n";
	cout << "--------------------------------------------------------------------\n\n";
}

int main(){
	queue<coord> cola;
	coord aux;
	coord *inicio;
	int op;
	int lng;
	bool rep = false;
	int espacio; //recolecta el espacio necesario para el nodo
	
	do{
	cout << "Ingrese una opcion:\n1-Ingresar coordenada\n2-Mostrar coordenadas\n3-Mostrar promedios\n4-Eliminar\n5-Salir\n-->";
	cin >> op;
	
	switch(op){
	case 1:
		agregar(aux);
		cola.push(aux);
		inicio = &cola.front();
		break;
	case 2:
		if(!cola.empty()){
			mostrar(lng,inicio);
			espacio = (lng * 3) * 32;
			cout << "\nEsta cola necesita un total de " <<espacio<< " bits\n";
		}else
			cout << "La cola esta vacía\n";
		break;
	case 3:
		if(!cola.empty()){
		promedio(lng,inicio);
		}else
			cout << "La cola esta vacía\n";
		break;
	case 4:
		if(!cola.empty()){
			cout << "Las coordenadas han sido eliminadas\n";
			cola.pop();
			inicio = &cola.front();	
		} else
			cout << "La cola esta vacía\n";
		break;
	case 5:
		return 0;
	default:
		cout << "Ingrese un valor dentro del rango\n";
	}
	
	lng = cola.size();
	cout << "\nPresione cualquier tecla para continuar...\n";
	cin.get();
	cin.get();
	system("cls");
	}while(true);

}

//El final de la cola diga cuanto espacio estan ocupando todos los nodos, agregar eliminar



