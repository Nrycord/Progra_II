//hacer una clase que permita almacenar la informacion de los pacientes en un consultorio,
//los datos a almacenar son: Correlativo, Nombre, Apellido, Edad, Sexo, Peso, Enfermedad cronica.
//La clase debe permitir mostrar la info del paciente y pedir la informacion del paciente
//constructor y destructor tambien
//crear dos objetos de la clase paciente

#include<iostream> //ingreso y salida de datos
using namespace std;

class Pacientes{
	// Private section
	struct Nodo{
		int correlativo;
		char nombre[10];
		char apellido[10];
		char sexo;
		char enfcro[20];
		int edad;
		float peso;
		Nodo *sig;
	};
	Nodo *ini;
	
	public:
		Pacientes();
		 ~Pacientes();
		void imprimir();	
		void ingresar();
		int extraer();
};

Pacientes::Pacientes(){
	ini = NULL; //Aqui se puede asignar un valor por defecto para la clase
	//TOMAR RAIZ COMO UN TOPE
}          

Pacientes::~Pacientes(){
	Nodo *reco = ini; //asigna reco a la posicion del tope de la pila
	Nodo *bor; //variable Nodo con la que apuntaremos al dato a borrar en reco
	
	while(reco != NULL){
		bor = reco; //asigna bor a la posicion de reco actual
		reco = reco->sig;//reco retrocede en un espacio en la pila
		delete bor;//borra la direccion que esta apuntando (el dato reco del tope de la pila)
	}
}

void Pacientes::ingresar(){
	Nodo *nuevo; //deja un espacio para un entero y para un nodo
	nuevo = new Nodo(); //alojamos el espacio necesario
	cout << "Ingrese el nombre: "; cin >> nuevo->nombre;	
	cout << "Ingrese el apellido: "; cin >> nuevo->apellido;
	cout << "Ingrese el correlativo: "; cin >> nuevo->correlativo;
	cout << "Ingrese la edad: "; cin >> nuevo->edad;
	cout << "Ingrese el peso: "; cin >> nuevo->peso;
	cout << "Ingrese el sexo (m,f): "; cin >> nuevo->sexo;
	cout << "Ingrese la enfermedad cronica: "; cin >> nuevo->enfcro;
	
	if(ini == NULL){ //si es el primer dato, raiz = NULL
		ini = nuevo; //la raiz ahora apunta al valor de nuevo
		nuevo->sig = NULL; //Deja el siguiente valor de nuevo como NULL
	}
	else{
		nuevo->sig = ini; //El valor del tope ahora apunta a el espacio en nodo
		//el dato sig de nuevo se le asigna la direccion de raiz,
		ini = nuevo;
	}
}

void Pacientes::imprimir(){
	Nodo *reco = ini;
	cout << "Lista de datos almacenados en la pila: \n";
	while(reco != NULL){
		cout << "Nombre: " << reco->nombre << endl;	
		cout << "Apellido: " <<  reco->apellido << endl;
		cout << "Correlativo: " << reco->correlativo << endl;
		cout << "Edad: " << reco->edad << endl;
		cout << "Peso: " << reco->peso << endl;
		cout << "Sexo (m,f): " << reco->sexo << endl;
		cout << "Enfermedad cronica: " << reco->enfcro << endl << endl;
		reco = reco->sig;
	}
	cout << "\n";
}

int Pacientes::extraer(){
	if(ini != NULL){
		Nodo *bor = ini; //almacena la direccion del tope actual
		ini = ini->sig; //reduce el tope en un "Nodo" (un espacio o cadena del nodo)
		delete bor;//borra los datos de el tope, elimina la direccion de memoria a la que apunta
			}
	else{
		return -1;
	}
}

int main(){
	Pacientes *paciente;
	paciente = new Pacientes();
	int op;
	
	do{	
		cout << "Que opcion desea realizar:\n1-Ingresar paciente.\n2-Mostrar lista de pacientes.\n3-Eliminar paciente\n4-Salir\n";
		cin >> op;
		
		switch(op) {
		case 1:
			paciente->ingresar();
			break;
		case 2:
			paciente->imprimir();
			break;
		case 3:
			paciente->extraer();//destruye la pila
			break;
		case 4:
			return 0;
		
		
		}
	cout << "Presione enter para continuar...\n";	
	cin.get(); cin.get();
	system("cls");	
	}while(true);
	
	cin.get();
	return 0;
}
