#include<iostream>
#include<queue>
using namespace std;

/*void encolar (struct cola &q, int valor){
	struct *nodo
}
*/
int main(){
	queue<char> cola;
	char *ptrfront;
	char *ptrback;
	
	for(int i='A';i<='Z';i++)
		cola.push(i); //no es mecesario poner corchetes porque solo es una linea de codigo
	
	ptrfront = &cola.front();
	ptrback = &cola.back();
	
	for(int i='A';i<='Z';i++){
		cout << *ptrfront << "\t"; //imprime los valores de forma descendente
		cout << *ptrback << endl; //imprime los valores de forma ascendente
		ptrfront++;
		ptrback--;
	}
	
	
	/*while(!cola.empty())
	{
		cout << cola.front() << " "; //imprime el tope de la cola (el que lleva mas tiempo en ella)
		cout << cola.back() << "\n"; //imprime el final de la cola (el que fue ingresado de ultimo)
		cola.pop();
	}*/
	
	cin.get();
	return 0;
}


