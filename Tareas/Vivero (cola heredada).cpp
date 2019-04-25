//agregar arbol al vivero
//listar arboles
//Buscar arboles
//eliminar arbol
//salir

#include<iostream>
#include<queue>
#include<string.h>
using namespace std;

class Arbol{
	string nomCom;
	string nomCien;
	string fam;
	
public:
	string tipo;
	
	Arbol(){
	}
	
	~Arbol(){
		
	}
	//
	void setnomCom(string x){
		this->nomCom = x;
	}	
	string getnomCom(){ //this->x = INDICA QUE LA VARIABLE ESTA DENTRO DE LA CLASE, EN CASO DE HABER DOS VARIABLES CON EL MISMO NOMBRE ENTRE CLASES, SE EVITA TENER QUE COMPARAR CON LAS DEMAS
		return this->nomCom;
	}
	//
	void setnomCien(string y){
		this->nomCien = y;
	}	
	string getnomCien(){
		return this->nomCien;
	}
	//
	void setFam(string z){
		this->fam = z;
	}	
	string getFam(){
		return this->fam;
	}
};

class ArbolFrutal: public Arbol{
};

class ArbolOrnamental: public Arbol{
};



class Factory: public Arbol{
	
	public:
	//clase base  		
		Arbol* crearArbol(int x){
			switch(x){
				case 1:
					return new ArbolFrutal();
					break;
				case 2:
					return new ArbolOrnamental();
					break;
			}
		}
};


void centerstring(string s){ //codigo obtenido de: https://www.dreamincode.net/forums/topic/13749-center-text-with-cout/
   int l=strlen(s.c_str());
   int pos=(int)((115-l)/2);
   for(int i=0;i<=pos;i++)
    cout<<" ";
   
   cout<<s;
}

bool clear(bool &rep){ //Limpia la variable en caso de que el tipo de dato sea el incorrecto	
	if(cin.fail()) //si al ingresar el dato da error
	{
		rep = true;
		cin.clear(); //limpia la variable para que pueda ser ingresada nuevamente
		cin.ignore();
		cout << "Ingrese un valor valido\n\n";
	}
	else
		rep = false; //el dato no es erroneo
}

void menu(){
	centerstring("----------------------------------------------\n");
	centerstring("Que accion desea realizar:\n");
	centerstring("1-Ingresar un arbol\n");
	centerstring("2-Mostrar listado de arboles\n");
	centerstring("3-Buscar un arbol\n");
	centerstring("4-Eliminar un arbol\n");
	centerstring("5-Salir\n");
	centerstring("----------------------------------------------\n");
	cout << "-->";
}


int main(){
	
Factory *afactory = new Factory(); //Instancia la fabrica
queue<Arbol> cola; //creacion de la cola
Arbol *af; //Creamos el objeto que alamcenara el dato a ingresar a la cola

int opcion; //variable para el menu

int x; //elige que tipo de arbol se ingresa
bool rep = true; //decide si se repite algun ciclo
string comun; //almacena el nombre a ingresar en el objeto
string cientifico; //almacena el nombre a ingresar en el objeto
string familia; //almacena la familia a ingresar en el objeto

Arbol *ptrfront;
Arbol *ptrback;

do{
menu();
cin >> opcion;

switch(opcion) {

	case 1: //agregar arbol
		rep = true;
		do{
		cout << "Que tipo de arbol desea ingresar: (1-Frutal, 2-Ornamental)\n";
		cin >> x;
		
		if(x == 1){
			af = afactory->crearArbol(x); //crea un arbol de tipo frutal	
			af->tipo = "Frutal";
			cout << "Ingrese el nombre comun: "; cin >> comun; 
			cout << "Ingrese el nombre cientifico: "; cin >> cientifico;
			cout << "Ingrese la familia del arbol: "; cin >> familia;		
			break;	
		}
		else if(x == 2){
			af = afactory->crearArbol(x); //crea un arbol de tipo frutal	
			af->tipo = "Ornamental";
			cout << "Ingrese el nombre comun: "; cin >> comun; 
			cout << "Ingrese el nombre cientifico: "; cin >> cientifico;
			cout << "Ingrese la familia del arbol: "; cin >> familia;		
			break;
		}
		else{
			cout << "Ingrese un numero dentro del rango\n";
		}
		
		}while(clear(rep));
		
		af->setnomCom(comun);
		af->setnomCien(cientifico);
		af->setFam(familia);
		
		cola.push(*af);
		
		break;

	case 2: //Mostrar arboles
		if(!cola.empty()){
			ptrfront = &cola.front();
			ptrback = &cola.back();
			while(ptrfront != ptrback){
				cout << ptrfront->tipo << endl;
				cout << ptrfront->getnomCom() << endl;
				cout << ptrfront->getnomCien() << endl;
				cout << ptrfront->getFam() << endl << endl;
				ptrfront++;
			}	
			if(ptrfront == ptrback){
				cout << ptrfront->tipo << endl;
				cout << ptrfront->getnomCom() << endl;
				cout << ptrfront->getnomCien() << endl;
				cout << ptrfront->getFam() << endl << endl;
			}
		} else{
			cout << "La cola esta vacia\n";
		}
		
		break;

	case 3: //buscar un arbol
		
		if(!cola.empty()){
			cout << "Ingrese el nombre comun del arbol: "; cin >> comun;
			ptrfront = &cola.front();
			ptrback = &cola.back();
			while(ptrfront != ptrback){
					if(comun == ptrfront->getnomCom()){
					cout << ptrfront->tipo << endl;
					cout << "Nombre comun: " << ptrfront->getnomCom() << endl;
					cout << "Nombre cientifico: " << ptrfront->getnomCien() << endl;
					cout << "Familia: " << ptrfront->getFam() << endl << endl;
			}
			ptrfront++;}
			if(ptrfront == ptrback){
				if(comun == ptrfront->getnomCom()){
					cout << ptrfront->tipo << endl;
					cout <<  "Nombre comun: " << ptrfront->getnomCom() << endl;
					cout << "Nombre cientifico: " << ptrfront->getnomCien() << endl;
					cout << "Familia: " << ptrfront->getFam() << endl << endl;
			}}
		} else{
			cout << "La cola esta vacia\n";
		}
		
		break;

	case 4: //Eliminar el primero en la cola
		if(!cola.empty()){
			cola.pop();	
		} else{
			cout << "La cola esta vacia\n";
		}
		
		break;				

	case 5:
		return 0;
		
	default:
		cout << "Ingrese un numero dentro del rango \n";
		break;
}//fin del switch

cout << "Presione cualquier tecla para continuar...";
cin.get();cin.get();
system("cls");

}while(true);//fin del while 



return 0;
}


